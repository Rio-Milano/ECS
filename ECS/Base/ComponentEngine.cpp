#include "ComponentEngine.h"



void ComponentEngine::ClearComponents()
{
	m_Component_DataStore.clear();
}

const bool ComponentEngine::IsMemoryValid(const std::list<std::shared_ptr<BaseComponent>>& listOfComponentPointers) const
{
	for (auto i : listOfComponentPointers)
		if (!i) return false;
	return true;
}

std::shared_ptr<BaseComponent> ComponentEngine::GetComponent(const uint32_t& entityID)
{
	return m_Component_DataStore[entityID];
}

std::shared_ptr<BaseComponent> ComponentEngine::AddComponent(const uint32_t& entityID, const std::shared_ptr<BaseComponent>& component)
{
	m_Component_DataStore[entityID] = component;
	return m_Component_DataStore[entityID];
}

void ComponentEngine::RemoveComponent(const uint32_t& entityID)
{
	m_Component_DataStore.erase(entityID);
}

std::unordered_map<uint32_t, std::shared_ptr<BaseComponent>>& ComponentEngine::GetComponentPool()
{
	return m_Component_DataStore;
}
