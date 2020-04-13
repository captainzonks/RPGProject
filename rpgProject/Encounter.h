//#ifndef ENCOUNTER_H
//#define ENCOUNTER_H
//
//#include "actor.h"
//#include "EnemyManager.h"
//
//#include <vector>
//
//class Encounter
//{
//public:
//	Encounter(EnemyManager& manager, actor& player);
//	~Encounter();
//	void SortInitiativeOrder();
//	void DisplayIniatives(); // debug
//	void BeginEncounter(EnemyManager& manager, actor& player);
//	actor* RandomTargetPicker(actor& attacker);
//	bool EncounterHandler(actor& attacker, actor& defender);
//
//private:
//	actor* player;
//	EnemyManager& manager;
//	std::vector<actor*> initiativeOrder;
//};
//
//#endif // !ENCOUNTER_H