#include "PlayerObject.h"
#include <iostream>
#include "MathHelper.h"
#include "Time.h"

PlayerObject::PlayerObject() {
	m_MoveSpeed = 5.0f;
}

PlayerObject::~PlayerObject(){

}

void PlayerObject::Initialise(SDL_Renderer* renderer, Vector2 position, Vector2 size) {
	spritePath = "Assets/Adventurer Sprite Sheet v1.1.png";
	sourceRect = SDL_Rect{ 0, 0, 32, 32 };
	GameObject::Initialise(renderer, position, size);
	box.Initialise(position, Vector2(0, 0), size);
}

void PlayerObject::Update() {
	Vector2 dir = Vector2(0, 0);	//A vector2 to store direction based on input

	//X axis input
	if (Input::GetKey(Input::KeyCode::A) || Input::GetKey(Input::KeyCode::LeftArrow)) dir.x = -1;
	else if (Input::GetKey(Input::KeyCode::D) || Input::GetKey(Input::KeyCode::RightArrow)) dir.x = 1;

	//Y axis input
	if (Input::GetKey(Input::KeyCode::S) || Input::GetKey(Input::KeyCode::DownArrow)) dir.y = -1;
	else if (Input::GetKey(Input::KeyCode::W) || Input::GetKey(Input::KeyCode::UpArrow)) dir.y = 1;

	//Modify the position
	m_Pos += dir * m_MoveSpeed * Time::GetDeltaTime();

	box.position = m_Pos;
	GameObject::Update();
	box.Update();
}

void PlayerObject::Render(SDL_Renderer* renderer) {
	GameObject::Render(renderer);
	box.Render(renderer, SDL_Color{ 0, 255, 0, 255 });
}

void PlayerObject::SetPosition(Vector2 position) { 
	m_Pos = position; 
	Update();
}

void PlayerObject::Fall(float speed) {
	m_Pos.y -= speed;
	Update();
}

