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
};

