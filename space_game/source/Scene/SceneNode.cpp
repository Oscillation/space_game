#include "SceneNode.h"
#include <iostream>
SceneNode::SceneNode()
	:
	m_children(),
	m_parent(nullptr),
	m_delete(false)
{
}

SceneNode::~SceneNode()
{
}

void SceneNode::update(sf::Time const& p_deltaTime)
{
	updateSelf(p_deltaTime);
	updateChildren(p_deltaTime);
}

void SceneNode::addChild(Ptr p_node)
{
	p_node->setParent(this);
	m_children.push_back(std::move(p_node));
}

SceneNode::Ptr SceneNode::detachChild(SceneNode const& p_node)
{
	auto found = std::find_if(m_children.begin(), m_children.end(), 
		[&] (Ptr& p) -> bool { return p.get() == &p_node; });

	Ptr result = std::move(*found);
	result->setParent(nullptr);
	m_children.erase(found);
	return result;
}

void SceneNode::setParent(SceneNode* p_parent)
{
	m_parent = p_parent;
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	drawSelf(target, states);

	for (auto i = m_children.begin(); i != m_children.end(); ++i)
	{
		(*i)->draw(target, states);
	}
}

void SceneNode::drawSelf(sf::RenderTarget& target, sf::RenderStates states) const
{
}

void SceneNode::updateSelf(sf::Time const& p_deltaTime)
{
}

void SceneNode::updateChildren(sf::Time const& p_deltaTime)
{
	for (auto i = m_children.begin(); i != m_children.end(); ++i)
	{
		if ((*i)->getDelete())
		{
			detachChild(*(*i));
			i = m_children.begin();
		}
	}
	const int size = m_children.size();
	for (unsigned int i = 0; i < size; i++)
	{
		m_children[i]->update(p_deltaTime);
	}
}

std::string SceneNode::getTag() const{
	return m_tag;
}

SceneNode* SceneNode::getChild(std::string p_tag) const{
	SceneNode* result = nullptr;
	if (m_tag == p_tag)
	{
		result = (SceneNode*)(this);
		return result;
	}else
	{
		for (int i = 0; i < m_children.size(); i++)
		{
			if (m_children[i]->getChild(p_tag) != nullptr)
			{
				result = m_children[i]->getChild(p_tag);
				return result;
			}
		}
	}
	return nullptr;
	/*for (int i = 0; i < m_children.size(); i++)
	{
		if (std::strcmp(p_tag.c_str(), m_children[i].get()->getTag().c_str()) == 0)
		{
			return m_children[i].get();
		}
		m_children[i].get()->getChild(p_tag, p_baseTag);
	}
	if (!p_tag.compare(p_baseTag))
	{
		return nullptr;
	}*/
}

void SceneNode::setTag(const std::string & p_tag){
	m_tag = p_tag;
}

sf::Transform SceneNode::getWorldTransform() const
{
	sf::Transform result = sf::Transform::Identity;
	for (const SceneNode* node = this; node != nullptr; node = node->m_parent){
		result *= node->getTransform();
	}
	return result;
}

sf::Vector2f SceneNode::getWorldPosition() const
{
	return getWorldTransform() * sf::Vector2f();
}

sf::FloatRect SceneNode::getBoundingRect() const
{
	return getWorldTransform().transformRect(sf::FloatRect());
}

void SceneNode::handleCollision(SceneNode::Ptr& p_other)
{
}

bool SceneNode::getDelete() const{
	return m_delete;
}