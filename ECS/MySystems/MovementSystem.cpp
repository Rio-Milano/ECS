#include"../MySystems/MovementSystem.h"

#include"../Base/ECS_Engine.h"
#define ECS ECS_Engine::Get_Instance()

#include"../MyComponents/MovementComponent.h"
#include"../MyComponents/TransformComponent.h"



void MovementSystem::Update_Component(const uint32_t& Entity)
{
	if (!Is_Memory_Vaid({ ECS.m_systems.m_TransformSystem->Get_Component(Entity) }))throw std::string("Bad Memory");

	std::shared_ptr<MovementComponent> movement_component  = std::static_pointer_cast<MovementComponent>(m_System_DataStore[Entity]);
	std::shared_ptr<TransformComponent> transform_component = std::static_pointer_cast<TransformComponent>(ECS.m_systems.m_TransformSystem->Get_Component(Entity));

	transform_component->position.x += movement_component->x_velocity;
	transform_component->position.y += movement_component->y_velocity;

}

void MovementSystem::Reset_Component(const uint32_t& Entity)
{
	std::shared_ptr<MovementComponent> movement_component = std::static_pointer_cast<MovementComponent>(m_System_DataStore[Entity]);

	movement_component->x_velocity = 0.0f;
	movement_component->y_velocity = 0.0f;
}
