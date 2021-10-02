#ifndef ANIMATIONCOMPONENT_H
#define ANIMATIONCOMPONENT_H

#include"../Base/BaseComponent.h"
#include<string>
#include<SFML/Graphics.hpp>
#include<memory>

struct AnimationComponent final : public BaseComponent
{
	AnimationComponent(const std::string& animationName, const unsigned int& animationFrame, const float& speed)
	:m_animationFrame(animationFrame), m_animation_name(animationName), speed(speed) {};
	
	unsigned int m_animationFrame;
	std::string m_animation_name;
	float speed, elapsed = 0;
};

#endif