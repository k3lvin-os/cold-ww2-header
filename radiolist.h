// Radiobutton set (similar to the used on Web)
struct RadioList
{	
	// Proprieties	
	static const int RADIUS = 10;
	std::vector<Radio> list;
	
	// Methods
	void CheckRadio(Radio *pRadio);	
	Radio* RadioChecked();
	RadioList();
	RadioList(std::vector<Radio> list);
	ShowList();
	void CheckClick();
	
};

// Construtor without paramters
RadioList::RadioList()
{
	
}

// Constructor that receives Radio's in one vector
RadioList::RadioList(std::vector<Radio> list)
{
	this->list = list;
}

// Turn On the selected radio and Turn Off the other that is setted
void RadioList::CheckRadio(Radio *pRadio)
{	
	int i;
	Radio *current;

	if(pRadio->checked == false)
	{
		current = RadioChecked();
		if(current != NULL)
		{
			current->checked = false;
		}
				
		pRadio->checked = true;
	}
		
}

	
// Check for possible clicks in the radiobuttons list
void RadioList::CheckClick()
{
	
	int mouseX, mouseY, i;
	double distRaidus, tempX, tempY;
	
	if(GetKeyState(VK_LBUTTON) & 0x80)
	{
		mouseX = mousex();
		mouseY = mousey();
		
		for(i = 0; i < list.size(); i++)
		{
			tempX = pow(list[i].x - mouseX, 2.0);
			tempY = pow(list[i].y - mouseY,2.0);
			distRaidus = sqrt(tempX + tempY);
			
			if(distRaidus <= RADIUS)
			{
				CheckRadio(&list[i]);
			}
		}
			
	}
	
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




//Show the list of radiobuttons
RadioList::ShowList()
{
	int i;
	setcolor(LIGHTGREEN);
	setfillstyle(1,LIGHTGREEN);
	
	for(i = 0; i < list.size(); i++)
	{
		outtextxy(list[i].x + 15, list[i].y + 5, list[i].label);
		if(list[i].checked == false)
			circle(list[i].x,list[i].y,RADIUS);
		else
			fillellipse(list[i].x,list[i].y,RADIUS,RADIUS);
	}
}
	




