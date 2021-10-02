#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include"../Base/BaseComponent.h"
#include"../../DataStructures/Vector2.h"

#include<SFML/Graphics.hpp>

struct TransformComponent final : public BaseComponent
{
	TransformComponent(const sf::Vector2f& position, const float& rotation = 0, const float& scale = 1)
		:position(position), rotation(rotation), scale(scale) {}


	sf::Vector2f position{ 0.0f, 0.0f };
	
	float rotation{0.0f};

	float scale{1.0f};
};

#endif