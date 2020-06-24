#ifndef PLAYER_OBJECT_H
#define PLAYER_OBJECT_H

#include "CharacterObject.h"
#include "GunObject.h"
#include "BulletObject.h"
#include "Input.h"

class PlayerObject : public CharacterObject
{
public:
	PlayerObject(Vector2 position, Vector2 size);
	~PlayerObject();
	void Update();

private:
	Vector2 m_DirLastFrame;	
	
	std::vector<Texture*> m_IdleTextures;
	Animation* m_IdleAnimation;
	
	std::vector<Texture*> m_RunTextures;
	Animation* m_RunAnimation;

	GunObject* gun;
};

#endif // !PLAYER_OBJECT_H