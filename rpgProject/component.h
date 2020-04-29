#ifndef COMPONENT_H
#define COMPONENT_H

class character;

class component
{
public:
	character* owner { nullptr };
	virtual ~component() = default;
	virtual void initialize() {}
	virtual void update(float delta_time) {}
	virtual void draw() {}
	
};

#endif