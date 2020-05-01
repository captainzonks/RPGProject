#ifndef ANIMATION_H
#define ANIMATION_H

class animation
{
public:
	unsigned index;
	unsigned num_frames;
	unsigned animation_speed;

	animation() = default;
	animation(const unsigned index, const unsigned num_frames, const unsigned animation_speed)
		: index(index), num_frames(num_frames), animation_speed(animation_speed) {}
};

#endif