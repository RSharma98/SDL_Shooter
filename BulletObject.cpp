#include "BulletObject.h"

BulletObject::BulletObject(Vector2 position, Vector2 dir, Vector2 size) : GameObject(position, size)
{
	m_MoveSpeed = 10.0f;
	m_TimeToDestroy = 7.0f;
	m_Velocity = Vector2(0, 0);
	m_Box = new BoxCollider2D(position, Vector2(0, 0), size);
	m_Dir = dir;
	m_Angle = atan2(dir.y, dir.x) * 180.0f / M_PI * -1;	//Calculate the angle
	m_Dir.Normalise();
	m_Texture = new Texture("Assets/Square.png", Vector2(1, 1), Vector2(2, 2));
	spriteRenderer->SetTexture(m_Texture);
}

BulletObject::~BulletObject()
{
	delete m_Box;
	m_Box = nullptr;

	delete m_Texture;
	m_Texture = nullptr;
}

void BulletObject::Update()
{
	m_Velocity = m_Dir * m_MoveSpeed;
	m_Pos += m_Velocity * Time::GetDeltaTime();

	GameObject::Update();
	m_Box->position = m_Pos;
	m_Box->Update();

	m_TimeToDestroy -= Time::GetDeltaTime();
}
