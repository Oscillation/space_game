#include "Bullet.h"

Bullet::Bullet(const sf::Vector2<float> & p_position, const float & p_speed, const float & p_angle, const sf::Sprite & p_sprite){
	setPosition(p_position);
	m_velocity = sf::Vector2f(std::cos(p_angle)*p_speed, std::sin(p_angle)*p_speed);
	m_sprite.setRotation(p_angle);
}

void Bullet::updateSelf(sf::Time const& p_deltaTime){
	move(m_velocity);
}