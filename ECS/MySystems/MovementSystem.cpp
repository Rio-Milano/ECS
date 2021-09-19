
#include"../MySystems/MovementSystem.h"
#include"../Base/ECS_Engine.h"
#include"../MyComponents/TransformComponent.h"
#include"../MyComponents/MovementComponent.h"




void MovementSystem::UpdateComponent(const uint32_t& entityID, ECS_Engine& ecs)
{
	if (!m_componentEngine.IsMemoryValid({ ecs.GetComponent<TransformComponent>(entityID) }))throw std::string("Bad Memory");

	auto movement_component = ecs.GetComponent<MovementComponent>(entityID);
	auto transform_component = ecs.GetComponent<TransformComponent>(entityID);

	transform_component->position.x += movement_component->x_velocity;
	transform_component->position.y += movement_component->y_velocity;

}

void MovementSystem::ResetComponent(const uint32_t& Entity, ECS_Engine& ecs)
{
	std::shared_ptr<MovementComponent> movement_component = ecs.GetComponent<MovementComponent>(Entity);

	movement_component->x_velocity = 0.0f;
	movement_component->y_velocity = 0.0f;
}
