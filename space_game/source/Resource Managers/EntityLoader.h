#pragma once
#include "..\Scene\SceneNode.h"
#include "..\Scene\Entity.h"
#include "..\Scene\BackgroundNode.h"
#include "..\Scene\Player\BigShip.h"
#include "..\Scene\Player\LittleShip.h"
#include "..\Scene\World.h"
#include "..\Scene\Weapon\Weapon.h"
#include "ResourceManager.h"

#include <string>
#include <fstream>
#include <iostream>
#include <memory>

class EntityLoader{
public:
	void load(World & p_world, const std::string & p_path, ResourceManager<sf::Texture> & p_resourceManager);
};