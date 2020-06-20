#include "PlayerObject.h"
#include <iostream>
#include "MathHelper.h"
#include "Time.h"

PlayerObject::PlayerObject() {
	m_MoveSpeed = 5.0f;
	m_Animator = nullptr;
	m_IdleAnimation = m_RunAnimation = nullptr;
	m_IdleTextures = m_RunTextures = std::vector<Texture*>();
}

PlayerObject::~PlayerObject(){
	std::cout << "Clear player\n";
	for (int i = 0; i < m_IdleTextures.size(); i++) delete m_IdleTextures[i];
	for (int i = 0; i < m_RunTextures.size(); i++) delete m_RunTextures[i];
	m_IdleTextures.clear();
	m_RunTextures.clear();
}

void PlayerObject::Initialise(SDL_Renderer* renderer, Vector2 position, Vector2 size) {
	m_Animator = new Animator();
	for (int i = 0; i < 13; i++) {
		if (i < 8) {
			m_RunTextures.push_back(new Texture());
			m_RunTextures.at(i)->Initialise("Assets/Adventurer Sprite Sheet v1.1.png", Vector2(16 + (32 * i), 48), Vector2(32, 32));
		}
		m_IdleTextures.push_back(new Texture());
		m_IdleTextures.at(i)->Initialise("Assets/Adventurer Sprite Sheet v1.1.png", Vector2(16 + (32 * i), 16), Vector2(32, 32));
	}
	m_IdleAnimation = new Animation("Idle", m_IdleTextures, 0.1f);
	m_RunAnimation = new Animation("Run", m_RunTextures, 0.1f);

	m_Animator->AddAnimation(m_IdleAnimation);
	m_Animator->AddAnimation(m_RunAnimation);
	m_Animator->SetAnimation("Idle");
	
	GameObject::Initialise(renderer, position, size);
	box.Initialise(position, Vector2(0, 0), size);
}

void PlayerObject::Update() {
	m_Animator->Update();

	Vector2 dir = Vector2(0, 0);	//A vector2 to store direction based on input

	//X axis input
	if (Input::GetKey(Input::KeyCode::A) || Input::GetKey(Input::KeyCode::LeftArrow)) dir.x = -1;
	else if (Input::GetKey(Input::KeyCode::D) || Input::GetKey(Input::KeyCode::RightArrow)) dir.x = 1;

	//Y axis input
	if (Input::GetKey(Input::KeyCode::S) || Input::GetKey(Input::KeyCode::DownArrow)) dir.y = -1;
	else if (Input::GetKey(Input::KeyCode::W) || Input::GetKey(Input::KeyCode::UpArrow)) dir.y = 1;

	if (dir.x != 0) spriteRenderer->flipX = (dir.x > 0) ? false : true;

	if (dir.x != 0 || dir.y != 0) m_Animator->SetAnimation("Run");
	else m_Animator->SetAnimation("Idle");
	spriteRenderer->SetTexture(m_Animator->GetAnimation()->GetTexture());

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

