#ifndef KEYBOARDMOVEMENTSYSTEMCOMPONENT_H
#define KEYBOARDMOVEMENTSYSTEMCOMPONENT_H


#include"../Base/BaseComponent.h"

struct KeyboardMovementSystemComponent final : public BaseComponent
{
	KeyboardMovementSystemComponent(const float& x_velocity, const float& y_velocity)
		:x_velocity(x_velocity), y_velocity(y_velocity) {}

	float x_velocity{ 0.0f };
	float y_velocity{ 0.0f };

	
};

#endif