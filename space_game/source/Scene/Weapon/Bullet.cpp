#include "Bullet.h"
#include <iostream>

Bullet::Bullet(const sf::Vector2<float> & p_position, const float & p_speed, const float & p_angle, const sf::Sprite & p_sprite) : Entity(p_sprite), m_angle(p_angle){
	setPosition(p_position);
	m_velocity = sf::Vector2f(std::cos(p_angle)*p_speed, std::sin(p_angle)*p_speed);
}

void Bullet::updateSelf(sf::Time const& p_deltaTime){
	//std::cout << getPosition().x << " : " << getPosition().y << "\n";
	move(m_velocity);
}