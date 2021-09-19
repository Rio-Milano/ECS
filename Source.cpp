
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
#include"ECS/MyComponents/CollisionComponent.h"

#include"Window.h"
#define Window Window::Instance_()

#include"memory"


int main()
{





	ECS_Engine ECS;

	//init the player
	const uint32_t playerID = ECS.AddEntity("Player");
	ECS.AddComponent<TransformComponent>(playerID, std::make_shared<TransformComponent>(sf::Vector2f(10.f, 10.f)));
	ECS.AddComponent<CollisionComponent>(playerID, std::make_shared<CollisionComponent>(CollisionComponent::CollisionLayer::Default, 50.f, 50.f));


	//init the enemy
	const uint32_t EnemyID = ECS.AddEntity("Enemy");
	ECS.AddComponent<TransformComponent>(EnemyID, std::make_shared<TransformComponent>(sf::Vector2f(200.f, 200.f), 10.f));
	ECS.AddComponent<CollisionComponent>(EnemyID, std::make_shared<CollisionComponent>(CollisionComponent::CollisionLayer::Default, 100.f, 50.f));

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	sf::RectangleShape rect1;
	rect1.setFillColor(sf::Color(0, 0, 0, 0));
	rect1.setOutlineColor(sf::Color::Blue);
	rect1.setOutlineThickness(1.0f);
	//Rect rect1_{ 10.0f, 10.0f, 50.0f, 50.0f };
	rect1.setPosition(ECS.GetComponent<TransformComponent>(playerID)->position.x, ECS.GetComponent<TransformComponent>(playerID)->position.y);
	rect1.setSize(sf::Vector2f(ECS.GetComponent<CollisionComponent>(playerID)->width, ECS.GetComponent<CollisionComponent>(playerID)->height));

	sf::RectangleShape rect2;
	rect2.setFillColor(sf::Color(0, 0, 0, 0));
	rect2.setOutlineColor(sf::Color::Blue);
	rect2.setOutlineThickness(1.0f);
	//Rect rect2_{ 200.0f, 200.0f, 100.0f, 50.0f };
	rect2.setPosition(ECS.GetComponent<TransformComponent>(EnemyID)->position.x, ECS.GetComponent<TransformComponent>(EnemyID)->position.y);
	rect2.setSize(sf::Vector2f(ECS.GetComponent<CollisionComponent>(EnemyID)->width, ECS.GetComponent<CollisionComponent>(EnemyID)->height));

	const sf::Color isCollidingColor = sf::Color::Red;
	const sf::Color isNotCollidingColor = sf::Color::Green;


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	float dt{ 1.f / 60.f }, et{ 0.f };

	while (Window.Get_Is_Window_Open())
	{
		Window.Update_();

		while (et >= dt)
		{
			//logic
			ECS.UpdateECS();

			float movementSpeed{ 5.0f };


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				ECS.GetComponent<TransformComponent>(playerID)->position.x -= movementSpeed;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				ECS.GetComponent<TransformComponent>(playerID)->position.x += movementSpeed;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				ECS.GetComponent<TransformComponent>(playerID)->position.y -= movementSpeed;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				ECS.GetComponent<TransformComponent>(playerID)->position.y += movementSpeed;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				ECS.GetComponent<TransformComponent>(EnemyID)->position.x -= movementSpeed;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				ECS.GetComponent<TransformComponent>(EnemyID)->position.x += movementSpeed;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				ECS.GetComponent<TransformComponent>(EnemyID)->position.y -= movementSpeed;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				ECS.GetComponent<TransformComponent>(EnemyID)->position.y += movementSpeed;

			rect1.setPosition(ECS.GetComponent<TransformComponent>(playerID)->position.x, ECS.GetComponent<TransformComponent>(playerID)->position.y);
			rect2.setPosition(ECS.GetComponent<TransformComponent>(EnemyID)->position.x, ECS.GetComponent<TransformComponent>(EnemyID)->position.y);

			if (std::find(ECS.GetComponent<CollisionComponent>(playerID)->m_listOfEntityIDsColliding.begin(), 
					ECS.GetComponent<CollisionComponent>(playerID)->m_listOfEntityIDsColliding.end(), EnemyID)
					!= 
					ECS.GetComponent<CollisionComponent>(playerID)->m_listOfEntityIDsColliding.end())
				
				rect1.setOutlineColor(isCollidingColor);
			else
				rect1.setOutlineColor(isNotCollidingColor);

			if(std::find(ECS.GetComponent<CollisionComponent>(EnemyID)->m_listOfEntityIDsColliding.begin(),
					ECS.GetComponent<CollisionComponent>(EnemyID)->m_listOfEntityIDsColliding.end(), playerID)
					!= 
					ECS.GetComponent<CollisionComponent>(EnemyID)->m_listOfEntityIDsColliding.end())
				
				rect2.setOutlineColor(isCollidingColor);
			else
				rect2.setOutlineColor(isNotCollidingColor);



			et -= dt;
		}

		Window.Render_Window_Entity_(rect1);
		Window.Render_Window_Entity_(rect2);
			//Window.Render_Window_Entity_(ECS.GetComponent<SpriteComponent>(playerID)->sprite);


		Window.Render_();


	//update et
		Window.Set_Elapsed_Time_();
		et += Window.Get_Elapsed_Time();
	



	}
		return 0;
}






