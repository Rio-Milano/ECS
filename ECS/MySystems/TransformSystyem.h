#ifndef TRANSFORMSYSTEM_H
#define TRANSFORMSYSTEM_H

#include"../Base/System.h"
#include"../MyComponents/TransformComponent.h"

class TransformSystem : public System
{
public:
	/*
	SEE SYSTEM CLASS FOR COMMENTS
	*/

	TransformSystem() = default;
	~TransformSystem() = default;

	void Reset_Component(const uint32_t& Entity) override final;


};

#endif
