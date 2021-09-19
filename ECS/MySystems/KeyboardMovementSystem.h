#ifndef KEYBOARDMOVEMENTSYSTEM_H
#define KEYBOARDMOVEMENTSYSTEM_H

#include"../Base/System.h"
#include"../MyComponents/MovementComponent.h"


class KeyboardMovementSystem final : public System
{
public:
	/*
	SEE SYSTEM CLASS FOR COMMENTS
	*/

	KeyboardMovementSystem() = default;
	~KeyboardMovementSystem() = default;

	/*
	Overriding Virtual Functions
	*/
	void ResetComponent(const uint32_t& entityID, ECS_Engine& ecs) override;

	void UpdateComponent(const uint32_t& entityID, ECS_Engine& ecs) override;

};

#endif