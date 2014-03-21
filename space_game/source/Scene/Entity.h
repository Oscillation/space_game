#pragma once

#include "SceneNode.h"

class Entity : public SceneNode
{
public:
	Entity();
	virtual ~Entity();

	void updateSelf(sf::Time const& p_deltaTime);

	void drawSelf(sf::RenderTarget& target, sf::RenderStates states) const;
};