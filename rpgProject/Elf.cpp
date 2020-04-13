//#include "Elf.h"
//
//Elf::Elf()
//{
//	cout << "Elf constructor called" << endl; // debug
//}
//
//Elf::Elf(int identifier)
//{
//	cout << "Elf (int identifier) overloaded constructor called" << endl; // debug
//	this->name_ = "Bad Guy Elf";
//	this->RollStats();
//	this->identifier = identifier;
//	this->race_ = "Elf";
//	this->level_ = 1;
//	this->health = 6 + get_const_mod();
//	this->max_health_ = health;
//	this->xp = 0;
//	this->myCurrency.add_money(roll_dice(4, 4) * 10);
//}
//
//Elf::Elf(string name_)
//{
//	cout << "Elf (name_) overloaded constructor called" << endl; // debug
//	this->name_ = name_;
//	this->RollStats();
//	this->race_ = "Elf";
//	this->level_ = 1;
//	this->health = 6 + get_const_mod();
//	this->max_health_ = health;
//	this->xp = 0;
//	this->myCurrency.add_money(roll_dice(4, 4) * 10);
//}
//
//Elf::~Elf()
//{
//	std::cout << "Elf destructor called" << endl;
//}
//
//void Elf::RollStats()
//{
//	this->strength = roll_dice_ignore_lowest(4, 6);
//	this->dexterity = roll_dice_ignore_lowest(4, 6) + 2;
//	this->constitution = roll_dice_ignore_lowest(4, 6);
//	this->intelligence = roll_dice_ignore_lowest(4, 6) + 1;
//	this->wisdom = roll_dice_ignore_lowest(4, 6) + 1;
//	this->charisma = roll_dice_ignore_lowest(4, 6) + 1;
//}
//
//string Elf::get_race()
//{
//	return this->race_;
//}
