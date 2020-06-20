#ifndef ANIMATOR_H
#define ANIMATOR_H

#include "Animation.h"

class Animator {
public:
	Animator();
	~Animator();
	void Update();
	void AddAnimation(Animation* animation);	//Add an animation to play
	void SetAnimation(const char* name);		//Set the animation to play

	Animation* GetAnimation() { return m_Animations.at(m_Index); }

private:
	std::vector<Animation*> m_Animations;	//The list of animations
	int m_Index;	//The index of the current animation
};

#endif // !ANIMATOR_H
