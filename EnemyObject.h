#ifndef ENEMY_OBJECT_H
#define ENEMY_OBJECT_H

#include "CharacterObject.h"

class EnemyObject : public CharacterObject
{
public:
	EnemyObject();
	~EnemyObject();
	void Initialise(Vector2 position, Vector2 size);
	void Update(Vector2 playerPos);

private:
	std::vector<Texture*> m_IdleTextures;
	Animation* m_IdleAnimation;

	std::vector<Texture*> m_WalkTextures;
	Animation* m_WalkAnimation;
};

#endif // !ENEMY_OBJECT_H