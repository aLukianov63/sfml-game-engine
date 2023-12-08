
#ifndef GAMETEST_SRC_ENGINE_RESOURCEMANAGER_H_
#define GAMETEST_SRC_ENGINE_RESOURCEMANAGER_H_

#include <SFML/Audio.hpp>

#include <unordered_map>
#include <memory>

template <typename Resource, typename Identifier = int>
class ResourceManager
{
public:
	ResourceManager(const ResourceManager&) = delete;
	auto operator=(const ResourceManager&) -> ResourceManager& = delete;

	explicit ResourceManager() = default;
public:
	template <typename ... Args>
	auto load(const Identifier& id, Args&& ... args) -> void
	{
		std::unique_ptr<Resource> pRes(new Resource);
		if (!pRes->loadFromFile(std::forward<Args>(args)...)) throw std::runtime_error("File not found!");
		_resources.emplace(id, std::move(pRes));
	}

	auto get(const Identifier& id) const -> Resource&
	{
		return *_resources.at(id);
	}

private:
	std::unordered_map<Identifier, std::unique_ptr<Resource>> _resources;
};

template<typename Identifier>
class ResourceManager<sf::Music, Identifier>
{
public:
	ResourceManager(const ResourceManager&) = delete;
	auto operator=(const ResourceManager&) -> ResourceManager& = delete;

	explicit ResourceManager() = default;
public:
	template<typename ... Args>
	auto load(const Identifier &id, Args &&... args) -> void
	{
		std::unique_ptr<sf::Music> pRes(new sf::Music);
		if (!pRes->openFromFile(std::forward<Args>(args)...)) throw std::runtime_error("File not found!");
		_resources.emplace(id, std::move(pRes));
	}

	auto get(const Identifier &id) const -> sf::Music&
	{
		return *_resources.at(id);
	}
private:
	std::unordered_map<Identifier, std::unique_ptr<sf::Music>> _resources;
};

#endif //GAMETEST_SRC_ENGINE_RESOURCEMANAGER_H_
