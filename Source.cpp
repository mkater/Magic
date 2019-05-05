#include"Card.h"
#include"Player.h"
#include<iostream>
#include<random>
#include<iterator>


void removeCastSpellFromHand(Player * plptr, int choice);	//function declarations
Card findSpell(Player * plPtr, int choice);
void castSpell(Player * plptr1, Player * plptr2, int choice);
void playerStatusCheck(Player * plrPtr1);
void askForSpell();
void PlayGame(Player * plrPtr1, Player * plrPtr2);

using namespace std;

int main()

{
	
	
	string name1;
	string name2;
	cout << "Welcome to the wondeful realm of Wizardville, where wizards duel for the right to declare themselves the coolest.\n"
		"Each turn you cast a spell using ENERGY with the goal of getting your opponent's LIFE to 0, in which case you will win!\n"
		"Don't take too long because if you run out of cards in your deck you will lose the game.\n"
		"Good luck!\n\n";
	cout << "Player 1 what name would you like to go by?\n";
	getline(cin, name1);		//using getline so person can include spaces in their name
	Player player1(name1);		//creates Player object with name just put in
	cout << "Player 2 what name would you like to go by?\n";
	getline(cin, name2);
	Player player2(name2);
	Player * player1ptr = &player1;		//creates Player pointers pointing to the Players
	Player * player2ptr = &player2;

	PlayGame(player1ptr, player2ptr);		//calls PlayGame with both players

	if (player1ptr->getplayerLife() < 1 || player1ptr->getplayerDeckSize() < 1)		//If player1 runs out of cards or life they lose
	{
		if (player2ptr->getplayerLife() > 0)	//checks to make sure player2 has life left
		{
			cout << player2ptr->getPlayerName() << " wins the game!  You are the coolest around!\n";	//player2 wins
		}
		else
		{
			cout << player1ptr->getPlayerName() << " wins the game!You are the coolest around!\n";	//if player1 ran out of cards same time player2 ran out of life, player1 life has priority over cards. 
		}
	}
	else if (player2ptr->getplayerLife() < 1 || player2ptr->getplayerDeckSize() < 1)	//same with player2
	{
		if (player1ptr->getplayerLife() > 0)
		{
			cout << player1ptr->getPlayerName() << " wins the game!  You are the coolest around!\n";
		}
		else
		{
			cout << player2ptr->getPlayerName() << " wins the game!  You are the coolest around!\n";
		}
	}

	cin.ignore(2);
}

void PlayGame(Player * plrPtr1, Player * plrPtr2)	//Play game takes in both player pointers
{
	int choice;
	int counter = 0;
	while (plrPtr1->getplayerLife() > 0 && !plrPtr1->getDeck().empty() && plrPtr2->getplayerLife() > 0 && !plrPtr2->getDeck().empty())	//While Game is going on
	{
		if (counter > 0)	//player1 doesn't draw card on first turn
		{
			plrPtr1->drawCard();
		}
		counter++;	//does on future turns.  Also increments for turn counter

		do
		{
			cout << endl;
			cout << plrPtr1->getPlayerName() << " what would you like to do this turn?\n"	//giving player one options for turn
				"1.  See your Hand?\n"
				"2.  See what the cards in your hand do?\n"
				"3.  Display Life/Energy Totals of Each Player?\n"
				"4.  Cast a Spell?\n"
				"5.  Pass the turn?\n";
			cin >> choice;

			switch (choice)
			{
			case 1:
				cout << endl;
				plrPtr1->displayHand();	//Calls Display Hand function
				break;
			case 2:
				cout << endl;
				plrPtr1->displayHandDescription();	//Calls Display Hand Description Function, showing hand
				cout << endl;
				cout << plrPtr1->getPlayerName() << " Total Energy: " << plrPtr1->getplayerEnergy() << endl;	//Also displays player energy
				break;
			case 3:
				cout << endl;
				playerStatusCheck(plrPtr1);	//Calls function that displays player energy, deck size, etc.
				playerStatusCheck(plrPtr2);
				cout << "Turn: " << counter << endl;
				break;
			case 4:
				cout << endl;
				askForSpell();	//function displays available cards to cast
				int spellChoice;
				cin >> spellChoice;	//asks for spell
				castSpell(plrPtr1, plrPtr2, spellChoice);	//casts spell
				break;
			case 5:
				cout << "Yea, resting is nice\n";	//just passes turn
				break;
			}//end of switch
		} while (choice != 4 && choice != 5);  //end of while switch statement.  Keeps looping as long as they don't cast spell or pass.

		if (plrPtr2->getplayerLife() > 0 && !plrPtr2->getDeck().empty())	//occurs as long as player2 hasn't lost
		{
			plrPtr2->drawCard();	//does draw on first turn

			do
			{
				cout << endl;
				cout << plrPtr2->getPlayerName() << " what would you like to do this turn?\n"
					"1.  See your Hand?\n"
					"2.  See what the cards in your hand do?\n"
					"3.  Display Life/Energy Totals of Each Player?\n"
					"4.  Cast a Spell?\n"
					"5.  Pass the turn?\n";
				cin >> choice;

				switch (choice)
				{
				case 1:
					cout << endl;
					plrPtr2->displayHand();		//same loop as for player1
					break;
				case 2:
					cout << endl;
					plrPtr2->displayHandDescription();
					cout << plrPtr2->getPlayerName() << " Total Energy: " << plrPtr2->getplayerEnergy() << endl;
					break;
				case 3:
					cout << endl;
					playerStatusCheck(plrPtr1);
					playerStatusCheck(plrPtr2);
					cout << "Turn: " << counter << endl;
					break;
				case 4:
					cout << endl;
					askForSpell();
					int spellChoice;
					cin >> spellChoice;
					castSpell(plrPtr2, plrPtr1, spellChoice);	//main difference is cast spell, parameters are reversed.
					break;
				case 5:
					cout << endl;
					cout << "Yea, resting is nice\n";
					break;
				}//end of switch
			} while (choice != 4 && choice != 5);  //end of do while switch statement
		}
	} //end of while loop playing game
}
void castSpell(Player * plptr1, Player * plptr2, int choice)	//cast spell function takes in player pointers and the player choice
{
	if (plptr1->checkifCardinHand(choice) == true)	//verifies the card they are trying to cast is in their hand
	{
		Card spellCard = findSpell(plptr1, choice);	//finds and returns that spell if in hand
		switch (choice)
		{
		case 0:
			spellCard.Fireblast(plptr1, plptr2);	//casts each of the spells if in hand
			break;
		case 1:
			spellCard.EnergyIncursion(plptr1);
			break;
		case 2:
			spellCard.MindBlast(plptr1, plptr2);
			break;
		case 3:
			spellCard.EldritchBlast(plptr1, plptr2);
			break;
		case 4:
			spellCard.JustLikeaTonofSpiders(plptr1, plptr2);
			break;
		case 5:
			spellCard.CureWounds(plptr1);
			break;
		case 6:
			spellCard.AbsorbLife(plptr1, plptr2);
			break;
		case 7:
			spellCard.DawnofRevelation(plptr1);
			break;
		case 8:
			spellCard.MindCulling(plptr1, plptr2);
			break;
		case 9:
			spellCard.SkillShot(plptr1, plptr2);
			break;
		}//end of switch statement
		removeCastSpellFromHand(plptr1, choice);	//removes spell/card from hand
	}//end of if statement
	else
	{
		cout << "Oh No!  You tried to use a spell unavailable to you at this time.  Please be better.\n";	//prints this if spell not in hand
	}
	
}

void removeCastSpellFromHand(Player * plPtr, int choice)
{
	vector<Card>::const_iterator itr;	//need to use iterator to remove from hand
	for (itr = plPtr->getHand().begin(); itr != plPtr->getHand().end();)	//iterate over vector of hand
	{
		if (((Card)(*itr)).getValue() == choice)	//needed to cast Card as it was giving strange error otherwise, if cardvalue == player choice
		{
			itr = plPtr->getHand().erase(itr);	//we use iterator to erase that card from hand.
			break;	//if so we immediately break so that only one card is removed from hand if multiple copies of same card in hand.
		}
		else
		{
			itr++;	//increment iterator if not found
		}
	}
}

Card findSpell(Player * plPtr, int choice)
{
	for (unsigned int i = 0; i < plPtr->getHand().size(); i++)	//loops through player hand
	{
		if (plPtr->getHand()[i].getValue() == choice)
		{
			return plPtr->getHand()[i];		//returns the card if its found
		}
	}
	cout << "Can't Find Spell\n";	//else returns null
	 return NULL;
}

void playerStatusCheck(Player * plrPtr1)
{
	cout << plrPtr1->getPlayerName() << " life total: " << plrPtr1->getplayerLife() << endl;	//just displays important player stats
	cout << "Energy total: " << plrPtr1->getplayerEnergy() << endl;
	cout << "Deck Remaining: " << plrPtr1->getDeck().size() << endl;
	cout << "Cards in Hand: " << plrPtr1->getHand().size() << endl;
	cout << endl;
}

void askForSpell()
{
	cout << "Please enter the number of the spell you would like to cast, numbers are as follows:\n"	//displays the spells able to cast
		" 0. FireBlast\n 1. Energy Incursion \n 2. MindBlast \n 3. Eldritch Blast \n" 
		" 4. Just like, a ton of spiders\n 5. Cure Wounds \n" 
		" 6. Absorb Life \n 7. Dawn of Revelation\n 8. Mindculling\n 9. SkillShot\n";
}