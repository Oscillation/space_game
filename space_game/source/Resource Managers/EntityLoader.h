#pragma once
#include "..\Scene\SceneNode.h"
#include "..\Scene\Entity.h"
#include "..\Scene\BackgroundNode.h"
#include "..\Scene\Player\BigShip.h"
#include "ResourceManager.h"

#include <string>
#include <fstream>
#include <iostream>
#include <memory>

class EntityLoader{
public:
	void load(SceneNode* ptr_baseNode, const std::string & p_path, ResourceManager<sf::Texture> & p_resourceManager);
};