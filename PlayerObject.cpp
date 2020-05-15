#include "PlayerObject.h"
#include <iostream>
#include "MathHelper.h"

PlayerObject::PlayerObject() {

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
	box.position = m_Pos;
	GameObject::Update();
	box.Update();
}

void PlayerObject::Render(SDL_Renderer* renderer) {
	GameObject::Render(renderer);
	box.Render(renderer, SDL_Color{ 0, 255, 0, 255 });
}

void PlayerObject::MoveHorizontal(float speed, BoxCollider2D enemy) {
	/*box.position = Camera::Instance->WorldToScreenUnits(Vector2(m_Pos.x + speed, m_Pos.y));
	if (!box.IsColliding(enemy)) m_Pos.x += speed;
	Update();*/

	float startPos = m_Pos.x;
	float targetPos = m_Pos.x + speed;
	//std::cout << "Unit Difference: " << (targetPos - startPos) << '\n';
	//std::cout << "Pixel Difference: " << ((Camera::Instance->WorldToScreenUnits(m_Pos).x + (speed * Camera::Instance->GetUnitSize())) - Camera::Instance->WorldToScreenUnits(m_Pos).x) << '\n';
	float t = 0;
	while (t < 1.0f) {
		//Once you implement the uniform grid you'll need to update actor position on it before checking for collision
		if (box.IsColliding(enemy)) {
			std::cout << m_Pos.x;
			//m_Pos.x = enemy.GetBottomRight().x + enemy.offset.x - enemy.size.x;
			std::cout << '\t' << m_Pos.x << '\n';
			break;
		}
		m_Pos.x = MathHelper::Lerp(startPos, targetPos, t);
		Update();
		t += 0.01f;
	}
}

void PlayerObject::SetPosition(Vector2 position) { 
	m_Pos = position; 
	Update();
}

void PlayerObject::Fall(float speed) {
	m_Pos.y -= speed;
	Update();
}

