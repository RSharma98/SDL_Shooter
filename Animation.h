#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL.h>
#include <vector>
#include "Texture.h"

class Animation {
public:
	Animation(const char* name, std::vector<Texture*> textures, float updateRate, bool loop = true);
	~Animation();

	void Play();	//Play the animation

	bool GetIsComplete() { return m_IsCompleted; }
	const char* GetName() { return m_Name; }

	Texture* GetTexture() { return m_Textures.at(m_CurrentFrame); }

protected:
	const char* m_Name;		//The name of this animation
	int m_CurrentFrame;		//The current frame the animation is on
	float m_ElapsedTime;	//Animation time elapsed
	float m_UpdateRate;		//The rate at which the frame is changed
	bool m_Loop;			//Is this a looping animation?
	bool m_IsCompleted;		//Has the animation been completed (only for non-looping animations)

	std::vector<Texture*> m_Textures;
};
#endif // !ANIMATION_H