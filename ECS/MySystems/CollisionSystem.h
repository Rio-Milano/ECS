#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

#include"../Base/System.h"

class CollisionSystem final : public System
{
public:

	void ResetComponent(const uint32_t& entityID, ECS_Engine& ecs) override;
	virtual void UpdateComponent(const uint32_t& entityID, ECS_Engine& ecs) override;


private :
	const bool CheckAABBCollision(const uint32_t& entityID_A, const uint32_t& entityID_B, ECS_Engine& ecs) const;
};

#endif
