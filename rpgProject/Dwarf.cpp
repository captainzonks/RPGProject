//#include "Dwarf.h"
//
//Dwarf::Dwarf()
//{
//	cout << "Dwarf constructor called" << endl; // debug
//}
//
//Dwarf::Dwarf(int identifier)
//{
//	cout << "Dwarf (name) overloaded constructor called" << endl; // debug
//	this->name = "Bad Guy Dwarf"; // temporary debug value
//	this->RollStats();
//	this->identifier = identifier;
//	this->race = "Dwarf";
//	this->level_ = 1;
//	this->health = 8 + get_const_mod();
//	this->max_health_ = health;
//	this->xp = 0;
//	this->myCurrency.add_money(roll_dice(4, 4) * 10);
//	this->resistance = damage_type::poison;
//}
//
//Dwarf::Dwarf(string name)
//{
//	cout << "Dwarf (name) overloaded constructor called" << endl; // debug
//	this->name = name;
//	this->RollStats();
//	this->race = "Dwarf";
//	this->level_ = 1;
//	this->health = 8 + get_const_mod();
//	this->max_health_ = health;
//	this->xp = 0;
//	this->myCurrency.add_money(roll_dice(4, 4) * 10);
//	this->resistance = damage_type::poison;
//}
//
//Dwarf::~Dwarf()
//{
//	std::cout << "Dwarf destructor called" << endl;
//}
//
//void Dwarf::RollStats()
//{
//	this->strength = roll_dice_ignore_lowest(4, 6) + 2;
//	this->dexterity = roll_dice_ignore_lowest(4, 6);
//	this->constitution = roll_dice_ignore_lowest(4, 6) + 2;
//	this->intelligence = roll_dice_ignore_lowest(4, 6);
//	this->wisdom = roll_dice_ignore_lowest(4, 6) + 1;
//	this->charisma = roll_dice_ignore_lowest(4, 6);
//}
//
//string Dwarf::get_race()
//{
//	return this->race;
//}
