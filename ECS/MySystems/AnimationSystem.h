#ifndef ANIMATIONSYSTEM_H
#define ANIMATIONSYSTEM_H

#include"../Base/System.h"
#include<SFML/Graphics.hpp>
#include<utility>

class AnimationSystem final : public System
{

public:

	void ResetComponent(const uint32_t& entityID, ECS_Engine& ecs) override;
	virtual void UpdateComponent(const uint32_t& entityID, ECS_Engine& ecs) override;

	void AddAnimationFromSpriteSheet(const std::string& textureName, const std::string& animationName, const int& animationsOnXAxis, const int& animationsOnYAxis, const int& startFrameX, const int& StartFrameY, const int& frameCount);

private:
	//string ---> [Texture, Vector[IntRect]
	std::unordered_map<std::string, std::pair<std::string,std::vector<sf::IntRect>>> m_animationDataStore;
};

#endif
