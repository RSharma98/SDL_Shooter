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
	GameObject();
	~GameObject();
	void Initialise(Vector2 position, Vector2 size);
	void Update();
	Vector2 GetPos() { return m_Pos; }
	Vector2 GetSize() { return m_Size; }

	void SetPosition(Vector2 position) { m_Pos = position; }
	void SetSize(Vector2 size) { m_Size = size; }

protected:
	int Random(int max);
	SpriteRenderer* spriteRenderer;
	Vector2 m_Pos;
	Vector2 m_Size;
};

#endif
