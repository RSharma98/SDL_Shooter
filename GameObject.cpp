#include "GameObject.h"
#include <iostream>

GameObject::GameObject(Vector2 position, Vector2 size) {
	spriteRenderer = new SpriteRenderer();
	m_Pos = position;
	m_Size = size;
}

GameObject::~GameObject() {
	RenderManager::Instance->RemoveFromRenderQueue(spriteRenderer);

	delete spriteRenderer;
	spriteRenderer = nullptr;
}

//Update moves the sprite as needed
void GameObject::Update() {
	RenderManager::Instance->AddToRenderQueue(spriteRenderer, m_Pos, m_Size);
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