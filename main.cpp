#include "Game.h"
#include "Time.h"

Game* game = nullptr;

int main(int args, char* argv[]) {
	//These are used to calculate deltaTime
	Uint64 NOW = SDL_GetPerformanceCounter();			//The time at the beginning of the frame
	Uint64 LAST = 0;									//The time at the end of the frame
	double deltaTime = 0;								//The time between frames
	double timeElapsed = 0;								//The time elapsed since the game began

	game = new Game("SDL Platformer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);	//Initialise the game
	game->Initialise();
	while (game->Running()) {			//While the game is running
		LAST = NOW;
		game->HandleEvents();			//Check for events (input)
		game->Update();					//Update the game
		game->Render();					//Render the game

		NOW = SDL_GetPerformanceCounter();

		//Calculate delta time and output the total time elapsed
		deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());
		Time::SetDeltaTime(deltaTime);

		//std::cout << "FPS: " << (1.0f / deltaTime) << '\n';
	}
	//Clean the game if it's not running
	game->Clean();

	return 0;
}