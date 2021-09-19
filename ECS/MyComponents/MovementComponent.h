#ifndef MOVEMENT_H
#define MOVEMENT_H

#include"../Base/BaseComponent.h"

struct MovementComponent final : public BaseComponent
{
	float x_velocity{0.0f};
	float y_velocity{0.0f};
};

#endif