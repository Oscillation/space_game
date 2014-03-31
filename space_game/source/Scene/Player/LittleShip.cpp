#include "LittleShip.h"

LittleShip::LittleShip(sf::Sprite const& p_sprite)
	: 
	Entity(p_sprite)
{
	setOrigin(32, 16);
	setPosition(0, 150);
}

LittleShip::~LittleShip()
{
}

void LittleShip::updateSelf(sf::Time const& p_deltaTime)
{
}
