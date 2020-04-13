//#include "Human.h"
//
//Human::Human()
//{
//	cout << "Human constructor called" << endl; // debug
//}
//
//Human::Human(int identifier)
//{
//	cout << "Human (int identifier) overloaded constructor called" << endl; // debug
//	this->name = "Bad Guy Human"; // temporary debug
//	this->RollStats();
//	this->identifier = identifier;
//	this->race = "Human";
//	this->level_ = 1;
//	this->health = 8 + get_const_mod();
//	this->max_health_ = health;
//	this->xp = 0;
//	this->myCurrency.add_money(roll_dice(4, 4) * 10);
//}
//
//Human::Human(string name)
//{
//	cout << "Human (name) overloaded constructor called" << endl; // debug
//	this->RollStats();
//	this->name = name;
//	this->race = "Human";
//	this->level_ = 1;
//	this->health = 8 + get_const_mod();
//	this->max_health_ = health;
//	this->xp = 0;
//	this->myCurrency.add_money(roll_dice(4, 4) * 10);
//}
//
//Human::~Human()
//{
//	std::cout << "Human destructor called" << endl;
//}
//
//void Human::RollStats()
//{
//	this->strength = roll_dice_ignore_lowest(4, 6) + 1;
//	this->dexterity = roll_dice_ignore_lowest(4, 6) + 1;
//	this->constitution = roll_dice_ignore_lowest(4, 6) + 1;
//	this->intelligence = roll_dice_ignore_lowest(4, 6) + 1;
//	this->wisdom = roll_dice_ignore_lowest(4, 6) + 1;
//	this->charisma = roll_dice_ignore_lowest(4, 6) + 1;
//}
//
//string Human::get_race()
//{
//	return this->race;
//}