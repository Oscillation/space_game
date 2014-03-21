#pragma once

#include "..\Entity.h"

class BigShip : public Entity{
public:
	BigShip(const sf::Sprite & p_sprite);
	~BigShip();

	void updateSelf(const sf::Time & p_deltaTime);
private:
	sf::Vector2<float> m_velocity;

};