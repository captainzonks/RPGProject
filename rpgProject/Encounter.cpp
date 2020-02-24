#include "Encounter.h"

//void Encounter::encounterHandler(Actor& player, Actor& enemy)
//{
//	// TODO getting kinda big, and the flow is wonky (asks Attack? every time)
//	// eventually a choice of KIND of attack will be replaced here
//
//
//	char choice{};
//	while (enemy.livingOrDead() && tolower(choice) != 'y' && tolower(choice) != 'n')
//	{
//		cin >> choice;
//		switch (tolower(choice))
//		{
//		case 'y':
//		{
//			player.attack(enemy);
//			break;
//		}
//		case 'n':
//		{
//			cout << "You ran away!" << endl;
//			break;
//		}
//		default:
//		{
//			cout << "That is not recognized input." << endl;
//			break;
//		}
//		}
//		if (enemy.livingOrDead())
//		{
//			cout << "The enemy still stands! Attack again (Y or N)? ";
//			cin >> choice;
//			if (tolower(choice) == 'y')
//			{
//				choice = ' ';
//				continue;
//			}
//			else if (tolower(choice) == 'n')
//				break;
//		}
//	}
//}
