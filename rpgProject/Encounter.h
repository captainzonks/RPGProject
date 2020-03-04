#ifndef ENCOUNTER_H
#define ENCOUNTER_H

#include "Actor.h"
#include "EnemyManager.h"

class Encounter
{
public:
	Encounter(EnemyManager& manager, Actor* player);
	void encounterHandler(Actor* attacker, Actor* defender);

private:
	Actor* player;
	EnemyManager& manager;
};

#endif // !ENCOUNTER_H