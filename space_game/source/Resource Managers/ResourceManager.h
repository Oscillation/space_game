#pragma once

#include <SFML\System\NonCopyable.hpp>
#include <memory>
#include <map>
#include <string>

template <class T>
class ResourceManager : sf::NonCopyable 
{

public:
	ResourceManager(); 
	~ResourceManager();

	bool load(std::string id, std::string path); // Returns true on success
	T* get(std::string id); // Returns nullptr on fail

private:
	std::map<std::string, std::unique_ptr<T>> m_resourceMap;
};