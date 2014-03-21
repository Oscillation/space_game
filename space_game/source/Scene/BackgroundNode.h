#pragma once
#include "Entity.h"

class BackgroundNode : public Entity{
public:
	BackgroundNode(const sf::Sprite & p_sprite);
	void updateSelf(const sf::Time & p_deltaTime);
};