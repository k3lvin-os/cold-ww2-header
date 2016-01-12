
// Map the keys of the keyboard
class KeyMap
{
	public:
	static const int TXT_AMOUNT_KEY = 46;
	static const int TXT_TOTAL_NUMBER = TXT_AMOUNT_KEY;
	
	private:
		char *_name[TXT_TOTAL_NUMBER];
		int _value[TXT_TOTAL_NUMBER];
		void LoadKeys(char *txtKeyMap);
	public:
		//Constructor
		KeyMap(char* txtKeyMap);
		char* name(int i) { return _name[i] ;};
		int value(int i) {return _value[i] ;};
		void ShowKeys();
};

		
		

		

// Show the keys and the corresponding _values on console
void KeyMap::ShowKeys()
{
	int i;
	for(i = 0; i < TXT_AMOUNT_KEY;i++)
	{
		std::cout << _name[i] << " = " << _value[i] << std::endl;
	}
}

// Constructor that needs a .txt with a propoer key mapping
KeyMap::KeyMap(char* txtKeyMap)
{
	LoadKeys(txtKeyMap);
	
}

// Load the keys _name and _values from .txt file
void KeyMap::LoadKeys(char* txtKeyMap)
{
	std::ifstream reader;
	bool readingValue = false;
	char buffer[20], temp[2], c;
	int i;
	
	reader.open(txtKeyMap);
	if(!reader.is_open())
	{
		std::cout << "\ncould not open " << txtKeyMap << "\n";
	}
	else
	{
		strcpy(buffer,"");
		i = 0;
		
		while(reader.get(c))
		{
			
			if(c != '\n' && c!= '\0' && c != ' ')
			{
				temp[0] = c;
				temp[1] = '\0';
				strcat(buffer,temp);
			}
			else if(c != '\0')
			{
				if(readingValue)
				{
					sscanf(buffer, "%x", &_value[i]);
					readingValue = false;
					i++;

				}
				else
				{
					_name[i] = (char*) malloc(sizeof(buffer) / sizeof(buffer[0]) );
					strcpy(_name[i], buffer);
					readingValue = true;				
				}
				
				strcpy(buffer,"");

			}
		}
	}
	reader.close();
}


