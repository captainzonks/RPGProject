#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

static std::string game_version{"v0.02"};

enum class character_class
{
	none = 0,
	fighter = 1
};

// fighter related enum
enum class fighting_style
{
	none = 0,
	archery = 1,
	defense = 2,
	dueling = 3,
	great_weapon_fighting = 4,
	protection = 5,
	two_weapon_fighting = 6
};

enum class damage_type
{
	none = 0,
	acid = 1,
	bludgeoning = 2,
	cold = 3,
	fire = 4,
	force = 5,
	lightning = 6,
	necrotic = 7,
	piercing = 8,
	poison = 9,
	psychic = 10,
	radiant = 11,
	slashing = 12,
	thunder = 13
};

enum class item_type
{
	none = 0,
	consumable = 1,
	armor = 2,
	weapon = 3
};

enum class weapon_type
{
	none = 0,
	melee = 1,
	ranged = 2
};

enum class weapon_proficiency
{
	none = 0,
	simple = 1,
	martial = 2
};

enum class armor_type
{
	none = 0,
	light_armor = 1,
	medium_armor = 2,
	heavy_armor = 3,
	shield = 4
};

enum class abilities
{
	none = 0,
	strength = 1,
	dexterity = 2,
	constitution = 3,
	intelligence = 4,
	wisdom = 5,
	charisma = 6
};

#endif