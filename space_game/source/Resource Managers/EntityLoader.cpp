#include "EntityLoader.h"

#include "../Scene/EmptyNode.h"

void EntityLoader::load(World& p_world, const std::string & p_path, ResourceManager<sf::Texture> & p_resourceManager){
	std::ifstream entityFile;
	entityFile.open(p_path);
	std::string line;
	while (std::getline(entityFile, line))
	{
		int index[2] = {line.find_first_of(' '), line.find_last_of(' ')};

		std::string tag = line.substr(0, index[0]);
		std::string type = line.substr(index[0] + 1, index[1] - index[0] - 1);
		std::string parent_tag = line.substr(index[1] + 1);

		sf::Sprite sprite;
		if (tag != "empty") { // Check for spriteless entities here
			sprite.setTexture(*p_resourceManager.get(tag));
		}

		SceneNode::Ptr node;

		if (type == "BackgroundNode") {
			node = SceneNode::Ptr(new BackgroundNode(sprite));
		} else if (type == "BigShip") {
			node = SceneNode::Ptr(new BigShip(sprite));
		} else if (type == "LittleShip") {
			node = SceneNode::Ptr(new LittleShip(sprite));
		} else if (type == "EmptyNode") {
			node = SceneNode::Ptr(new EmptyNode());
		} else if (type == "Weapon") {
			sf::Sprite bullet;
			bullet.setTexture(*p_resourceManager.get("bullet"));
			node = SceneNode::Ptr(new Weapon(p_world, sprite, bullet));
		}

		node->setTag(tag);
		if (parent_tag != "null")
		{
			p_world.getNode(parent_tag)->addChild(std::move(node));
		} else
		{
			p_world.addNode(std::move(node));
		}

		std::cout << tag << " " << sprite.getGlobalBounds().width << " : " << sprite.getGlobalBounds().height << std::endl;
	}

	entityFile.close();
}