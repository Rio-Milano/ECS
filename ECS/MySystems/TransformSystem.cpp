
#include"TransformSystyem.h"
#include"../MyComponents/TransformComponent.h"
#include"../Base/ECS_Engine.h"


void TransformSystem::ResetComponent(const uint32_t& entityID, ECS_Engine& ecs)
{
	auto transform_component = ecs.GetComponent<TransformComponent>(entityID);

	transform_component->position = {0.0f, 0.0f};
	transform_component->rotation = 0.0f;
	transform_component->scale = 1.0f;

}
