#include "GunObject.h"

GunObject::GunObject(Vector2 position, Vector2 size) : GameObject(position, size)
{
	m_Texture = new Texture("Assets/Weapons/AK47 Sheet.png", Vector2(60, 16), Vector2(120, 36));
	spriteRenderer->SetTexture(m_Texture);
}

GunObject::~GunObject()
{
	delete m_Texture;
	m_Texture = nullptr;
}

void GunObject::Update(Vector2 position, float angle)
{
	m_Pos = position;
	m_Angle = angle;
	GameObject::Update();
}
