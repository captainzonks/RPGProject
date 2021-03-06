#ifndef ENTITY_H
#define ENTITY_H

#include <map>

#include "entity_manager.h"

class component;

class entity
{
public:
	entity(const entity &other) = default;

	entity(entity &&other) noexcept
		: name(std::move(other.name)),
		  is_active_(other.is_active_),
		  components_(std::move(other.components_)),
		  component_type_map_(std::move(other.component_type_map_))
	{
	}

	entity &operator=(const entity &other)
	{
		if (this == &other)
			return *this;
		name = other.name;
		is_active_ = other.is_active_;
		components_ = other.components_;
		component_type_map_ = other.component_type_map_;
		return *this;
	}

	entity &operator=(entity &&other) noexcept
	{
		if (this == &other)
			return *this;
		name = std::move(other.name);
		is_active_ = other.is_active_;
		components_ = std::move(other.components_);
		component_type_map_ = std::move(other.component_type_map_);
		return *this;
	}

	entity() = default;
	entity(std::string name);
	~entity();

	void update() const;
	void render();
	void destroy();

	void list_all_components() const;
	void display();

	[[nodiscard]] bool is_active() const { return is_active_; }

	template <typename T, typename... TArgs>
	T &add_component(TArgs &&... args)
	{
		T *new_component(new T(std::forward<TArgs>(args)...));
		new_component->owner = this;
		components_.emplace_back(new_component);
		component_type_map_[&typeid(*new_component)] = new_component;
		new_component->initialize();
		return *new_component;
	}

	template <typename T>
	[[nodiscard]] bool has_component() const
	{
		return component_type_map_.count(&typeid(T));
	}

	template <typename T>
	T *get_component()
	{
		return static_cast<T *>(component_type_map_[&typeid(T)]);
	}

	std::string name;

private:
	bool is_active_{true};

	std::vector<component *> components_;
	std::map<const std::type_info *, component *> component_type_map_;
};

#endif