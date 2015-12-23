// Works with game FPS

class FPSController{
	
	int limit;	// Limit of the frames per second
	int count;	// Amount of framas in the current second
	time_t timeMark; // Time marker
	time_t second;
	
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
	timeMark = NULL;
	count = 0;
}


// Start the time marker
void FPSController::Start()
{
	time(&timeMark);
}

// Check FPS - if over the framas limt, don't update until the next second
void FPSController::CheckFPS()
{
	count++;
	if(count >= limit)
}


