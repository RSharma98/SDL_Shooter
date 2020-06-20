#include "GameObject.h"
#include <iostream>

GameObject::GameObject() {
	spriteRenderer = new SpriteRenderer();
}

GameObject::~GameObject() {

}

//This function intialises the object by rendering a sprite based on the specified values
void GameObject::Initialise(SDL_Renderer* renderer, Vector2 position, Vector2 size) {
	spriteRenderer = new SpriteRenderer();
	m_Pos = position;
	m_Size = size;
}

//Update moves the sprite as needed
void GameObject::Update() {
	RenderManager::Instance->AddToRenderQueue(spriteRenderer, m_Pos, m_Size);
	//Todo, update sprite renderer values based on object's transform
}

//This function renders the sprite (obviously)
void GameObject::Render(SDL_Renderer *renderer) {
	//spriteRenderer->Render(renderer);
}

//This function generates a random number between zero and max
int GameObject::Random(int max){
	static bool first = true;
	if (first)
	{
		srand(time(NULL)); //seeding for the first time only!
		first = false;
	}
	return rand() % (max + 1);
}