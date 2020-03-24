#pragma once

#include "GameState.h"

class CharacterCreatorState :
	public GameState
{
public:
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(Game* game);
	void Update(Game* game);
	void Draw(Game* game);

	static CharacterCreatorState* Instance()
	{
		return &m_CharacterCreatorState;
	}

protected:
	CharacterCreatorState() {}
	int raceChoice{};
	std::string race{};
	std::string charName{};
	int classChoice{};
	static CharacterCreatorState m_CharacterCreatorState;
	std::vector<std::string> raceOptions{ "Human", "Dwarf", "Elf", "Halfling" };
	std::vector<std::string> classOptions{ "Fighter" };
	const std::string races{ "Races" };
	const std::string classes{ "Classes" };
};

