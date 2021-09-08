#ifndef HEALTHCOMPONENT_H
#define HEALTHCOMPONENT_H

#include"../Base/BaseComponent.h"

struct HealthComponent : public BaseComponent
{
	HealthComponent() : HP(), MAX_HP() {};	
	~HealthComponent() = default;

	float HP, MAX_HP;
};

#endif
