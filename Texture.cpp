#include "Texture.h"
#include "Game.h"

Texture::Texture() {
	m_Texture = nullptr;
	m_SourceRect = SDL_Rect();
}

Texture::Texture(const char* path, Vector2 position, Vector2 size)
{
	SDL_Surface* surface = IMG_Load(path);
	m_Texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
	SDL_FreeSurface(surface);

	m_SourceRect = SDL_Rect();
	m_SourceRect.x = (int)(position.x - size.x / 2);
	m_SourceRect.y = (int)(position.y - size.y / 2);
	m_SourceRect.h = (int)(size.y);
	m_SourceRect.w = (int)(size.x);
}

Texture::~Texture()
{
	SDL_DestroyTexture(m_Texture);
}

SDL_Rect Texture::GetSourceRect()
{
	return m_SourceRect;
}

SDL_Texture* Texture::GetTexture()
{
	return m_Texture;
}
