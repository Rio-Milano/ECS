#ifndef HEALTHSYSTEM_H
#define HEALTHSYSTEM_H

#include"../Base/System.h"

#include"../MyComponents/HealthComponent.h"


class HealthSystem : public System
{
public:
	/*
	SEE SYSTEM CLASS FOR COMMENTS
	*/

	HealthSystem() = default;
	~HealthSystem() = default;

	void Reset_Component(const uint32_t& Entity) override final;

	void Update_Component(const uint32_t& Entity) override final;

};

#endif