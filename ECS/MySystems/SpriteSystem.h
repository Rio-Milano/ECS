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

	/*
	Overriding Virtual Functions
	*/
	void ResetComponent(const uint32_t& entityID, ECS_Engine& ecs) override final;

	void UpdateComponent(const uint32_t& entityID, ECS_Engine& ecs) override final;

};

#endif
