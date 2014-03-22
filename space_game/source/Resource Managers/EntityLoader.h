#pragma once
#include "..\Scene\SceneNode.h"
#include "..\Scene\Entity.h"
#include "..\Scene\BackgroundNode.h"

#include <string>
#include <fstream>
#include <iostream>

class EntityLoader{
public:
	void load(SceneNode* ptr_baseNode, const std::string & p_path);

private:
	SceneNode::Ptr load(const std::string & p_properties);
};