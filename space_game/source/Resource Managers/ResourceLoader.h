#pragma once

#include "ResourceManager.h"

#include <SFML\System\NonCopyable.hpp>

#include <string>
#include <fstream>

class ResourceLoader : private sf::NonCopyable
{
public:
	ResourceLoader();
	~ResourceLoader();

	template <class T>
	bool load(ResourceManager<T>& p_manager, std::string p_path) // FUCKING TEMPLATES
	{
		std::ifstream resourceFile;
		resourceFile.open(p_path);
		std::string line;

		bool success;

		while (std::getline(resourceFile, line))
		{
			size_t seperator = line.find(" ");
			success = p_manager.load(line.substr(0, seperator), line.substr(seperator+1));
		}
		resourceFile.close();
		return success;
	}
};