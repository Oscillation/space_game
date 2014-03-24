#pragma once

#include <SFML\System\NonCopyable.hpp>
#include <SFML\System\Time.hpp>
#include <SFML\Graphics\Drawable.hpp>

#include "SceneNode.h"

class World : 
	private sf::NonCopyable,
	public sf::Drawable
{
public:
	World();
	~World();

	void addNode(SceneNode::Ptr& p_node);
	SceneNode* getNode(std::string const& p_tag) const;

	void update(sf::Time const& p_deltaTime);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	SceneNode::Ptr baseNode;
};