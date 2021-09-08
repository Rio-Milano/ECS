#ifndef SYSTEM_H
#define SYSTEM_H

//<> includes
#include<memory>//gives use to uint32_t
#include<list>//gives use to hash map
#include<unordered_map>

//""includes
#include"BaseComponent.h"//using polymorphic design in which we store components and cast down hirearchy when access is needed

/*
This class is used as a template for on-demand created systems and also to make use of polymorphism to make
updating all systems efficient 
*/

class System
{
public:

	System() = default;
	~System() = default;

	/*
	* INHERITED FUNCTIONS
	*/
	//clears the data store of the system
	void Hard_Reset_System();
	
	//retrives the data store of the system
	std::unordered_map<uint32_t, std::shared_ptr<BaseComponent>>& Get_Data_Store();

	//used to check the validity of related components 
	const bool Is_Memory_Vaid(const std::list<std::shared_ptr<BaseComponent>>& Pointer_List);

	//gets a component from a system
	const std::shared_ptr<BaseComponent>& Get_Component(const uint32_t& Entity);

	//adds a component to a system
	const std::shared_ptr<BaseComponent>& Add_Component(const uint32_t& Entity, const std::shared_ptr<BaseComponent>& Component);
	
	/*
	PURE VIRTUAL
	*/
	//sets a component to its default state
	virtual void Reset_Component(const uint32_t& Entity) = 0;
	

	/*
	VIRTUAL
	*/
	virtual void Update_Component(const uint32_t& Entity) {};


protected:
	std::unordered_map<uint32_t, std::shared_ptr<BaseComponent>> m_System_DataStore;


	

};

#endif