#ifndef ENCOUNTER_H
#define ENCOUNTER_H

#include "Actor.h"
#include "EnemyManager.h"

#include <vector>

class Encounter
{
public:
	Encounter(EnemyManager& manager, Actor& player);
	~Encounter();
	void SortInitiativeOrder();
	void DisplayIniatives(); // debug
	void BeginEncounter(EnemyManager& manager, Actor& player);
	Actor* RandomTargetPicker(Actor& attacker);
	bool EncounterHandler(Actor& attacker, Actor& defender);

private:
	Actor* player;
	EnemyManager& manager;
	std::vector<Actor*> initiativeOrder;
};

#endif // !ENCOUNTER_H