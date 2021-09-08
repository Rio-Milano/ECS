#include "KeyboardMovementSystem.h"

#include"../MyComponents/MovementComponent.h"
#include"../MyComponents/TransformComponent.h"

#include"../Base/ECS_Engine.h"
#define ECS ECS_Engine::Get_Instance()

#include"TransformSystyem.h"

#include<SFML/System.hpp>


void KeyboardMovementSystem::Update_Component(const uint32_t& Entity)
{
	if (!Is_Memory_Vaid({ ECS.m_systems.m_TransformSystem->Get_Component(Entity) }))throw std::string("Bad Memory");

	std::shared_ptr<MovementComponent> l_MovementComponent{ std::static_pointer_cast<MovementComponent>( m_System_DataStore[Entity] )}; 
	std::shared_ptr<TransformComponent> l_TransformComponent{ std::static_pointer_cast<TransformComponent>(ECS.m_systems.m_TransformSystem->Get_Component(Entity)) };
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		l_TransformComponent->position.y -= l_MovementComponent->y_velocity;

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		l_TransformComponent->position.y += l_MovementComponent->y_velocity;
	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		l_TransformComponent->position.x -= l_MovementComponent->x_velocity;

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		l_TransformComponent->position.x += l_MovementComponent->x_velocity;
}

void KeyboardMovementSystem::Reset_Component(const uint32_t& Entity)
{
	m_System_DataStore[Entity] = std::make_shared<MovementComponent>();
}
