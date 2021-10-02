#include"AnimationSystem.h"
#include"../Base/ECS_Engine.h"
#include"../MyComponents/AnimationComponent.h"
#include"../MyComponents/SpriteComponent.h"
#include"../../Window.h"
#define Window Window::Instance_()
#include"../../TextureManager.h"
#define TextureManager TextureManager::Instance_()


void AnimationSystem::ResetComponent(const uint32_t& entityID, ECS_Engine& ecs)
{
}

void AnimationSystem::UpdateComponent(const uint32_t& entityID, ECS_Engine& ecs)
{
	auto animationComponent = ecs.GetComponent<AnimationComponent>(entityID);
	auto spriteComponent = ecs.GetComponent<SpriteComponent>(entityID);

	if (animationComponent->elapsed >= animationComponent->speed)
	{
		animationComponent->elapsed -= animationComponent->speed;
		spriteComponent->sprite.setTexture(TextureManager.Get_Texture_(m_animationDataStore[animationComponent->m_animation_name].first));
		spriteComponent->sprite.setTextureRect(m_animationDataStore[animationComponent->m_animation_name].second[animationComponent->m_animationFrame]);
		animationComponent->m_animationFrame = (animationComponent->m_animationFrame + 1) % (m_animationDataStore[animationComponent->m_animation_name].second.size());
	}
	animationComponent->elapsed += Window.Get_Elapsed_Time();
}

void AnimationSystem::AddAnimationFromSpriteSheet(const std::string& textureName, const std::string& animationName, const int& animationsOnXAxis, const int& animationsOnYAxis, const int& startFrameXIndex, const int& StartFrameYIndex, const int& frameCount)
{
	const sf::Texture& animationSheet = TextureManager.Get_Texture_(textureName);

	int animationWidth = animationSheet.getSize().x / animationsOnXAxis;
	int animationHeight = animationSheet.getSize().y / animationsOnYAxis;

	m_animationDataStore[animationName].first = textureName;

	int createdFrames = 0;

	for (int y = StartFrameYIndex * animationHeight; y < (int)animationSheet.getSize().y; y += animationHeight)
	{
		for (int x = StartFrameYIndex * animationWidth; x < (int)animationSheet.getSize().x; x += animationWidth)
		{
			if (++createdFrames < frameCount)
				m_animationDataStore[animationName].second.emplace_back(sf::IntRect(x, y, animationWidth, animationHeight));
			else
				return;
		}
	}


}
