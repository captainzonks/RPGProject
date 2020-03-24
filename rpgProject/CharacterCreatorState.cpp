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

	std::cout << "----" << this->races << "----" << std::endl;
	int count{ 1 };
	for (int i{}; i != raceOptions.size(); ++i)
	{
		std::cout << count << ") " << raceOptions[i] << std::endl;
		count++;
	}
	std::cout << "----";
	for (int i{}; i != this->races.length(); i++)
	{
		std::cout << "-";
	}
	std::cout << "----" << std::endl;

	bool valid_input{ false };

	do
	{
		std::cout << "Please enter a number: ";
		std::cin >> raceChoice;

		if (!(valid_input = cin.good()) || raceChoice > (int)raceOptions.size() || raceChoice < 1)
		{
			std::cout << "That's not a valid choice." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!valid_input || raceChoice > (int)raceOptions.size() || raceChoice < 1);

	std::cout << "\nWhat's your name? ";
	std::cin >> charName;

	std::cout << "\nWhat class are you?" << std::endl;

	std::cout << "----" << this->classes << "----" << std::endl;
	int count2{ 1 };
	for (int i{}; i != classOptions.size(); ++i)
	{
		std::cout << count2 << ") " << classOptions[i] << std::endl;
		count2++;
	}
	std::cout << "----";
	for (int i{}; i != this->classes.length(); i++)
	{
		std::cout << "-";
	}
	std::cout << "----" << endl;

	valid_input = false;

	do
	{
		std::cout << "Please enter a number: ";
		std::cin >> classChoice;

		if (!(valid_input = cin.good()) || classChoice > (int)classOptions.size() || classChoice < 1)
		{
			std::cout << "That's not a valid choice." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!valid_input || classChoice > (int)classOptions.size() || classChoice < 1);
}
