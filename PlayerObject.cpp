#include "PlayerObject.h"

PlayerObject::PlayerObject(Vector2 position, Vector2 size) : CharacterObject(position, size) {
	m_IdleAnimation = m_RunAnimation = nullptr;
	m_IdleTextures = m_RunTextures = std::vector<Texture*>();

	m_MoveSpeed = 5.0f;
	m_DirLastFrame = Vector2();

	for (int i = 0; i < 13; i++) {
		if (i < 8) {
			m_RunTextures.push_back(new Texture("Assets/Adventurer Sprite Sheet v1.1.png", Vector2(16 + (32 * i), 48), Vector2(32, 32)));
		}
		m_IdleTextures.push_back(new Texture("Assets/Adventurer Sprite Sheet v1.1.png", Vector2(16 + (32 * i), 16), Vector2(32, 32)));
	}
	m_IdleAnimation = new Animation("Idle", m_IdleTextures, 0.1f);
	m_RunAnimation = new Animation("Run", m_RunTextures, 0.1f);

	m_Animator->AddAnimation(m_IdleAnimation);
	m_Animator->AddAnimation(m_RunAnimation);
	m_Animator->SetAnimation("Idle");
}

PlayerObject::~PlayerObject(){
}

void PlayerObject::Update() {
	Vector2 dir = Vector2(0, 0);	//A vector2 to store direction based on input

	//X axis input
	if (Input::GetKey(Input::KeyCode::A) || Input::GetKey(Input::KeyCode::LeftArrow)) dir.x = -1;
	else if (Input::GetKey(Input::KeyCode::D) || Input::GetKey(Input::KeyCode::RightArrow)) dir.x = 1;

	//Y axis input
	if (Input::GetKey(Input::KeyCode::S) || Input::GetKey(Input::KeyCode::DownArrow)) dir.y = -1;
	else if (Input::GetKey(Input::KeyCode::W) || Input::GetKey(Input::KeyCode::UpArrow)) dir.y = 1;

	if (dir.x == 0 || dir.y == 0) {
		m_Velocity = dir * m_MoveSpeed;
	}
	else {
		if (dir != m_DirLastFrame) {
			if (dir.x != 0 && m_DirLastFrame.x == 0) {
				m_Velocity = Vector2(m_MoveSpeed * dir.x, 0);
			}
			else if (dir.y != 0 && m_DirLastFrame.y == 0) {
				m_Velocity = Vector2(0, m_MoveSpeed * dir.y);
			}
		}
	}

	m_DirLastFrame = dir;

	if (dir.x != 0 || dir.y != 0) m_Animator->SetAnimation("Run");
	else m_Animator->SetAnimation("Idle");

	CharacterObject::Update();
}