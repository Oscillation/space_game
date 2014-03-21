#pragma once
#include "Entity.h"

struct BackgroundNode : public Entity{
	BackgroundNode(const sf::Sprite & p_sprite);
	void updateSelf(const sf::Time & p_deltaTime);
};