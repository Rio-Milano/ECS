

#include "ECS_Engine.h"

#include"../MySystems/HealthSystem.h"
#include"../MySystems/KeyboardMovementSystem.h"
#include"../MySystems/SpriteSystem.h"
#include"../MySystems/TransformSystyem.h"
#include"../MySystems/MovementSystem.h"

#include"../MyComponents/HealthComponent.h"
#include"../MyComponents/KeyboardMovementSystemComponent.h"
#include"../MyComponents/SpriteComponent.h"
#include"../MyComponents/TransformComponent.h"
#include"../MyComponents/MovementComponent.h"

#include<iostream>

ECS_Engine::ECS_Engine()
{
#pragma region ECS Defined Systems
	//add each component type id to the system container mapped to the system that holds it
	m_ECS_System_DataStore[typeid(TransformComponent)] = std::make_shared<TransformSystem>();
	m_ECS_System_DataStore[typeid(SpriteComponent)] = std::make_shared<SpriteSystem>();
	m_ECS_System_DataStore[typeid(KeyboardMovementSystemComponent)] = std::make_shared<KeyboardMovementSystem>();
	m_ECS_System_DataStore[typeid(MovementComponent)] = std::make_shared<MovementSystem>();
#pragma endregion

#pragma region User Defined Systems
	m_ECS_System_DataStore[typeid(HealthComponent)] = std::make_shared<HealthSystem>();
#pragma endregion
}



const uint32_t& ECS_Engine::AddEntity(const std::string& entityName)
{
	//create new ID and increate next ID
	const uint32_t newEntityID = m_nextEntityID++;
	//add entity to hash map
	m_ECS_Entity_DataStore[entityName] = newEntityID;
	//return new entity
	return m_ECS_Entity_DataStore[entityName];
}

const uint32_t& ECS_Engine::GetEntity(const std::string& entityName)
{
	return m_ECS_Entity_DataStore[entityName];
}


	
void ECS_Engine::UpdateECS()
{
	//if an update component call throws exception it can be caught 
	try {
		//loop through all entities
		for (const auto& Entity : m_ECS_Entity_DataStore)
		{
			//loop through all systems
			for (auto& System : m_ECS_System_DataStore)
			{
				//if system is valid
				if (System.second)
				{
					//if system contains entity
					if(System.second->GetComponent(Entity.second))
						//update entity componenent 
						System.second->UpdateComponent(Entity.second, *this);
				}
			}
		}
	}
	catch (std::string& e)
	{
		std::cout << "Error: " << e;
		return;
	}
}
