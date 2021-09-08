#include"TransformSystyem.h"

#include"../MyComponents/TransformComponent.h"

void TransformSystem::Reset_Component(const uint32_t& Entity)
{
	std::shared_ptr<TransformComponent> transform_component = std::static_pointer_cast<TransformComponent>(m_System_DataStore[Entity]);

	transform_component->position = {0.0f, 0.0f};
	transform_component->rotation = 0.0f;
	transform_component->scale = 1.0f;

}
