#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H
#include <string>

class attributes
{
public:
	attributes() = default;
	~attributes() = default;
private:
	std::string label_, name_;
	int currentHP_{}, maxHP_{}, currentMana_{}, maxMana_{}, currentXP_{};

	int strength_{}, dexterity_{}, constitution_{}, intelligence_{}, wisdom_{}, charisma_{};
};

#endif