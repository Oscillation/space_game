#pragma once

#include <vector>
#include <memory>

#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\Transformable.hpp>
#include <SFML\System\NonCopyable.hpp>
#include <SFML\System\Time.hpp>

class SceneNode : 
	public sf::Transformable, 
	public sf::Drawable, 
	sf::NonCopyable
{
public:
	typedef std::unique_ptr<SceneNode> Ptr;

public:
	SceneNode();
	virtual ~SceneNode();

	void update(sf::Time const& p_deltaTime);

	void addChild(Ptr p_node);
	Ptr detachChild(SceneNode const& p_node);

	void setParent(SceneNode* p_parent);

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	/*	This is and updateSelf are the only 
		important functions to keep track of.
		They are overridden in a derived class to define that 
		nodes behaviour. 
	*/

	virtual void drawSelf(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual void updateSelf(sf::Time const& p_deltaTime);
	void updateChildren(sf::Time const& p_deltaTime);

private:
	std::vector<Ptr> m_children;
	SceneNode* m_parent;
};