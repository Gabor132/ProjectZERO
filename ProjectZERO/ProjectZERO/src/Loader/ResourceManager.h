#pragma once
#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>
#include <string>
#include <memory>
#include <utility>

template<class Identifier, class Resource>
class ResourceManager
{
protected:

	void                            PushResourceIntoMap(Identifier id, std::unique_ptr<Resource> resource);

public:

	virtual void                    LoadResource(Identifier id, const std::string& fileName);
	virtual Resource&               GetResource(Identifier id);
	virtual const Resource&         GetResource(Identifier id)const;

private:

	typedef std::unique_ptr<Resource> ptr;
	std::map< Identifier, ptr > m_ResourceMap;
};
#include "ResourceManager.inl"

#endif // RESOURCEMANAGER_H