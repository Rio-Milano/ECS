#include "HealthSystem.h"
#include<iostream>

#include<memory>

void HealthSystem::Update_Component(const uint32_t& Entity)
{
	std::shared_ptr<HealthComponent> l_HP{std::static_pointer_cast<HealthComponent>( m_System_DataStore[Entity])};
	
	l_HP->HP += 1.f;

	if (l_HP->HP > l_HP->MAX_HP)
		l_HP->HP = l_HP->MAX_HP;
}

void HealthSystem::Reset_Component(const uint32_t& Entity)
{
}
