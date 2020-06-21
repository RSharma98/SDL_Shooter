#include "Game.h"
int frames;

int Game::Width = 0;
int Game::Height = 0;
SDL_Renderer* Game::renderer = nullptr;

Game::Game(const char* title, int xPos, int yPos, int width, int height, bool fullscreen) {
	Game::Width = width;
	Game::Height = height;
	input = new Input();
	std::cout << Game::Width << ", " << Game::Height << '\n';
	camera = new Camera(5);
	std::cout << camera->position.x << ", " << camera->position.y << '\n';
	renderer = nullptr;
	window = nullptr;
	frames = 0;
	player = new PlayerObject();
	enemy = new EnemyObject();
	int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;
	renderManager = new RenderManager();
	isRunning = false;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if (window) std::cout << "Window created.\n";

		Game::renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) std::cout << "Renderer created.\n";
		isRunning = true;

		//SDL_Rect view = { 0, 0, 320, 180 };
		//SDL_RenderSetViewport(renderer, &view);
	}
}

Game::~Game() {

}

void Game::Initialise() {
	player->Initialise(Vector2(0, 0), Vector2(1, 1));
	enemy->Initialise(Vector2(0, 0), Vector2(1, 1.25f));
}

void Game::Update() {
	player->Update();
	enemy->Update(player->GetPos());
}

//This function handles keyboard movement (moving the player and quitting)
void Game::HandleEvents() {
	input->BeginInput();	//Begin input detection
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) isRunning = false;

		//Store all the keys pressed this frame
		if (event.type == SDL_KEYDOWN) input->AddKeyPressed(event.key.keysym.sym);

		//Store the keys released this frame
		if (event.type == SDL_KEYUP) input->AddKeyReleased(event.key.keysym.sym);

		if (event.type == SDL_MOUSEBUTTONDOWN) input->AddMouseButton(event.button.button);

		if (event.type == SDL_MOUSEBUTTONUP) input->RemoveMouseButton(event.button.button);
	}

	int mouseX = 0, mouseY = 0;
	SDL_GetMouseState(&mouseX, &mouseY);
	input->SetMousePosition(Vector2(mouseX, mouseY));

	if (input->GetKeyUp(Input::KeyCode::Escape)) isRunning = false;
}

void Game::Render() {
	SDL_SetRenderDrawColor(renderer, 15, 15, 15, 255);	//Set the background colour
	SDL_RenderClear(renderer);							//Clear the render view

	//Add stuff to render here
	renderManager->Render(renderer);
	
	player->GetBox()->Render(renderer, SDL_Color{ 0, 255, 0, 255 });
	camera->Render(renderer);

	SDL_RenderPresent(renderer);						//Render the frame
}

//This function is called when the game exits
void Game::Clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	delete camera;

	std::cout << "Game cleaned.\n";
}