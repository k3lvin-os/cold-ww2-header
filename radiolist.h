// Radiobutton set (similar to the used on Web)
class RadioList
{	
	private:
		std::vector<Radio> list;
		
	public:
		Radio* RadioChecked();
		bool CheckRadio(char* label);
}

// Returns the radio that was selected
Radio* RadioList::RadioChecked()
{
	int i;
	Radio *pRadio = NULL;
	for(i = 0; i < list.size(); i++)
	{
		if(list[i].checked == true )
		{
			pRadio = &list[i];
			break;
		}					
	}
	
	return pRadio;
}

// Turn On the selected radio and Turn Off the other that is setted
bool Radio::CheckRadio(char* label)
{	
	int i;
	Radio *pRadio = NULL;
	Radio *currentCheck = NULL;
	
	for(i = 0; i < list.size(); i++)
	{
		if(list[i].label == label)
		{
			break;
		}
		
	}
	
	if(pRadio != NULL)
	{

		currentChecked = RadioChecked();
		if(currentChecked != pRadio)
		{
			currentChecked->checked = false;
			pRadio->checked = true;
		}
		
		
		return true;
	} else
	{
		return false;
	}
	
	
	
	
}



/*
// Turn On the selected radio and Turn Off the others
	void Radio::CheckRadio(Radio *radio0){
		
		Radio *pRadio = NULL;
		for(pRadio = radio0->next; pRadio != NULL; pRadio = pRadio->next ){
			pRadio->checked = false;	
		}
		this->checked = true;
	}
*/	
