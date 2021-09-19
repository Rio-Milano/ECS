#include"CollisionSystem.h"
#include"../Base/ECS_Engine.h"
#include"../MyComponents/CollisionComponent.h"
#include"../MyComponents/TransformComponent.h"
#include<string>
void CollisionSystem::ResetComponent(const uint32_t& entityID, ECS_Engine& ecs)
{
}

void CollisionSystem::UpdateComponent(const uint32_t& entityID, ECS_Engine& ecs)
{

	auto entityIDCollisionComponent = ecs.GetComponent<CollisionComponent>(entityID);
	entityIDCollisionComponent->m_listOfEntityIDsColliding.clear();

	auto entityIDTransformComponent = ecs.GetComponent<TransformComponent>(entityID);
	if (!m_componentEngine.IsMemoryValid({ entityIDTransformComponent })) throw std::string("Bad Memory");


	auto& collisionSystemComponentPool = m_componentEngine.GetComponentPool();
	auto currentComponentRecord = collisionSystemComponentPool.find(entityID);

	for (auto i = collisionSystemComponentPool.begin(); i != collisionSystemComponentPool.end(); i++)
	{
		//check collision with self
		if (i == currentComponentRecord)
			continue;

		//check collision
		auto otherEntityIDTransformComponent = ecs.GetComponent<TransformComponent>(i->first);
		if (!m_componentEngine.IsMemoryValid({ otherEntityIDTransformComponent })) throw std::string("Bad Memory");

		if (CheckAABBCollision(currentComponentRecord->first, i->first, ecs))
			entityIDCollisionComponent->m_listOfEntityIDsColliding.emplace_back(i->first);

	}



}

const bool CollisionSystem::CheckAABBCollision(const uint32_t& entityID_A, const uint32_t& entityID_B, ECS_Engine& ecs) const
{
	auto entityA_Transform = ecs.GetComponent<TransformComponent>(entityID_A);
	auto entityA_CollisionComponent = ecs.GetComponent<CollisionComponent>(entityID_A);

	auto entityB_Transform = ecs.GetComponent<TransformComponent>(entityID_B);
	auto entityB_CollisionComponent = ecs.GetComponent<CollisionComponent>(entityID_B);

	if (entityA_Transform->position.x < entityB_Transform->position.x + entityB_CollisionComponent->width &&
		entityA_Transform->position.x + entityA_CollisionComponent->width > entityB_Transform->position.x &&
		entityA_Transform->position.y < entityB_Transform->position.y + entityB_CollisionComponent->height &&
		entityA_Transform->position.y + entityA_CollisionComponent->height > entityB_Transform->position.y)

		return true;

	else

		return false;

}
