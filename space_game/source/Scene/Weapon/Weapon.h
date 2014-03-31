#pragma once
#include "..\Entity.h"
#include "Bullet.h"
#include "Power.h"
#include "..\World.h"
#include <SFML\Window\Mouse.hpp>

class Weapon : public Entity{
public:
	Weapon(World & p_world, const sf::Sprite & p_sprite, const sf::Sprite p_bulletSprite);
	~Weapon();

	void fire(const sf::Vector2<float> & p_position, const float & p_speed, const float & p_angle, const sf::Sprite & p_sprite);
	void updateSelf(const sf::Time & p_deltaTime);

protected:

	///<summary> Time between bullets fired.</summary>
	float m_delay, m_time;
	World & m_world;
	std::vector<Power> m_powers;
	sf::Sprite m_bulletSprite;
};