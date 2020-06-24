#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

#include "SDL.h"
#include "Vector2.h"
#include "SpriteRenderer.h"
#include "Camera.h"
#include <vector>

class RenderManager {
public:
	RenderManager();
	~RenderManager();
	void Render(SDL_Renderer* renderer);
	void AddToRenderQueue(SpriteRenderer* spriteRenderer, Vector2 position, Vector2 size, float angle);
	void RemoveFromRenderQueue(SpriteRenderer* spriteRenderer);
	static RenderManager* Instance;

private:
	struct Sprite;
	std::vector<Sprite> sprites;
};
#endif // !RENDERMANAGER_H
