	
// Radiobutton single component (similar to the used on Web)
struct Radio{

	int x,y;
	bool checked;
	char *label;
	Radio(char *label, bool checked, int myX, int myY);
};
	
// Radio constructor
Radio::Radio(char *label1, bool checked1, int myX, int myY){
	x = myX;
	y = myY;
	checked = checked1;
	label = label1;
}

