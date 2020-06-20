#include "Animator.h"
#include <iostream>

Animator::Animator()
{
	m_Index = 0;
}

Animator::~Animator()
{
}

void Animator::Update()
{
	if (m_Animations.size() > 0) {
		m_Animations.at(m_Index)->Play();
	}
}

void Animator::AddAnimation(Animation* animation)
{
	m_Animations.push_back(animation);
}

void Animator::SetAnimation(const char* name)
{
	if(m_Animations.size() > 0){
		if (m_Animations.at(m_Index)->GetName() != name) {
			for (int i = 0; i < m_Animations.size(); i++) {
				if (m_Animations.at(i)->GetName() == name) {
					m_Index = i;
					break;
				}
			}
		}
	}
	else {
		std::cout << "NO ANIMATIONS ADDED TO ANIMATOR\n";
	}
}
