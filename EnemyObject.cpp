#include "EnemyObject.h"
#include <iostream>

EnemyObject::EnemyObject() : CharacterObject() {
	m_IdleAnimation = m_WalkAnimation = nullptr;
	m_IdleTextures = m_WalkTextures = std::vector<Texture*>();
}

EnemyObject::~EnemyObject() {
}

void EnemyObject::Initialise(Vector2 position, Vector2 size) {
	for (int i = 0; i < 13; i++) {
		if (i < 8) {
			m_IdleTextures.push_back(new Texture());
			m_IdleTextures.at(i)->Initialise("Assets/Skeleton/Skeleton Idle.png", Vector2(12 + (24 * i), 16), Vector2(24, 32));
		}

		m_WalkTextures.push_back(new Texture());
		m_WalkTextures.at(i)->Initialise("Assets/Skeleton/Skeleton Walk.png", Vector2(12 + (24 * i), 16), Vector2(24, 32));
	}
	m_IdleAnimation = new Animation("Idle", m_IdleTextures, 0.1f);
	m_WalkAnimation = new Animation("Walk", m_WalkTextures, 0.1f);

	m_Animator->AddAnimation(m_IdleAnimation);
	m_Animator->AddAnimation(m_WalkAnimation);
	m_Animator->SetAnimation("Idle");

	CharacterObject::Initialise(position, size);
}

void EnemyObject::Update(Vector2 playerPos) {
	Vector2 dir = playerPos - m_Pos;
	dir.Normalise();
	std::cout << "Normalised vector: " << dir << '\n';

	m_Velocity = dir * 2.0f;

	CharacterObject::Update();
}