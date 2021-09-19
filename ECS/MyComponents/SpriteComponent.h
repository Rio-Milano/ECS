#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include"../Base/BaseComponent.h"
#include"SFML/Graphics.hpp"

struct SpriteComponent final : public BaseComponent
{
	//a texture is made and initialized and a sprite holds an alies to that texture 
	sf::Sprite sprite;
};
#endif