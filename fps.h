// Works with game FPS

class FPSController{
	
	int limit;	// Limit of the frames per second
	int count;	// Amount of framas in the current second
	time_t second; // Current second register
	
	bool NextSecond();
	
	public:
	
		FPSController(int limit);
		void Start();
		void CheckFPS();
		
};

// Constructor
FPSController::FPSController(int limit)
{
	this->limit = limit;
	count = 0;
}


// Start the time marker
void FPSController::Start()
{
	time(&second);
	count = 0;
}

// Check FPS - if over the framas limt, don't update until the next second
void FPSController::CheckFPS()
{
	time_t now;
	time(&now);
	
	if(now != second)
	{
		time(&second);
		count = 0;
	}
	
	if(count < limit){
		count++;
	}
	else{
		do{
			time(&now);
		} while(now == second);
	}
	
}


