#include "Animation.h"
#include "Time.h"

Animation::Animation(const char* name, std::vector<Texture*> textures, float updateRate, bool loop)
{
	m_Name = name;
	m_UpdateRate = updateRate;
	m_Loop = loop;

	m_CurrentFrame = 0;
	m_ElapsedTime = 0;
	m_IsCompleted = false;

	m_Textures = textures;
}

Animation::~Animation() {
	for (int i = 0; i < m_Textures.size(); i++) {
		delete m_Textures[i];
		m_Textures[i] = nullptr;
		m_Textures.erase(m_Textures.begin() + i);
	}
}

void Animation::Play() {
	if (m_Textures.size() > 0) {
		m_ElapsedTime += Time::GetDeltaTime();
		if (m_ElapsedTime >= m_UpdateRate) {
			m_CurrentFrame++;
			if (m_CurrentFrame > m_Textures.size() - 1) {
				if (m_Loop) m_CurrentFrame = 0;
				else m_IsCompleted = true;
			}
			m_ElapsedTime -= m_UpdateRate;
		}
	}
}
