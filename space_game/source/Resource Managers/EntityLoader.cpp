#include "EntityLoader.h"

void EntityLoader::load(SceneNode* ptr_baseNode, const std::string & p_path, ResourceManager<sf::Texture> & p_resourceManager){
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
		sprite.setTexture(*p_resourceManager.get(tag));

		SceneNode::Ptr node;
		if (type == "BackgroundNode")
		{
			node = SceneNode::Ptr(new BackgroundNode(sprite));
		}else if (type == "BigShip")
		{
			node = SceneNode::Ptr(new BigShip(sprite));
		}else if (type == "LittleShip")
		{
			node = SceneNode::Ptr(new LittleShip(sprite));
		}
		node->setTag(tag);
		if (parent_tag != "null")
		{
			ptr_baseNode->getChild(parent_tag)->addChild(std::move(node));
		}else
		{
			ptr_baseNode->addChild(std::move(node));
		}
	}
}