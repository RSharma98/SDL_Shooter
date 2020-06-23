#include "SpriteRenderer.h"

//Initialise a sprite rendererer so an image can be loaded based on the image path and specified rects
SpriteRenderer::SpriteRenderer() {
	m_Texture = new Texture();
	flipX = flipY = false;
	renderSprite = true;
	colour = SDL_Color{ 255, 255, 255, 255 };
}

SpriteRenderer::~SpriteRenderer() {
}

void SpriteRenderer::SetTexture(Texture* texture) {
	m_Texture = texture;
}
