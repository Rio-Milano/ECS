#include "System.h"


void System::Hard_Reset_System()
{
	m_System_DataStore.clear();
}

std::unordered_map<uint32_t, std::shared_ptr<BaseComponent>>& System::Get_Data_Store()
{
	return m_System_DataStore;
}

const bool System::Is_Memory_Vaid(const std::list<std::shared_ptr<BaseComponent>>& Pointer_List)
{
	for (auto i : Pointer_List)
		if (!i) return false;
	return true;
}

const std::shared_ptr<BaseComponent>& System::Get_Component(const uint32_t& Entity)
{
	return m_System_DataStore[Entity];
}

const std::shared_ptr<BaseComponent>& System::Add_Component(const uint32_t& Entity, const std::shared_ptr<BaseComponent>& Component)
{
	m_System_DataStore[Entity] = Component;
	return Component;
}



