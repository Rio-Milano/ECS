#ifndef SPRITESYSTEM_H
#define SPRITESYSTEM_H

#include"../Base/System.h"
#include"../MyComponents/SpriteComponent.h"

class SpriteSystem : public System
{
public:
	/*
	SEE SYSTEM CLASS FOR COMMENTS
	*/

	SpriteSystem() = default;
	~SpriteSystem() = default;

	void Reset_Component(const uint32_t& Entity) override final;

	void Update_Component(const uint32_t& Entity) override final;

};

#endif
