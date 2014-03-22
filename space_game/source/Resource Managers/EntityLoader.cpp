#include "EntityLoader.h"

void EntityLoader::load(SceneNode* ptr_baseNode, const std::string & p_path){
	std::ifstream entityFile;
	entityFile.open(p_path);
	std::string line;
	while (std::getline(entityFile, line))
	{
		SceneNode::Ptr node;
		int index[2] = {line.find_first_of(' '), line.find_last_of(' ')};

		std::string tag = line.substr(0, index[0]);
		std::string type = line.substr(index[0], index[1]);
		std::string parent_tag = line.substr(index[1]);

		ptr_baseNode->getChild(parent_tag)->addChild(std::move(node));
	}
}