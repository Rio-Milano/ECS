#ifndef COLLISIONCOMPONENT_H
#define COLLISIONCOMPONENT_H


#include"../Base/BaseComponent.h"
#include<list>

struct CollisionComponent final : public BaseComponent
{
	typedef enum struct CollisionComponentCollisionLayer
	{
		Default = 0,
		Layer1 = 1,
		Layer2 = 2,
		Layer3 = 3,
		Layer4 = 4,
		Layer5 = 5,
		Layer6 = 6,
		Layer7 = 7,
		Layer8 = 8
	}CollisionLayer;

	CollisionComponent(const CollisionLayer& collisionLayer, const float& width, const float& height) :
		m_collisionLayer(collisionLayer), width(width), height(height) {};
	~CollisionComponent() = default;



	CollisionLayer m_collisionLayer;
	std::list<uint32_t> m_listOfEntityIDsColliding;
	float width, height;

};

#endif