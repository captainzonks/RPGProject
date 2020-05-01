#ifndef ENTITY_H
#define ENTITY_H

#include <map>

#include "entity_manager.h"

class component;

class entity
{
public:

	entity() = default;
	entity(std::string name, layer_type layer);
	~entity();

	void update(float delta_time) const;
	void draw();
	void destroy();

	void list_all_components() const;
	void display();

	[[nodiscard]] bool is_active() const { return is_active_; }

	template <typename T, typename ... TArgs>
	T& add_component(TArgs&& ... args)
	{
		T* new_component(new T(std::forward<TArgs>(args)...));
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
	T* get_component()
	{
		return static_cast<T*>(component_type_map_[&typeid(T)]);
	}

	std::string name;
	layer_type layer;
	
private:
	bool is_active_ { true };

	std::vector<component*> components_;
	std::map<const std::type_info*, component*> component_type_map_;
};

#endif