#include<iostream>
#include<memory>

#include "HealthSystem.h"
#include"../Base/ECS_Engine.h"



void HealthSystem::UpdateComponent(const uint32_t& entityID, ECS_Engine& ecs)
{
	auto l_HP = ecs.GetComponent<HealthComponent>(entityID);
	
	l_HP->HP += 1.f;

	if (l_HP->HP > l_HP->MAX_HP)
		l_HP->HP = l_HP->MAX_HP;
}

void HealthSystem::ResetComponent(const uint32_t& Entity, ECS_Engine& ecs)
{
}
