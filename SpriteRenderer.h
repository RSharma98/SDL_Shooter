#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include "SDL.h"
#include "SDL_image.h"
#include "Texture.h"

class SpriteRenderer {
public:
	SpriteRenderer();
	~SpriteRenderer();
	void SetTexture(Texture* texture);

	Texture* m_Texture;
	bool flipX;
	bool flipY;
	bool renderSprite;
	int layerOrder;
	SDL_Color colour;
};

#endif 