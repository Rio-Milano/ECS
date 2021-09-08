#ifndef KEYBOARDMOVEMENTSYSTEM_H
#define KEYBOARDMOVEMENTSYSTEM_H

#include"../Base/System.h"
#include"../MyComponents/MovementComponent.h"


class KeyboardMovementSystem : public System
{
public:
	/*
	SEE SYSTEM CLASS FOR COMMENTS
	*/

	KeyboardMovementSystem() = default;
	~KeyboardMovementSystem() = default;

	void Reset_Component(const uint32_t& Entity) override final;

	void Update_Component(const uint32_t& Entity) override final;

};

#endif