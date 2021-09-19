#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H

#include"../Base/System.h"
#include"../MyComponents/MovementComponent.h"


class MovementSystem final : public System
{
public:
	/*
	SEE SYSTEM CLASS FOR COMMENTS
	*/

	MovementSystem() = default;
	~MovementSystem() = default;

	
	/*
	Overriding Virtual Functions
	*/
	void ResetComponent(const uint32_t& entityID, ECS_Engine& ecs) override;

	void UpdateComponent(const uint32_t& entityID, ECS_Engine& ecs) override;
};

#endif