#include "Weapon.h"

Weapon::Weapon(World & p_world, const sf::Sprite & p_sprite, const sf::Sprite p_bulletSprite) : m_world(p_world), Entity(p_sprite), m_bulletSprite(p_bulletSprite){}

Weapon::~Weapon(){}

void Weapon::fire(const sf::Vector2<float> & p_position, const float & p_speed, const float & p_angle, const sf::Sprite & p_sprite){
	SceneNode::Ptr bullet(new Bullet(p_position, p_speed, p_angle, p_sprite));
	
	for (int i = 0; i < m_powers.size(); i++)
	{
		for (int j = 0; j < m_powers[i].m_powerFunctions.size(); j++)
		{
			m_powers[i].m_powerFunctions[j]((Bullet*)bullet.get(), m_world);
		}
	}

	m_world.addNode(std::move(bullet));
}

void Weapon::updateSelf(const sf::Time & p_deltaTime){
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		fire((sf::Vector2<float>)sf::Mouse::getPosition(), 1.f, std::atan2f(sf::Mouse::getPosition().y - 720/2, sf::Mouse::getPosition().x - 1280/2), m_bulletSprite);
	}
	for (int i = 0; i < m_powers.size(); i++)
	{
		if (m_powers[i].m_life <= 0)
		{
			m_powers.erase(m_powers.begin() + i);
		}else
		{
			m_powers[i].m_life -= p_deltaTime.asSeconds();
		}
	}
}