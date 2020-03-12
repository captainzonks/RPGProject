#pragma once

#include "CombatClass.h"

class Fighter :
	public CombatClass
{
public:

	// constructor
	Fighter();
	// destructor
	virtual ~Fighter() override;

	// fighting style
	void SetFightingStyle();

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

