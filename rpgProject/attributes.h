#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H
#include <string>

class attributes
{
public:
	attributes(std::string label, std::string name, const int& strength, const int& dexterity, const int& constitution, const int& intelligence, const int& wisdom, const int& charisma);
	~attributes() = default;

	std::string get_label() const { return label_; }
	std::string get_name() const { return name_; }

	int get_current_health() const { return current_health_; }
	int get_max_health() const { return max_health_; }
	int get_current_mana() const { return current_mana_; }
	int get_max_mana() const { return max_mana_; }
	int get_current_exp() const { return current_exp_; }

	int get_strength() const { return strength_; }
	int get_strength_mod() const { return (strength_ - 10) / 2; }
	int get_dexterity() const { return dexterity_; }
	int get_dexterity_mod() const { return (dexterity_ - 10) / 2; }
	int get_constitution() const { return constitution_; }
	int get_constitution_mod() const { return (constitution_ - 10) / 2; }
	int get_intelligence() const { return intelligence_; }
	int get_intelligence_mod() const { return (intelligence_ - 10) / 2; }
	int get_wisdom() const { return wisdom_; }
	int get_wisdom_mod() const { return (wisdom_ - 10) / 2; }
	int get_charisma() const { return charisma_; }
	int get_charisma_mod() const { return (charisma_ - 10) / 2; }
	
private:
	std::string label_, name_;
	int current_health_{}, max_health_{}, current_mana_{}, max_mana_{}, current_exp_{};

	int strength_{}, dexterity_{}, constitution_{}, intelligence_{}, wisdom_{}, charisma_{};
};

#endif