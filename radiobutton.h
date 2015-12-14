	
// Radiobutton single component (similar to the used on Web)
class Radio{
	
	private:	
		static const int RADIUS = 10;
		int x,y;
		bool checked;
		char *label;
	
	public:
		Radio(char *label, bool checked, int myX, int myY);
};
	
// Radio constructor
Radio::Radio(char *label1, bool checked1, int myX, int myY){
	x = myX;
	y = myY;
	checked = checked1;
	label = label1;
}



	
/*
	
	//Show the list of radiobuttons
	void Radio::ShowList(Radio *radio0){
		Radio *pRadio = NULL;
		
		setcolor(LIGHTGREEN);
		setfillstyle(1,LIGHTGREEN);
	
		for(pRadio = radio0->next; pRadio != NULL; pRadio = pRadio->next){
			
			outtextxy(pRadio->x + 15, pRadio->y + 5, pRadio->label);
			if(pRadio->checked == false)
				circle(pRadio->x,pRadio->y,RADIUS);
			else
				fillellipse(pRadio->x,pRadio->y,RADIUS,RADIUS);
		}
	}
	
	
	// Check for possible clicks in the radiobuttons list
	void Radio::CheckClick(Radio *radio0){
		
		Radio *pRadio = NULL;
		int mouseX,mouseY;
		double tempX, tempY, distRadius;
		bool checkRadio = false;
	
		if(GetKeyState(VK_LBUTTON) & 0x80){
			
			mouseX = mousex();
			mouseY = mousey();
			for(pRadio = radio0->next; pRadio != NULL; pRadio = pRadio->next){
				
				tempX = pow(pRadio->x - mouseX,2.0);
				tempY = pow(pRadio->y - mouseY,2.0);
				distRadius = sqrt(tempX + tempY);
				
				if(distRadius <= RADIUS){
					pRadio->CheckRadio(radio0);		
				}
			}
		}
	}
*/

