#pragma once
#include <SFML\Graphics\Transformable.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include "..\Entity.h"

struct Bullet : public Entity{
	Bullet(const sf::Vector2<float> & p_position, const float & p_speed, const float & p_angle, const sf::Sprite & p_sprite);
	sf::Vector2<float> m_velocity;

	void updateSelf(sf::Time const& p_deltaTime);
};