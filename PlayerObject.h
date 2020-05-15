#pragma once
#ifndef PLAYER_OBJECT_H
#define PLAYER_OBJECT_H

#include "GameObject.h"
#include "BoxCollider2D.h"

class PlayerObject : public GameObject
{
public:
	PlayerObject();
	~PlayerObject();
	void Initialise(SDL_Renderer* renderer, Vector2 position, Vector2 size);
	void Update();
	void Render(SDL_Renderer* renderer);
	void MoveHorizontal(float speed, BoxCollider2D enemy);
	void SetPosition(Vector2 position);
	void Fall(float speed);
	BoxCollider2D GetBox() { return box; }

private:
	const int moveSpeed = 10;
	BoxCollider2D box;
};

#endif // !PLAYER_OBJECT_H