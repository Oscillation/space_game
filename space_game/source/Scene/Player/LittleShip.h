#pragma once
#include "..\Entity.h"

#include <SFML\Window\Mouse.hpp>

static const float m_terminal_velocity = 3.f;

class LittleShip : public Entity
{
public:
	LittleShip(sf::Sprite& p_sprite);
	~LittleShip();

	void updateSelf(sf::Time const& p_deltaTime);

private:
	float m_velocity;
};