#ifndef CHARACTER_H
#define CHARACTER_H

#include <map>

#include "character_manager.h"

class component;

class character
{
public:

	character() = default;
	~character();

	void update(float delta_time) const;
	void draw();
	void destroy();

	void list_all_components() const;
	void display();

	[[nodiscard]] bool alive() const { return is_alive_; }

	//void move(std::vector<double> destination);

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
	
	
private:
	bool is_alive_ { true };
	//std::vector<double> my_location_ { 0, 0, 0 };

	character_manager& manager_ { *character_manager::instance() };
	std::vector<component*> components_;
	std::map<const std::type_info*, component*> component_type_map_;
};

#endif