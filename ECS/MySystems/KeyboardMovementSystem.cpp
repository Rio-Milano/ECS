


#include "KeyboardMovementSystem.h"
#include"../MyComponents/MovementComponent.h"
#include"../MyComponents/TransformComponent.h"
#include"../Base/ECS_Engine.h"
#include"TransformSystyem.h"
#include"../MyComponents/KeyboardMovementSystemComponent.h"


#include<SFML/System.hpp>


void KeyboardMovementSystem::UpdateComponent(const uint32_t& entityID, ECS_Engine& ecs)
{
	if (!m_componentEngine.IsMemoryValid({ ecs.GetComponent<TransformComponent>(entityID) }))throw std::string("Bad Memory");

	std::shared_ptr<KeyboardMovementSystemComponent> l_MovementComponent{ ecs.GetComponent<KeyboardMovementSystemComponent>( entityID)};
	std::shared_ptr<TransformComponent> l_TransformComponent{ ecs.GetComponent<TransformComponent>(entityID) };
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		l_TransformComponent->position.y -= l_MovementComponent->y_velocity;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		l_TransformComponent->position.y += l_MovementComponent->y_velocity;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		l_TransformComponent->position.x -= l_MovementComponent->x_velocity;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		l_TransformComponent->position.x += l_MovementComponent->x_velocity;
}

void KeyboardMovementSystem::ResetComponent(const uint32_t& entityID, ECS_Engine& ecs)
{
	auto component = ecs.GetComponent<KeyboardMovementSystemComponent>(entityID);
	component->x_velocity = 0;
	component->y_velocity = 0;
}
