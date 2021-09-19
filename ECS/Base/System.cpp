#include "System.h"


void System::ClearComponents()
{
	m_Component_DataStore.clear();
}

const bool System::IsMemoryValid(const std::list<std::shared_ptr<BaseComponent>>& listOfComponentPointers) const
{
	for (auto i : listOfComponentPointers)
		if (!i) return false;
	return true;
}

const std::shared_ptr<BaseComponent>& System::GetComponent(const uint32_t& entityID)
{
	return m_Component_DataStore[entityID];
}

const std::shared_ptr<BaseComponent>& System::AddComponent(const uint32_t& entityID, const std::shared_ptr<BaseComponent>& component)
{
	m_Component_DataStore[entityID] = component;
	return component;
}

void System::RemoveComponent(const uint32_t& entityID)
{
	m_Component_DataStore.erase(entityID);
}




