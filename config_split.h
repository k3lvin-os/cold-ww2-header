
// Useful class for splitscreen controls config
class ConfigSplitscreen
{
	public:
		void SetDefaultControls();

};

// Set default controls for the splitscreen game
void ConfigSplitscreen::SetDefaultControls()
{
	std::ofstream write;
	write.open("txt/config_split.txt");
	if(!write.is_open()){
		std::cout << "Could not open config_split.txt";
	}
	
	write.close();

}
