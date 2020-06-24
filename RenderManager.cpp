#include "RenderManager.h"
#include <iostream>

RenderManager* RenderManager::Instance = NULL;

struct RenderManager::Sprite {
public:
	SpriteRenderer* spriteRenderer;
	Vector2 position;
	Vector2 size;
	float angle;
};

RenderManager::RenderManager() {
	if (RenderManager::Instance == NULL) RenderManager::Instance = this;
	sprites = std::vector<Sprite>();
}

RenderManager::~RenderManager() {
	while(sprites.size() > 0){
		sprites[0].spriteRenderer = nullptr;
		sprites.erase(sprites.begin());
	}
}

void RenderManager::AddToRenderQueue(SpriteRenderer* spriteRenderer, Vector2 position, Vector2 size, float angle) {
	Sprite sprite;
	sprite.spriteRenderer = spriteRenderer;
	sprite.position = position;
	sprite.size = size;
	sprite.angle = angle;
	sprites.push_back(sprite);
}

void RenderManager::RemoveFromRenderQueue(SpriteRenderer* spriteRenderer)
{
	for (int i = 0; i < sprites.size(); i++) {
		if (sprites[i].spriteRenderer == spriteRenderer) {
			sprites[i].spriteRenderer = nullptr;
			sprites.erase(sprites.begin() + i);
			break;
		}
	}
}

void RenderManager::Render(SDL_Renderer* renderer) {
	Camera* cam = Camera::Instance;
	/*for (int i = 0; i < sprites.size(); i++) {
		Sprite sprite = sprites[i];
		Vector2 screenPos = cam->WorldToScreenUnits(sprite.position);
		Vector2 spriteSize = sprite.size * cam->GetUnitSize();
		SDL_Rect destRect;
		destRect.x = screenPos.x - spriteSize.x / 2;
		destRect.y = screenPos.y - spriteSize.y / 2;
		destRect.w = spriteSize.x;
		destRect.h = spriteSize.y;

		if (sprite.spriteRenderer->flipX || sprite.spriteRenderer->flipY) {
			SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE;
			float angle = 0;
			if (sprite.spriteRenderer->flipX && !sprite.spriteRenderer->flipY) flip = SDL_RendererFlip::SDL_FLIP_HORIZONTAL;
			else if (!sprite.spriteRenderer->flipX && sprite.spriteRenderer->flipY) flip = SDL_RendererFlip::SDL_FLIP_VERTICAL;
			else angle = 180.0f;
			SDL_RenderCopyEx(renderer, sprite.spriteRenderer->m_Texture->GetTexture(), &sprite.spriteRenderer->m_Texture->GetSourceRect(), &destRect, angle, NULL, flip);
		}
		else {
			SDL_RenderCopy(renderer, sprite.spriteRenderer->m_Texture->GetTexture(), &sprite.spriteRenderer->m_Texture->GetSourceRect(), &destRect);
		}
	}
	sprites.clear();*/

	while (sprites.size() > 0) {
		Sprite sprite = sprites[0];
		Vector2 screenPos = cam->WorldToScreenUnits(sprite.position);
		Vector2 spriteSize = sprite.size * cam->GetUnitSize();
		SDL_Rect destRect;
		destRect.x = screenPos.x - spriteSize.x / 2;
		destRect.y = screenPos.y - spriteSize.y / 2;
		destRect.w = spriteSize.x;
		destRect.h = spriteSize.y;

		SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE;
		float angle = sprite.angle;
		if (sprite.spriteRenderer->flipX || sprite.spriteRenderer->flipY) {
			if (sprite.spriteRenderer->flipX && !sprite.spriteRenderer->flipY) flip = SDL_RendererFlip::SDL_FLIP_HORIZONTAL;
			else if (!sprite.spriteRenderer->flipX && sprite.spriteRenderer->flipY) flip = SDL_RendererFlip::SDL_FLIP_VERTICAL;
			else angle = sprite.angle - 180.0f;
		}
		SDL_RenderCopyEx(renderer, sprite.spriteRenderer->m_Texture->GetTexture(), &sprite.spriteRenderer->m_Texture->GetSourceRect(), &destRect, angle, NULL, flip);

		sprites[0].spriteRenderer = nullptr;
		sprites.erase(sprites.begin());
	}
}