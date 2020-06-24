#include "GunObject.h"
#include <iostream>

GunObject::GunObject(Vector2 position, Vector2 size) : GameObject(position, size)
{
	m_Bullets = std::vector<BulletObject*>();
	m_Texture = new Texture("Assets/Weapons/AK47 Sheet.png", Vector2(60, 16), Vector2(120, 36));
	spriteRenderer->SetTexture(m_Texture);
}

GunObject::~GunObject()
{
	delete m_Texture;
	m_Texture = nullptr;

	for (int i = 0; i < m_Bullets.size(); i++) {
		delete m_Bullets[i];
		m_Bullets[i] = nullptr;
		m_Bullets.erase(m_Bullets.begin() + i);
	}
}

void GunObject::Update(Vector2 pos)
{
	Vector2 mousePos = Camera::Instance->ScreenToWorldUnits(Input::GetMousePosition());
	m_Angle = atan2(mousePos.y - m_Pos.y, mousePos.x - m_Pos.x) * 180.0f / M_PI * -1;	//Calculate the gun angle
	spriteRenderer->flipY = MathHelper::Absolute(m_Angle) > 90.0f;	//Flip the gun so it's always facing the right direction
	m_Pos = pos;

	//When the left mouse button is pressed, shoot a bullet
	if (Input::GetMouseButtonDown(0)) {
		Vector2 dir = mousePos - m_Pos;
		float magnitude = dir.GetMagnitude();
		Vector2 bulletPos = m_Pos + (dir * ((m_Size.x / 2.0f) / magnitude));	//Calculate bullet spawn position so it spawns at tip of gun
		m_Bullets.push_back(new BulletObject(bulletPos, dir, Vector2(0.5f, 0.2f)));
	}

	for (int i = 0; i < m_Bullets.size(); i++) {
		m_Bullets[i]->Update();
		if (m_Bullets[i]->GetTimeToDestroy() <= 0.0f) {
			delete m_Bullets[i];
			m_Bullets[i] = nullptr;
			m_Bullets.erase(m_Bullets.begin() + i);
		}
	}

	GameObject::Update();
}
