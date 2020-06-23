#include "BulletObject.h"

BulletObject::BulletObject(Vector2 mousePos, Vector2 position, Vector2 size) : GameObject(position, size)
{
	m_MoveSpeed = 2.0f;
	m_Velocity = Vector2(0, 0);
	m_Box = new BoxCollider2D(position, Vector2(0, 0), size);
	m_Dir = mousePos - position;
	m_Dir.Normalise();
	m_Texture = new Texture("Assets/Square.png", Vector2(1, 1), Vector2(2, 2));
	spriteRenderer->SetTexture(m_Texture);
}

BulletObject::~BulletObject()
{
}

void BulletObject::Update()
{
	m_Velocity = m_Dir * m_MoveSpeed;
	m_Pos += m_Velocity * Time::GetDeltaTime();

	GameObject::Update();
	m_Box->position = m_Pos;
	m_Box->Update();
}
