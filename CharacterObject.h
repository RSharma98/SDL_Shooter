#pragma once
#ifndef CHARACTER_OBJECT_H
#define CHARACTER_OBJECT_H

#include "GameObject.h"
#include "BoxCollider2D.h"
#include "Animation.h"
#include "Animator.h"
#include "Time.h"

class CharacterObject : public GameObject
{
public:
	CharacterObject();
	~CharacterObject();
	void Initialise(Vector2 position, Vector2 size);
	void Update();
	BoxCollider2D* GetBox() { return m_Box; }

protected:
	float m_MoveSpeed;
	Vector2 m_Velocity;
	BoxCollider2D* m_Box;

	Animator* m_Animator;
};

#endif // !CHARACTER_OBJECT_H