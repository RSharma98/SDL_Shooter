#ifndef GUN_OBJECT_H
#define GUN_OBJECT_H

#include "GameObject.h"
#include "Texture.h"
#include "Time.h"

class GunObject : public GameObject
{
public:
	GunObject(Vector2 position, Vector2 size);
	~GunObject();
	void Update(Vector2 position, float angle);

private:
	Texture* m_Texture;
	//TODO: Add private variables for gun properties (such as fire rate, reload time, etc)
};

#endif // !GUN_OBJECT_H