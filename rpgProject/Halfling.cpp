//#include "Halfling.h"
//
//Halfling::Halfling()
//{
//	cout << "Halfling constructor called" << endl; // debug
//}
//
//Halfling::Halfling(int identifier)
//{
//	cout << "Halfling (int identifier) overloaded constructor called" << endl; // debug
//	this->name = "Bad Guy Halfling";
//	this->RollStats();
//	this->identifier = identifier;
//	this->race = "Halfling";
//	this->level_ = 1;
//	this->health = 6 + get_const_mod();
//	this->max_health_ = health;
//	this->xp = 0;
//	this->myCurrency.add_money(roll_dice(4, 4)* 10);
//}
//
//Halfling::Halfling(string name)
//{
//	cout << "Halfling (name) overloaded constructor called" << endl; // debug
//	this->name = name;
//	this->RollStats();
//	this->race = "Halfling";
//	this->level_ = 1;
//	this->health = 6 + get_const_mod();
//	this->max_health_ = health;
//	this->xp = 0;
//	this->myCurrency.add_money(roll_dice(4, 4) * 10);
//}
//
//Halfling::~Halfling()
//{
//	std::cout << "Halfling destructor called" << endl;
//}
//
//void Halfling::RollStats()
//{
//	this->strength = roll_dice_ignore_lowest(4, 6);
//	this->dexterity = roll_dice_ignore_lowest(4, 6);
//	this->constitution = roll_dice_ignore_lowest(4, 6) + 1;
//	this->intelligence = roll_dice_ignore_lowest(4, 6);
//	this->wisdom = roll_dice_ignore_lowest(4, 6);
//	this->charisma = roll_dice_ignore_lowest(4, 6) + 1;
//}
//
//string Halfling::get_race()
//{
//	return this->race;
//}
