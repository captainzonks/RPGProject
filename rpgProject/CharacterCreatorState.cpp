#include "CharacterCreatorState.h"
#include "MenuState.h"

CharacterCreatorState CharacterCreatorState::m_CharacterCreatorState;

void CharacterCreatorState::Init()
{
	cout << "\nLet's create a character!" << endl;
}

void CharacterCreatorState::Cleanup()
{
}

void CharacterCreatorState::Pause()
{
}

void CharacterCreatorState::Resume()
{
}

void CharacterCreatorState::HandleEvents(Game* game)
{
	if (raceChoice != 0)
	{
		switch (raceChoice)
		{
		case 1:
			race = "Human";
			break;
		case 2:
			race = "Dwarf";
			break;
		case 3:
			race = "Elf";
			break;
		case 4:
			race = "Halfling";
			break;
		default:
			break;
		}
	}

	if (classChoice != 0)
	{
		switch (classChoice)
		{
		case 1:
			game->player = new Fighter(charName, race);
			game->ChangeState(MainMenuState::Instance());
			break;
		default:
			break;
		}
	}
}

void CharacterCreatorState::Update(Game* game)
{

}

void CharacterCreatorState::Draw(Game* game)
{
	std::cout << "\nWhat race are you?" << std::endl;

	PrintMenu(races, raceOptions);

	raceChoice = MenuChoice(raceOptions);

	std::cout << "\nWhat's your name? ";
	std::cin >> charName;

	std::cout << "\nWhat class are you?" << std::endl;

	PrintMenu(classes, classOptions);

	classChoice = MenuChoice(classOptions);
}
