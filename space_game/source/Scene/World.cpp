#include "World.h"

#include <SFML\Graphics\RenderStates.hpp>
#include <SFML\Graphics\RenderTarget.hpp>

World::World()
	:
	baseNode(new SceneNode())
{
}

World::~World()
{

}

void World::addNode(SceneNode::Ptr& p_node)
{
	baseNode->addChild(std::move(p_node));
}

SceneNode* World::getNode(std::string const& p_tag) const
{
	return baseNode->getChild(p_tag);
}

void World::update(sf::Time const& p_deltaTime)
{
	baseNode->update(p_deltaTime);
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*baseNode, states);
}

void World::handleCollisions()
{

}