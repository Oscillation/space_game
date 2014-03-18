#include "ResourceManager.h"

template <class T>
ResourceManager<T>::ResourceManager()
{

}

template <class T>
ResourceManager<T>::~ResourceManager()
{

}

template <class T>
bool ResourceManager<T>::load(std::string id, std::string path)
{
	m_resourceMap[id] = std::unique_ptr<T>(new T());
	return m_resourceMap[id]->loadFromFile(path);
}

template <class T>
T* ResourceManager<T>::get(std::string id)
{
	return m_resourceMap.at(i).get();
}