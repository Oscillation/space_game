#pragma once
#include "..\Entity.h"

class LittleShip : public Entity
{
public:
	LittleShip(const sf::Sprite & p_sprite);
	~LittleShip();

	void updateSelf(sf::Time const& p_deltaTime);
};