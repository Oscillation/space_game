#pragma once

#include <vector>
#include <algorithm>
#include <memory>
#include <string>

#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\Transformable.hpp>
#include <SFML\System\NonCopyable.hpp>
#include <SFML\System\Time.hpp>
#include <SFML\Graphics\View.hpp>

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

	SceneNode* getChild(std::string p_tag) const;
	std::string getTag() const;
	void setTag(const std::string & p_tag);

	sf::Transform getWorldTransform() const;
	sf::Vector2f getWorldPosition() const;

	virtual sf::FloatRect getBoundingRect() const;

	virtual void handleCollision(SceneNode::Ptr& p_other);

	bool getDelete() const;

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual void drawSelf(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual void updateSelf(sf::Time const& p_deltaTime);
	void updateChildren(sf::Time const& p_deltaTime);

private:
	std::vector<Ptr> m_children;
	SceneNode* m_parent;

	std::string m_tag;

protected:
	bool m_delete;
};