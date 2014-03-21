#pragma once

#include "..\Entity.h"

class BigShip : public Entity{
private:
	sf::Vector2<float> m_velocity;

public:
	void updateSelf(const sf::Time & p_deltaTime);
};