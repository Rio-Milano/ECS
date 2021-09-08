#ifndef ECS_ENGINE_H
#define ECS_ENGINE_H

//<> includes
#include<memory>
#include<unordered_map>
#include<vector>

//"" includes
#include"System.h"
#include"../MySystems/HealthSystem.h"
#include"../MySystems/KeyboardMovementSystem.h"
#include"../MySystems/MovementSystem.h"
#include"../MySystems/SpriteSystem.h"
#include"../MySystems/TransformSystyem.h"

/*
This class is the interface to the ECS design 
*/

class ECS_Engine
{
public:

	//singleton retrival method
	static ECS_Engine& Get_Instance();

	//makes a new entity and returns its ID
	const uint32_t& Add_Entity_To_DataStore(const std::string& Entity_Name);

	//retrives entities
	const uint32_t& Get_Entity_By_Name(const std::string& Entity_Name);

	//update each entities components 
	void Update_ECS_Engine();

	//all systems held here
	struct Systems
	{
		Systems() = default;
		~Systems() = default;

		//creating each system
		std::shared_ptr<HealthSystem> m_HealthSystem{std::make_shared<HealthSystem>()};
		std::shared_ptr<KeyboardMovementSystem> m_KeyboardMovementSystem{ std::make_shared<KeyboardMovementSystem>() };
		std::shared_ptr<MovementSystem> m_MovementSystem{ std::make_shared<MovementSystem>() };
		std::shared_ptr<SpriteSystem> m_SpriteSystem{ std::make_shared<SpriteSystem>() };
		std::shared_ptr<TransformSystem> m_TransformSystem{ std::make_shared<TransformSystem>() };

		//adding the systems created to a polymorphic list

		std::vector<std::shared_ptr<System>> m_systemList	{
																m_HealthSystem,
																m_KeyboardMovementSystem,
																m_MovementSystem,
																m_SpriteSystem,
																m_TransformSystem 
															};		
	} m_systems{};//creating the systems

private:
	ECS_Engine();
	~ECS_Engine() = default;

	//allways set to the ID of the next entity to be made
	uint32_t m_nextEntityID{0};

	//binds the name of an entity to its ID which can be cross referanced in numerous systems for components 
	std::unordered_map<std::string, uint32_t> m_ECS_Entity_DataStore;


};


#endif