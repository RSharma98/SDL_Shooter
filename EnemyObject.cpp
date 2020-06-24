#include "EnemyObject.h"
#include <iostream>

EnemyObject::EnemyObject(Vector2 position, Vector2 size) : CharacterObject(position, size) {
	m_IdleAnimation = m_WalkAnimation = nullptr;
	m_IdleTextures = m_WalkTextures = std::vector<Texture*>();
	m_MoveSpeed = 0.0f;

	for (int i = 0; i < 13; i++) {
		if (i < 8) {
			m_IdleTextures.push_back(new Texture("Assets/Skeleton/Skeleton Idle.png", Vector2(12 + (24 * i), 16), Vector2(24, 32)));
		}

		m_WalkTextures.push_back(new Texture("Assets/Skeleton/Skeleton Walk.png", Vector2(12 + (24 * i), 16), Vector2(24, 32)));
	}
	m_IdleAnimation = new Animation("Idle", m_IdleTextures, 0.1f);
	m_WalkAnimation = new Animation("Walk", m_WalkTextures, 0.1f);

	m_Animator->AddAnimation(m_IdleAnimation);
	m_Animator->AddAnimation(m_WalkAnimation);
	m_Animator->SetAnimation("Idle");
}

EnemyObject::~EnemyObject() {
	m_IdleAnimation = nullptr;
	m_WalkAnimation = nullptr;
}

void EnemyObject::Update(Vector2 playerPos) {
	Vector2 dir = playerPos - m_Pos;
	dir.Normalise();
	//std::cout << "Normalised vector: " << dir << '\n';

	m_Velocity = dir * m_MoveSpeed;

	CharacterObject::Update();
}