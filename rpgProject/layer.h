#ifndef LAYER_H
#define LAYER_H

class layer
{
public:

	virtual void render() = 0;
	virtual void update(float delta_time) = 0;
};

#endif