#ifndef TRANSFORMSYSTEM_H
#define TRANSFORMSYSTEM_H

#include"../Base/System.h"
#include"../MyComponents/TransformComponent.h"

class TransformSystem final: public System
{
public:
	/*
	SEE SYSTEM CLASS FOR COMMENTS
	*/

	//ctors and dtors
	TransformSystem() = default;
	~TransformSystem() = default;

	/*
	Overriding Virtual Functions
	*/
	void ResetComponent(const uint32_t& entityID, ECS_Engine& ecs) override;


};

#endif
