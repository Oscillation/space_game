#include "BigShip.h"

BigShip::BigShip(const sf::Sprite & p_sprite) : Entity(p_sprite), m_velocity(5, 0){

}

BigShip::~BigShip(){}

void BigShip::updateSelf(const sf::Time & p_deltaTime){
	move(m_velocity);
}