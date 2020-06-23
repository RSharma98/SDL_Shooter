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

protected:
	float m_MoveSpeed;
	Vector2 m_Velocity;
	Vector2 m_Dir;
	BoxCollider2D* m_Box;

	Texture* m_Texture;
};

#endif // !BULLET_OBJECT_H