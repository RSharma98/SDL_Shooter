#ifndef BULLET_OBJECT_H
#define BULLET_OBJECT_H

#include "GameObject.h"
#include "BoxCollider2D.h"
#include "Animation.h"
#include "Animator.h"
#include "Time.h"

class BulletObject : public GameObject
{
public:
	BulletObject(Vector2 mousePos, Vector2 position, Vector2 size);
	~BulletObject();
	void Update();
	BoxCollider2D* GetBox() { return m_Box; }

	float GetTimeToDestroy() { return m_TimeToDestroy; }	//The time until this object is destroyed

protected:
	float m_MoveSpeed;
	float m_TimeToDestroy;
	Vector2 m_Velocity;
	Vector2 m_Dir;
	BoxCollider2D* m_Box;

	Texture* m_Texture;
};

#endif // !BULLET_OBJECT_H