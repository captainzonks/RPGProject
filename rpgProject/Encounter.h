#ifndef ENCOUNTER_H
#define ENCOUNTER_H

#include "Actor.h"
#include "EnemyManager.h"

#include <vector>

class Encounter
{
public:
	Encounter(EnemyManager& manager, std::shared_ptr<Actor> player);
	~Encounter();
	void SortInitiativeOrder();
	void DisplayIniatives(); // debug
	void BeginEncounter(EnemyManager& manager, std::shared_ptr<Actor> player);
	std::shared_ptr<Actor> RandomTargetPicker(std::shared_ptr<Actor> attacker);
	bool EncounterHandler(std::shared_ptr<Actor> attacker, std::shared_ptr<Actor> defender);

private:
	std::shared_ptr<Actor> player;
	EnemyManager& manager;
	std::vector<std::shared_ptr<Actor>> initiativeOrder;
};

#endif // !ENCOUNTER_H