#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SDL.h"
#include "RenderManager.h"
#include "SpriteRenderer.h"
#include <time.h>
#include <cstdlib>
#include "Vector2.h"

class GameObject {
public:
	GameObject(Vector2 position, Vector2 size);
	~GameObject();
	void Update();
	Vector2 GetPos() { return m_Pos; }
	Vector2 GetSize() { return m_Size; }
	float GetAngle() { return m_Angle; }

	void SetPosition(Vector2 position) { m_Pos = position; }
	void SetSize(Vector2 size) { m_Size = size; }
	void SetAngle(float angle) { m_Angle = angle; }
	SpriteRenderer* GetSpriteRenderer() { return spriteRenderer; }

protected:
	int Random(int max);
	SpriteRenderer* spriteRenderer;
	Vector2 m_Pos;
	Vector2 m_Size;
	float m_Angle;
};

#endif
