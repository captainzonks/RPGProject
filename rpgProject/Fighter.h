#pragma once

#include "CombatClass.h"

class Fighter 
	: public CombatClass
{
public:

	// constructors
		// player constructor
	Fighter(string name, string race);
		// enemy constructor
	Fighter(int identifier);

	// destructor
	virtual ~Fighter() override;

	// roll racial stats
	virtual void RollHumanStats() override, RollDwarfStats() override, RollElfStats() override, RollHalflingStats() override;

	// player fighting style
	void SetFightingStyle();
	// enemy fighting style
	void SetEnemyFightingStyle();

	// display
	virtual void DisplayClassInformation() override;

	// level up
	void LevelUp() override;

private:
	std::vector<ABILITIES> savingThrows{ ABILITIES::STRENGTH, ABILITIES::CONSTITUTION };

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

	FIGHTING_STYLE fightingStyle{};

};

