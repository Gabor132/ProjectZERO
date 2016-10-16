#pragma once
#include <iostream>
template<class Identifier, class Resource>
void ResourceManager<Identifier, Resource>::PushResourceIntoMap(Identifier id, std::unique_ptr<Resource> resource)
{
	auto find = m_ResourceMap.find(id);
	if (find == m_ResourceMap.end())
		m_ResourceMap.insert(std::make_pair(id, std::move(resource)));
}

template<class Identifier, class Resource>
void  ResourceManager<Identifier, Resource>::LoadResource(const Identifier id, const std::string& fileName)
{
	ptr resource(new Resource);
	if (resource->loadFromFile(fileName))
		PushResourceIntoMap(id, std::move(resource));
	else
		std::cout << "failed to load resource";

}
template<class Identifier, class Resource>
Resource& ResourceManager<Identifier, Resource>::GetResource(Identifier id)
{
	auto find = m_ResourceMap.find(id);
	if (find != m_ResourceMap.end())
		return *(find->second);
}
template<class Identifier, class Resource>
const Resource& ResourceManager<Identifier, Resource>::GetResource(Identifier id)const
{
	auto find = m_ResourceMap.find(id);
	if (find != m_ResourceMap.end())
		return *(find->second);
}