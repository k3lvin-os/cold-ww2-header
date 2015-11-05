
#define PACKET_MAX_SIZE 1500
#define TIMEOUT 5000
#define LOCALHOST "127.0.0.1"


// Estrutura com dados relativos a conexão
struct Rede{
	
	// Propriedades
	char* clienteOuServidor; // Identifica tipo de elemento da rede
	WSADATA wsaData;		// Biblioteca para conexão em rede
    SOCKET ListenSocket; 	// Socket para o servidor
	SOCKET ConnectSocket;  // Socket para o cliente
	
	SOCKET AcceptSocket;   // Socket para envio de mensagens 
							//(servidor utiliza-o)
							
	SOCKADDR_IN addrClient;// Endereço do cliente
	sockaddr_in addrServer;// Endereço do servidor
	DWORD timeout;			// timeout
	char recvBuf[PACKET_MAX_SIZE]; // Pacote
	
	
	// Flags
	bool servidorAberto;
	bool clienteConectado;
	bool clienteOk;
	bool servOk;

	// Funções
	void FlagsInit();
	bool ServerInit();
	bool ClientInit();
	bool RecebeDoClient();
	bool EnviaParaOClient(char pacote[PACKET_MAX_SIZE]);
	bool EnviaParaOServer(char pacote[PACKET_MAX_SIZE]);
	void RecebeDoServer();
	bool AceitaConexaoClient();
	bool ConectaServer();
	bool FechaConexaoClient();
	void FechaSocketClient();
	void FechaSocketServer();

};

// Inicializa as flags
void Rede::FlagsInit(){
	servidorAberto = false;
	clienteConectado = false;
	clienteOk = false;
	servOk = false;
}



// Envia um pacote para o server
bool Rede::EnviaParaOServer(char pacote[PACKET_MAX_SIZE]){
	
	int enviei;
	enviei = send(ConnectSocket ,pacote,strlen(pacote),0);
	
	if(enviei != SOCKET_ERROR)
		return true;
	else
		return false;
}


// Envia um pacote para o client
bool Rede::EnviaParaOClient(char pacote[PACKET_MAX_SIZE]){
	
	int enviou;
	
	enviou = send(AcceptSocket,pacote,strlen(pacote),0);
	
	if(enviou != SOCKET_ERROR)
		return true;
	else
		return false;
}


// Conecta-se ao servidor
bool Rede::ConectaServer(){
	int iResult = connect( ConnectSocket, (SOCKADDR*) &addrServer, sizeof(addrServer) );
    if ( iResult == SOCKET_ERROR) {
        closesocket (ConnectSocket);
        printf("Não foi possível se conectar ao servidor. Erro: %ld\n", WSAGetLastError());
        WSACleanup();
        return false;
    }
}


// Inicializa o cliente
bool Rede::ClientInit(){
	//----------------------
    // Inicializa Winsock.
    int iResult;
    
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	
    if (iResult != NO_ERROR) {
        wprintf(L"WSAStartup failed with error: %ld\n", iResult);
        return 1;
    }
    
    //----------------------
    // Cria um socket para conectar-se ao servidor
    ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ConnectSocket == INVALID_SOCKET) {
        wprintf(L"socket failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    
    //----------------------
    // A estrutura sockaddr_in  especifica o endereço da familia,
    // o endereço IP, e a porta que o socket está se conectando
    addrServer.sin_family = AF_INET;
    addrServer.sin_addr.s_addr = inet_addr( LOCALHOST );
    addrServer.sin_port = htons(20131);   
	
	

    return true;   
}

//=========================================================
// Aceite o pedido de conexão e retorna uma nova conexão de soquete
// (tradução do japonês do Autor)
bool Rede::AceitaConexaoClient(){
	
	int len= sizeof(SOCKADDR);
	AcceptSocket=accept(ListenSocket,(SOCKADDR*)&addrClient,&len);
	
	if(AcceptSocket  == INVALID_SOCKET)
		return false;
	else
		return true;
}


//================================================
//Fecha o socket para comunicacao com o client
bool Rede::FechaConexaoClient(){

	closesocket(AcceptSocket);
}


//========================================================
// Configuração Inicial do Servidor
bool Rede::ServerInit(){
	//----------------------
    // Inicializa Winsock.
    int iResult;
    
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	
    if (iResult != NO_ERROR) {
        wprintf(L"WSAStartup failed with error: %ld\n", iResult);
        return 1;
    }
    //----------------------
    // Cria um socket para ouvir
    // possíveis requisições de conexões
    ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ListenSocket == INVALID_SOCKET) {
        wprintf(L"socket failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    //----------------------
    // A estrutura sockaddr_in especifica a familía de endereços
    // o endereço IP, e a porta aonde o socket está sendo utilizado
    addrServer.sin_family = AF_INET;
    addrServer.sin_addr.s_addr = htonl(INADDR_ANY); 
    addrServer.sin_port = htons(20131);


	// Vincula o socket
    if (bind(ListenSocket,(SOCKADDR *) & addrServer, sizeof (addrServer)) == SOCKET_ERROR) {
        wprintf(L"bind failed with error: %ld\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    
	// Configura o timeout de envio de mensagens
	timeout = TIMEOUT;
    setsockopt(ListenSocket, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));
  

	//----------------------
    // Fica escutando possíveis requsições de conexão
    // no socket criado
    if (listen(ListenSocket, 1) == SOCKET_ERROR) {
        wprintf(L"listen failed with error: %ld\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
	
	
	servidorAberto = true;	
}

//===================================================
// Recebe dados do cliente
bool Rede::RecebeDoClient(){

	int bytesRecebi =recv(AcceptSocket ,recvBuf,PACKET_MAX_SIZE,0);
	
	recvBuf[bytesRecebi] = '\0';
	
	if(bytesRecebi != 0 && bytesRecebi != SOCKET_ERROR)
		return true;
	else
		return false;
}

//====================================================
// Fecha o socket do cliente
void Rede::FechaSocketClient(){
	closesocket(ConnectSocket);
	WSACleanup();
}

//===================================================
// Fecha o socket do server
void Rede::FechaSocketServer(){
	closesocket(ListenSocket);
	WSACleanup();
}
