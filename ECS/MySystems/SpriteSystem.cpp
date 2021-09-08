#include"SpriteSystem.h"

#include"../MyComponents/SpriteComponent.h"
#include"../MyComponents/TransformComponent.h"

#include"../Base/ECS_Engine.h"
#define ECS ECS_Engine::Get_Instance()

void SpriteSystem::Reset_Component(const uint32_t& Entity)
{
	static_cast<SpriteComponent*>(m_System_DataStore[Entity].get())->sprite.setTexture(sf::Texture());
}


void SpriteSystem::Update_Component(const uint32_t& Entity)
{
	if (!Is_Memory_Vaid({ ECS.m_systems.m_TransformSystem->Get_Component(Entity)}))throw std::string("Bad Memory");

	std::shared_ptr<TransformComponent> l_transform = std::static_pointer_cast<TransformComponent>(ECS.m_systems.m_TransformSystem->Get_Component(Entity));
	std::shared_ptr<SpriteComponent> l_sprite = std::static_pointer_cast<SpriteComponent>(m_System_DataStore[Entity]);

	l_sprite->sprite.setPosition(l_transform->position);
	l_sprite->sprite.setRotation(l_transform->rotation);
	l_sprite->sprite.setScale(l_transform->scale, l_transform->scale);
}
