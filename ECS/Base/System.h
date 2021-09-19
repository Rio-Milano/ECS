#ifndef SYSTEM_H
#define SYSTEM_H

#include<memory>
#include<list>
#include<unordered_map>
#include"BaseComponent.h"

/*
This is the base class to all of the systems 
*/

//forward decleration of ECS_Engine to fix circular reference 
class ECS_Engine;

class System
{
public:
	//ctors and dtors
	System() = default;
	~System() = default;

	//remove all components from memory
	void ClearComponents();
	
	//Take in a list of components needed for a component update and check if any are invalid
	const bool IsMemoryValid(const std::list<std::shared_ptr<BaseComponent>>& listOfComponentPointers) const;

	//get a component from the component map
	const std::shared_ptr<BaseComponent>& GetComponent(const uint32_t& entityID);

	//add a component to the system map
	const std::shared_ptr<BaseComponent>& AddComponent(const uint32_t& entityID, const std::shared_ptr<BaseComponent>& component);
	
	//Remove a component from the system map
	void RemoveComponent(const uint32_t& entityID);
	
	/*
	Pure Virtual
	*/
	//Puts component back to its default state
	virtual void ResetComponent(const uint32_t& entityID, ECS_Engine& ecs) = 0;
	
	/*
	Virtual
	*/
	//Updates component data
	virtual void UpdateComponent(const uint32_t& entityID, ECS_Engine& ecs) {};


protected:
	//maps entityID to component
	std::unordered_map<uint32_t, std::shared_ptr<BaseComponent>> m_Component_DataStore;


	

};

#endif