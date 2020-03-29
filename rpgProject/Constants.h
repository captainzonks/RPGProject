#pragma once

#include <string>

static std::string version{"v0.01h"};

enum class COMBAT_CLASS
{
	NONE = 0,
	FIGHTER = 1
};

// fighter related enum
enum class FIGHTING_STYLE
{
	NONE = 0,
	ARCHERY = 1,
	DEFENSE = 2,
	DUELING = 3,
	GREAT_WEAPON_FIGHTING = 4,
	PROTECTION = 5,
	TWO_WEAPON_FIGHTING = 6
};

enum class DAMAGE_TYPE
{
	NONE = 0,
	ACID = 1,
	BLUDGEONING = 2,
	COLD = 3,
	FIRE = 4,
	FORCE = 5,
	LIGHTNING = 6,
	NECROTIC = 7,
	PIERCING = 8,
	POISON = 9,
	PSYCHIC = 10,
	RADIANT = 11,
	SLASHING = 12,
	THUNDER = 13
};

enum class ITEM_TYPE
{
	NONE = 0,
	POTION = 1,
	ARMOR = 2,
	WEAPON = 3
};

enum class WEAPON_TYPE
{
	NONE = 0,
	MELEE = 1,
	RANGED = 2
};

enum class WEAPON_PROFICIENCY
{
	NONE = 0,
	SIMPLE = 1,
	MARTIAL = 2
};

enum class ARMOR_TYPE
{
	NONE = 0,
	LIGHT_ARMOR = 1,
	MEDIUM_ARMOR = 2,
	HEAVY_ARMOR = 3,
	SHIELD = 4
};

enum class ABILITIES
{
	NONE = 0,
	STRENGTH = 1,
	DEXTERITY = 2,
	CONSTITUTION = 3,
	INTELLIGENCE = 4,
	WISDOM = 5,
	CHARISMA = 6
};