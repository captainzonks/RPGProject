#ifndef COMPONENT_H
#define COMPONENT_H

class entity;

class component
{
public:
	entity* owner { nullptr };
	virtual ~component() = default;
	virtual void initialize() {}
	virtual void update(float delta_time) {}
	virtual void render() {}
};

#endif