#include"SpriteSystem.h"

#include"../MyComponents/SpriteComponent.h"
#include"../MyComponents/TransformComponent.h"

#include"../Base/ECS_Engine.h"

void SpriteSystem::ResetComponent(const uint32_t& entityID, ECS_Engine& ecs)
{
	ecs.GetComponent<SpriteComponent>(entityID)->sprite.setTexture(sf::Texture());
}


void SpriteSystem::UpdateComponent(const uint32_t& entityID, ECS_Engine& ecs)
{
	if (!IsMemoryValid({ ecs.GetComponent<SpriteComponent>(entityID)}))throw std::string("Bad Memory");

	std::shared_ptr<TransformComponent> l_transform = ecs.GetComponent<TransformComponent>(entityID);
	std::shared_ptr<SpriteComponent> l_sprite = ecs.GetComponent<SpriteComponent>(entityID);

	l_sprite->sprite.setPosition(l_transform->position);
	l_sprite->sprite.setRotation(l_transform->rotation);
	l_sprite->sprite.setScale(l_transform->scale, l_transform->scale);
}
