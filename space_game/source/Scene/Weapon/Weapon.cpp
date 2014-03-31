#include "Weapon.h"

Weapon::Weapon(World & p_world, const sf::Sprite & p_sprite, const sf::Sprite p_bulletSprite) : m_world(p_world), Entity(p_sprite), m_bulletSprite(p_bulletSprite), m_delay(.2f), m_time(0){
	m_powers.push_back(Power(test));
}

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

	m_time = 0;
}

void Weapon::updateSelf(const sf::Time & p_deltaTime){
	m_time += p_deltaTime.asSeconds();
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_time >= m_delay)
	{
		fire(getWorldPosition(), 10.f, std::atan2f(sf::Mouse::getPosition().y, sf::Mouse::getPosition().x), m_bulletSprite);
	}
	/*for (int i = 0; i < m_powers.size(); i++)
	{
		if (m_powers[i].m_life <= 0)
		{
			m_powers.erase(m_powers.begin() + i);
		}else
		{
			m_powers[i].m_life -= p_deltaTime.asSeconds();
		}
	}*/
}