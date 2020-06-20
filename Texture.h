#ifndef TEXTURE_H
#define TEXTURE_H

#include "Vector2.h"
#include <SDL.h>
#include <SDL_image.h>

class Texture {
public:
	Texture();
	~Texture();
	void Initialise(const char* path, Vector2 position, Vector2 size);
	SDL_Rect GetSourceRect();
	SDL_Texture* GetTexture();

private:
	SDL_Texture* m_Texture;
	SDL_Rect m_SourceRect;
};
#endif // !TEXTURE_H