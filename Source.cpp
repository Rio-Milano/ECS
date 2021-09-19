
//base tech
#include"ECS/Base/ECS_Engine.h"

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
#include"ECS/MyComponents/KeyboardMovementSystemComponent.h"

#include"Window.h"
#define Window Window::Instance_()

#include"memory"


int main()
{
	ECS_Engine ECS;

	//init the player
	const uint32_t playerID = ECS.AddEntity("Player");

	ECS.AddComponent<HealthComponent>(playerID, std::make_shared<HealthComponent>());
	ECS.AddComponent<TransformComponent>(playerID, std::make_shared<TransformComponent>());
	ECS.AddComponent<SpriteComponent>(playerID, std::make_shared<SpriteComponent>());
	ECS.AddComponent<KeyboardMovementSystemComponent>(playerID, std::make_shared<KeyboardMovementSystemComponent>());

	sf::Texture txt;
	txt.loadFromFile("DEMO.png");
	ECS.GetComponent<SpriteComponent>(playerID)->sprite.setTexture(txt);

	ECS.GetComponent<KeyboardMovementSystemComponent>(playerID)->x_velocity = 1.0f;
	ECS.GetComponent<KeyboardMovementSystemComponent>(playerID)->y_velocity = 1.0f;


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	float dt{ 1.f / 60.f }, et{ 0.f };

	while (Window.Get_Is_Window_Open())
	{
		Window.Update_();

		while (et >= dt)
		{
			//logic
			ECS.UpdateECS();


			et -= dt;
		}


			Window.Render_Window_Entity_(ECS.GetComponent<SpriteComponent>(playerID)->sprite);


		Window.Render_();


	//update et
		Window.Set_Elapsed_Time_();
		et += Window.Get_Elapsed_Time();
	



	}
		return 0;
}






