#include "attributes.h"

attributes::attributes(std::string label, std::string name, const int& strength, const int& dexterity, const int& constitution, const int& intelligence, const int& wisdom, const int& charisma)
	: label_{std::move(label)}, name_{std::move(name)}, strength_(strength), dexterity_(dexterity), constitution_(constitution), intelligence_(intelligence), wisdom_(wisdom), charisma_(charisma)
{
}
