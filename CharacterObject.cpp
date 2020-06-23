#include "CharacterObject.h"

CharacterObject::CharacterObject(Vector2 position, Vector2 size) : GameObject(position, size)
{
	m_MoveSpeed = 0.0f;
	m_Velocity = Vector2(0, 0);
	m_Animator = new Animator();
	m_Box = new BoxCollider2D(position, Vector2(0, 0), size);
}

CharacterObject::~CharacterObject()
{
	delete m_Box;
	delete m_Animator;
	m_Box = nullptr;
	m_Animator = nullptr;
}

void CharacterObject::Update()
{
	m_Animator->Update();
	spriteRenderer->SetTexture(m_Animator->GetAnimation()->GetTexture());
	if (m_Velocity.x != 0) spriteRenderer->flipX = (m_Velocity.x > 0) ? false : true;

	m_Pos += m_Velocity * Time::GetDeltaTime();

	GameObject::Update();
	m_Box->position = m_Pos;
	m_Box->Update();
}
