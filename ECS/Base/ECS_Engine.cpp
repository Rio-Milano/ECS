#include "ECS_Engine.h"

#include"../MySystems/HealthSystem.h"
#include"../MySystems/KeyboardMovementSystem.h"
#include"../MySystems/SpriteSystem.h"
#include"../MySystems/TransformSystyem.h"

ECS_Engine::ECS_Engine()
{

}



ECS_Engine& ECS_Engine::Get_Instance()
{
	static ECS_Engine ECS_Engine_Instance;
	return ECS_Engine_Instance;
}


const uint32_t& ECS_Engine::Add_Entity_To_DataStore(const std::string& Entity_Name)
{
	//create new ID and increate next ID
	const uint32_t newEntityID = m_nextEntityID++;
	//add entity to hash map
	m_ECS_Entity_DataStore[Entity_Name] = newEntityID;
	//return new entity
	return m_ECS_Entity_DataStore[Entity_Name];
}

const uint32_t& ECS_Engine::Get_Entity_By_Name(const std::string& Entity_Name)
{
	return m_ECS_Entity_DataStore[Entity_Name];
}



#include<iostream>
void ECS_Engine::Update_ECS_Engine()
{
	//if an update component call throws exception it can be caught 
	try {
		//loop through all entities
		for (const auto& Entity : m_ECS_Entity_DataStore)
		{
			//loop through all systems
			for (auto& System : m_systems.m_systemList)
			{
				//if entity has a component in the system then update it
				if (System->Get_Component(Entity.second))
					System->Update_Component(Entity.second);
			}
		}
	}
	catch (std::string& e)
	{
		std::cout << "Error: " << e;
		return;
	}
}
