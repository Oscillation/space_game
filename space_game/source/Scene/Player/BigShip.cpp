#include "BigShip.h"

BigShip::BigShip(const sf::Sprite & p_sprite) : Entity(p_sprite), m_velocity(3, 0.5f){
	setOrigin(128, 64);
	setPosition(0, 360);
}

BigShip::~BigShip(){}

void BigShip::updateSelf(const sf::Time & p_deltaTime){
	move(m_velocity);
}