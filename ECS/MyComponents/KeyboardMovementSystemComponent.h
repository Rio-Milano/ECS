#ifndef KEYBOARDMOVEMENTSYSTEMCOMPONENT_H
#define KEYBOARDMOVEMENTSYSTEMCOMPONENT_H


#include"../Base/BaseComponent.h"

struct KeyboardMovementSystemComponent final : public BaseComponent
{
	float x_velocity{ 0.0f };
	float y_velocity{ 0.0f };
};

#endif