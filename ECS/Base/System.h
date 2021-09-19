#ifndef SYSTEM_H
#define SYSTEM_H

#include<memory>
#include<list>
#include<unordered_map>
#include"BaseComponent.h"
#include"ComponentEngine.h"

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

	//get the component engine
	ComponentEngine& GetComponentEngine();


protected:
	ComponentEngine m_componentEngine;


	

};

#endif