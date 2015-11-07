
#define PACKET_MAX_SIZE 1500
#define TIMEOUT 5000


// Estrutura com dados relativos a conex�o
struct Rede{
	
	// Propriedades
	char* clienteOuServidor; // Identifica tipo de elemento da rede
	char* ipServer;
	int portaServ;
	WSADATA wsaData;		// Biblioteca para conex�o em rede
    SOCKET ListenSocket; 	// Socket para o servidor
	SOCKET ConnectSocket;  // Socket para o cliente
	
	SOCKET AcceptSocket;   // Socket para envio de mensagens 
							//(servidor utiliza-o)
							
	SOCKADDR_IN addrClient;// Endere�o do cliente
	sockaddr_in addrServer;// Endere�o do servidor
	DWORD timeout;			// timeout
	char recvBuf[PACKET_MAX_SIZE]; // Pacote
	
	
	// Flags
	bool servidorInit;
	bool clienteConectado;
	bool clienteOk;
	bool servOk;

	// Fun��es
	bool WinSockInit();
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

// Inicializa a biblioteca para conex�o em rede
bool Rede::WinSockInit(){
    int iResult;
    
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	
    if (iResult != NO_ERROR) {
        wprintf(L"WSAStartup failed with error: %ld\n", iResult);
        return false;
    }
    return true;
}

// Inicializa as flags
void Rede::FlagsInit(){
	servidorInit = false;
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
        printf("N�o foi poss�vel se conectar ao servidor. Erro: %ld\n", WSAGetLastError());
        WSACleanup();
        return false;
    }
}


// Inicializa o cliente
bool Rede::ClientInit(){
    //----------------------
    // Cria um socket para conectar-se ao servidor
    ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ConnectSocket == INVALID_SOCKET) {
        wprintf(L"socket failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    
    //----------------------
    // A estrutura sockaddr_in  especifica o endere�o da familia,
    // o endere�o IP, e a porta que o socket est� se conectando
    addrServer.sin_family = AF_INET;
    addrServer.sin_addr.s_addr = inet_addr( ipServer );
    addrServer.sin_port = htons(portaServ);   
	
	

    return true;   
}

//=========================================================
// Aceite o pedido de conex�o e retorna uma nova conex�o de soquete
// (tradu��o do japon�s do Autor)
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
// Configura��o Inicial do Servidor
bool Rede::ServerInit(){
    //----------------------
    // Cria um socket para ouvir
    // poss�veis requisi��es de conex�es
    ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ListenSocket == INVALID_SOCKET) {
        wprintf(L"socket failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    //----------------------
    // A estrutura sockaddr_in especifica a famil�a de endere�os
    // o endere�o IP, e a porta aonde o socket est� sendo utilizado
    addrServer.sin_family = AF_INET;
    addrServer.sin_addr.s_addr = htonl(INADDR_ANY); 
    addrServer.sin_port = htons(portaServ);


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
    // Fica escutando poss�veis requsi��es de conex�o
    // no socket criado
    if (listen(ListenSocket, 1) == SOCKET_ERROR) {
        wprintf(L"listen failed with error: %ld\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
	
	
	servidorInit = true;	
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
}

//===================================================
// Fecha o socket do server
void Rede::FechaSocketServer(){
	closesocket(ListenSocket);
}
