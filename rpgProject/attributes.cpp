#include "attributes.h"

attributes::attributes(std::string label, std::string name, const race_options race, const int& strength, const int& dexterity, const int& constitution, const int& intelligence, const int& wisdom, const int& charisma)
	: label_{std::move(label)}, name_{std::move(name)}, race_enum_(race), strength_(strength), dexterity_(dexterity), constitution_(constitution), intelligence_(intelligence), wisdom_(wisdom), charisma_(charisma)
{
	race_string_ = race_strings[static_cast<int>(race_enum_)];
}
