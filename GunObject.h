#ifndef GUN_OBJECT_H
#define GUN_OBJECT_H

#include "GameObject.h"
#include "Texture.h"
#include "Time.h"
#include "BulletObject.h"
#include "MathHelper.h"
#include "Input.h"

class GunObject : public GameObject
{
public:
	GunObject(Vector2 position, Vector2 size);
	~GunObject();
	void Update(Vector2 pos);

private:
	Texture* m_Texture;
	std::vector<BulletObject*> m_Bullets;
	//TODO: Add private variables for gun properties (such as fire rate, reload time, etc)
};

#endif // !GUN_OBJECT_H