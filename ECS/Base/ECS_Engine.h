#ifndef ECS_ENGINE_H
#define ECS_ENGINE_H

#include<memory>
#include<unordered_map>
#include<typeindex>
#include<vector>
#include"System.h"


/*
This class is the interface to the ECS design pattern
*/

class ECS_Engine
{
public:

	//ctors and dtors
	ECS_Engine();
	~ECS_Engine() = default;


	/*
	Entity Methods
	*/
	const uint32_t& AddEntity(const std::string& entityName);
	const uint32_t& GetEntity(const std::string& entityName);


	/*
	Component Methods
	*/
	//gets typeid of template type, does a search on the system map, validates system, searches system for component then casts to template type
	template<class T>
	const std::shared_ptr<T> GetComponent(const uint32_t& entityID);

	//gets typeid of template, does a search in system map, valdates system, adds component to system, casts the return value to the template type
	template<class T> 
	std::shared_ptr<T> AddComponent(const uint32_t& entityID, const std::shared_ptr<BaseComponent>& component);


	/*
	ECS Main
	*/
	//update each entities components 
	void UpdateECS();

	/*
	TEMP -- DELETE
	//demo function as rendering system is not build so currently used to get sprite system to render from source.cpp
	*/
	template<class T>
	std::shared_ptr<T> getSystemFromTypeIdOfComposition(const std::type_index& typeIndexOfComponent);


private:
	//allways set to the ID of the next entity to be made
	uint32_t m_nextEntityID{0};

	//binds the name of an entity to its ID which can be cross referanced in numerous systems for components 
	std::unordered_map<std::string, uint32_t> m_ECS_Entity_DataStore;
	//binds the type index of components to the system that holds them
	std::unordered_map<std::type_index, std::shared_ptr<System>> m_ECS_System_DataStore;




};





#endif

template<class T>
inline const std::shared_ptr<T> ECS_Engine::GetComponent(const uint32_t& entityID)
{
	//get the typeid of the template type and search for a system under that type
	std::shared_ptr<System> system = m_ECS_System_DataStore[typeid(T)];

	//if a system has been found
	if (system)//retrieve the component from that system
		return std::static_pointer_cast<T>(system->GetComponent(entityID));

	return nullptr;
}

template<class T>
inline std::shared_ptr<T> ECS_Engine::AddComponent(const uint32_t& entityID, const std::shared_ptr<BaseComponent>& component)
{
	//get system pointer
	std::shared_ptr<System> system = m_ECS_System_DataStore[typeid(T)];

	//if system valid
	if (system)//return system casted to type of template
		return std::static_pointer_cast<T>(system->AddComponent(entityID, component));

	return nullptr;
}

template<class T>
inline std::shared_ptr<T> ECS_Engine::getSystemFromTypeIdOfComposition(const std::type_index& typeIndexOfComponent)
{
	return std::static_pointer_cast<T>(m_ECS_System_DataStore[typeIndexOfComponent]);
}