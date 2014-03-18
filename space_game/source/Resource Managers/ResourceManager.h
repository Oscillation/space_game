#pragma once

#include <SFML\System\NonCopyable.hpp>
#include <memory>
#include <map>
#include <string>

template <class T>
class ResourceManager : sf::NonCopyable 
{

public:
	ResourceManager() 
	{
	}

	~ResourceManager()
	{
	}

	bool load(std::string id, std::string path) // Returns true on 
	{
		std::unique_ptr<T> resource(new T());
		bool success = resource->loadFromFile(path);
		m_resourceMap.insert(std::make_pair(id, std::move(resource)));
		return success;
	}

	T* get(std::string id) // Returns nullptr on fail
	{
		return m_resourceMap.at(id).get();
	}

private:
	std::map<std::string, std::unique_ptr<T>> m_resourceMap;
};