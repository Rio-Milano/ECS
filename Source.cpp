

//base tech
#include"ECS/Base/ECS_Engine.h"
#define ECS ECS_Engine::Get_Instance()

//systems
#include"ECS/Base/System.h"
#include"ECS/MySystems/TransformSystyem.h"
#include"ECS/MySystems/SpriteSystem.h"
#include"ECS/MySystems/KeyboardMovementSystem.h"
#include"ECS/MySystems/HealthSystem.h"

//components
#include"ECS/MyComponents/TransformComponent.h"
#include"ECS/MyComponents/SpriteComponent.h"
#include"ECS/MyComponents/MovementComponent.h"	
#include"ECS/MyComponents/HealthComponent.h"

#include"Window.h"
#define Window Window::Instance_()

#include"memory"



#include<iostream>

//having 32 bits for entities allows us to store upto 2^32 ids

int main()
{
	//move to static pointer cast

	//init the player
	const uint32_t PlayerID = ECS.Add_Entity_To_DataStore("Player");

	ECS.m_systems.m_HealthSystem->Add_Component(PlayerID, std::make_shared<HealthComponent>());

	ECS.m_systems.m_TransformSystem->Add_Component(PlayerID, std::make_shared<TransformComponent>());
	

	std::shared_ptr<SpriteComponent> Player_Sprite_Comp = std::make_shared<SpriteComponent>();
	sf::Texture txt;
	txt.loadFromFile("DEMO.png");
	Player_Sprite_Comp->sprite.setTexture(txt);
	ECS.m_systems.m_SpriteSystem->Add_Component(PlayerID, Player_Sprite_Comp);

	std::shared_ptr<MovementComponent> player_movement_comp = std::make_shared<MovementComponent>();
	player_movement_comp->x_velocity = 1.0f;
	player_movement_comp->y_velocity = 1.0f;
	ECS.m_systems.m_KeyboardMovementSystem->Add_Component(PlayerID, player_movement_comp);


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	float dt{ 1.f / 60.f }, et{ 0.f };

	while (Window.Get_Is_Window_Open())
	{
		Window.Update_();

		while (et >= dt)
		{
			//logic
			ECS.Update_ECS_Engine();


			et -= dt;
		}



		for (std::unordered_map<uint32_t, std::shared_ptr<BaseComponent>>::iterator Sprite = ECS.m_systems.m_SpriteSystem->Get_Data_Store().begin();
			Sprite != ECS.m_systems.m_SpriteSystem->Get_Data_Store().end(); Sprite++)
		{

			Window.Render_Window_Entity_(static_cast<SpriteComponent*>(Sprite->second.get())->sprite);
		}

		Window.Render_();


	//update et
		Window.Set_Elapsed_Time_();
		et += Window.Get_Elapsed_Time();
	



	}
		return 0;
}






