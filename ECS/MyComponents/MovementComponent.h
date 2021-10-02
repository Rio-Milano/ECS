#ifndef MOVEMENT_H
#define MOVEMENT_H

#include"../Base/BaseComponent.h"

struct MovementComponent final : public BaseComponent
{
	MovementComponent(const float& x_velocity, const float& y_velocity)
		:x_velocity(x_velocity), y_velocity(y_velocity) {}

	float x_velocity{0.0f};
	float y_velocity{0.0f};

	
};

#endif