#include "LittleShip.h"

LittleShip::LittleShip(sf::Sprite& p_sprite)
	:
	Entity(p_sprite)
{
	setPosition(0, 50);
}

LittleShip::~LittleShip()
{
}

void LittleShip::updateSelf(sf::Time const& p_deltaTime)
{
}