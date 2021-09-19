#ifndef HEALTHSYSTEM_H
#define HEALTHSYSTEM_H


#include"../Base/System.h"
#include"../MyComponents/HealthComponent.h"


class HealthSystem final : public System
{
public:
	/*
	SEE SYSTEM CLASS FOR COMMENTS
	*/

	HealthSystem() = default;
	~HealthSystem() = default;

	/*
	Overriding Virtual Functions
	*/

	void ResetComponent(const uint32_t& entityID, ECS_Engine& ecs) override;

	void UpdateComponent(const uint32_t& entityID, ECS_Engine& ecs) override;

};

#endif