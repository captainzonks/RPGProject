#ifndef CLASS_FEATURES_H
#define CLASS_FEATURES_H

class class_features
{
public:
	virtual ~class_features() = default;

	virtual int get_hit_die() { return hit_die_; }
	virtual int get_starting_hit_points() { return starting_hit_points_; }

	
private:
	int hit_die_ {};
	int starting_hit_points_ {};
	
};

#endif
