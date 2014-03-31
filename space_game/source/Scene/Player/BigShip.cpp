#include "BigShip.h"

BigShip::BigShip(const sf::Sprite & p_sprite) 
	: 
	Entity(p_sprite), m_velocity(0.5f, 0.f)
{
	setOrigin(64, 32);
	setPosition(0, 360);
}

BigShip::~BigShip(){}

void BigShip::updateSelf(const sf::Time & p_deltaTime)
{
	//move(m_velocity);
	SceneNode* empty = getChild("empty");
	if (empty) {
		empty->rotate(1);
		empty->setPosition(getOrigin());
	}
}