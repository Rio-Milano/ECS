#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H

#include"../Base/System.h"
#include"../MyComponents/MovementComponent.h"


class MovementSystem : public System
{
public:
	/*
	SEE SYSTEM CLASS FOR COMMENTS
	*/

	MovementSystem() = default;
	~MovementSystem() = default;

	void Reset_Component(const uint32_t& Entity) override final;

	void Update_Component(const uint32_t& Entity) override final;
};

#endif