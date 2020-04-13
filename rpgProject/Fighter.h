#pragma once

#include "combat_class.h"

class Fighter 
	: public combat_class
{
public:

	// player constructor
	Fighter(std::string name, std::string race);
	// enemy constructor
	Fighter(int identifier);

	// destructor
	virtual ~Fighter() override;

	// roll racial stats
	virtual void roll_human_stats() override, roll_dwarf_stats() override, roll_elf_stats() override, roll_halfling_stats() override;

	// player fighting style
	void SetFightingStyle();
	void PrintTWFDef();
	void PrintProtectionDef();
	void PrintGWFDef();
	void PrintDuelingDef();
	void PrintDefenseDef();
	void PrintArcheryDef();
	// enemy fighting style
	void SetEnemyFightingStyle();

	// display
	virtual void DisplayClassInformation() override;

	// level_ up
	void level_up() override;

private:
};

