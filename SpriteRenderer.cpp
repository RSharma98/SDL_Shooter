#include "SpriteRenderer.h"

//Initialise the sprite rendererer
SpriteRenderer::SpriteRenderer() {
	m_Texture = new Texture();
	flipX = flipY = false;
	renderSprite = true;
	layerOrder = 0;
	colour = SDL_Color{ 255, 255, 255, 255 };
}

SpriteRenderer::~SpriteRenderer() {
	m_Texture = nullptr;
}

void SpriteRenderer::SetTexture(Texture* texture) {
	m_Texture = texture;
}
