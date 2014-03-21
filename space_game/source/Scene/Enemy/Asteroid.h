#include "../Entity.h"

class Asteroid : public Entity
{
public:
	Asteroid(sf::Sprite& p_sprite, sf::Vector2f p_velocity, float p_rotationSpeed);
	~Asteroid();

	void updateSelf(sf::Time const& p_deltaTime);

private:
	sf::Vector2f m_velocity;
	float m_rotationSpeed;
};