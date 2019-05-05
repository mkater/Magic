#include"Card.h"
#include"Player.h"
Card::Card()
{

}

Card::Card(string cardName, int cardValue)	//constructor
{
	name = cardName;
	value = cardValue;
}

Card::Card(int cardValue)
{
	value = cardValue;
}

void Card::setName(string cardName)	//setters and getters
{
	name = cardName;
}

string Card::getName()
{
	return name;
}

void Card::setValue(int cardValue)
{
	value = cardValue;
}

int Card::getValue()
{
	return value;
}

void Card::Fireblast(Player * myPlayerptr, Player * myPlayerptr2)	//all the spells take in player pointers
{
	if (myPlayerptr->getplayerEnergy() > 6)	//verify enough energy
	{
		myPlayerptr->setPlayerEnergy(myPlayerptr->getplayerEnergy() - 7);	//changes energy
		myPlayerptr2->setPlayerLife(myPlayerptr2->getplayerLife() - 6);		//changes player life
		cout << "\n" << myPlayerptr->getPlayerName() << " casts FireBlast! " << myPlayerptr2->getPlayerName() << " takes 6 damage!\n";
	}
	else
	{
		cout << "Unable to cast, not enough energy!\n";
	}
}

void Card::EnergyIncursion(Player * myPlayerptr)
{
	if (myPlayerptr->getplayerDeckSize() > 1)	//verify deck large enough to cast, otherwise player will run out of cards
	{
		myPlayerptr->setPlayerEnergy(myPlayerptr->getplayerEnergy() + 12);	//gains energy and draws a card
		myPlayerptr->getHand().push_back(myPlayerptr->getDeck().front());	//pushes card from queue deck to vector hand
		myPlayerptr->getDeck().pop();	//removes from queue
		cout << "\n" << myPlayerptr->getPlayerName() << " casts Energy Incursion! " << myPlayerptr->getPlayerName()
			<< " gains 12 energy and draws a card!\n";
	}
	else
	{
		cout << "Unable to cast, this would empty your deck causing you to lose the game!\n";
	}
}

void Card::MindBlast(Player * myPlayerptr, Player * myplayerptr2)
{
	if (myPlayerptr->getplayerEnergy() > 4)	//checks energy
	{
		cout << "\n" << myPlayerptr->getPlayerName() << " casts MindBlast! " << myplayerptr2->getPlayerName()
			<< " discards two cards!\n";

		myPlayerptr->setPlayerEnergy(myPlayerptr->getplayerEnergy() - 5);
		if (!myplayerptr2->getHand().empty())	//verifies hand has cards, to avoid index exceptions etc.
		{
			if (myplayerptr2->getHand().size() > 2)
			{
				for (int i = 0; i < 2; i++)
				{
					myplayerptr2->getHand().pop_back();	//removes cards
				}
			}
			else
			{
				myplayerptr2->getHand().clear();	//if less than 2 just removes hand
			}
		}
	}
	else
	{
		cout << "Unable to cast, not enough energy!\n";
	}
}

void Card::EldritchBlast(Player * myPlayerptr, Player * myPlayerptr2)
{
	if (myPlayerptr->getplayerEnergy() > 11)
	{
		myPlayerptr->setPlayerEnergy(myPlayerptr->getplayerEnergy() - 12);
		myPlayerptr2->setPlayerLife(myPlayerptr2->getplayerLife() / 2);		//halves player life total
		cout << "\n" << myPlayerptr->getPlayerName() << " casts Eldritch Blast! " << myPlayerptr2->getPlayerName()
			<< " loses half their life, rounded up!\n";
	}
	else
	{
		cout << "Unable to cast, not enough energy!\n";
	}
}

void Card::JustLikeaTonofSpiders(Player * myPlayerptr, Player * myPlayerptr2)
{
	if (myPlayerptr->getplayerEnergy() > 11)
	{
		cout << "\n" << myPlayerptr->getPlayerName() << " casts Just Like, a Ton of Spiders! " << myPlayerptr2->getPlayerName() <<
			" discards a card and loses three life!\n";
		myPlayerptr->setPlayerEnergy(myPlayerptr->getplayerEnergy() - 12);
		myPlayerptr2->setPlayerLife(myPlayerptr2->getplayerLife() - 3);
		if (!myPlayerptr2->getHand().empty())	
		{
			myPlayerptr2->getHand().pop_back(); //removes card from hand
		}
	}
	else
	{
		cout << "Unable to cast, not enough energy!\n";
	}
}

void Card::CureWounds(Player * myPlayerptr)
{
	if (myPlayerptr->getplayerEnergy() > 4)
	{
		cout << "\n" << myPlayerptr->getPlayerName() << " casts Cure Wounds! " << myPlayerptr->getPlayerName()
			<< " gains 6 life!\n";
		myPlayerptr->setPlayerEnergy(myPlayerptr->getplayerEnergy() - 5);
		myPlayerptr->setPlayerLife(myPlayerptr->getplayerLife() + 6);	//gains life when cast
	}
	else
	{
		cout << "Unable to cast, not enough energy!\n";
	}
}

void Card::AbsorbLife(Player * myPlayerptr, Player * myPlayerptr2)
{
	if (myPlayerptr->getplayerEnergy() > 7)
	{
		cout << "\n" << myPlayerptr->getPlayerName() << " casts Absorb Life! " << myPlayerptr2->getPlayerName()
			<< " loses 3 life and " << myPlayerptr->getPlayerName() << " gains three life!\n";
		myPlayerptr->setPlayerEnergy(myPlayerptr->getplayerEnergy() - 8);
		myPlayerptr->setPlayerLife(myPlayerptr->getplayerLife() + 3);	//takes life from opponent gives to player
		myPlayerptr2->setPlayerLife(myPlayerptr2->getplayerLife() - 3);
	}
	else
	{
		cout << "Unable to cast, not enough energy!\n";
	}
}

void Card::DawnofRevelation(Player * myPlayerptr)
{
	if (myPlayerptr->getplayerEnergy() > 7)
	{
		cout << "\n" << myPlayerptr->getPlayerName() << " casts Dawn of Revelation! " << myPlayerptr->getPlayerName()
			<< " draws 2 cards and gains 4 life!\n";
		myPlayerptr->setPlayerEnergy(myPlayerptr->getplayerEnergy() - 8);
		myPlayerptr->setPlayerLife(myPlayerptr->getplayerLife() + 4);
		if (myPlayerptr->getDeck().size() > 2)		//draws two cards as long as deck can support it.
		{
			for (int i = 0; i < 2; i++)
			{
				myPlayerptr->getHand().push_back(myPlayerptr->getDeck().front());
				myPlayerptr->getDeck().pop();
			}
		}
		else
		{
			cout << "Unable to cast, you will run out of cards in your deck and lose the game\n";
		}
	}
	else
	{
		cout << "Unable to cast, not enough energy!\n";
	}
}

void Card::MindCulling(Player * myPlayerptr, Player * myplayerptr2)
{
	if (myPlayerptr->getplayerEnergy() > 6)
	{
		cout << "\n" << myPlayerptr->getPlayerName() << " casts MindCulling! " << myPlayerptr->getPlayerName()
			<< " draws two cards and " << myplayerptr2->getPlayerName() << " discards two cards!\n";
		myPlayerptr->setPlayerEnergy(myPlayerptr->getplayerEnergy() - 7);
		if (myPlayerptr->getDeck().size() > 2)		//draws two cards if deck can support it
		{
			for (int i = 0; i < 2; i++)
			{
				myPlayerptr->getHand().push_back(myPlayerptr->getDeck().front());
				myPlayerptr->getDeck().pop();
			}
			if (!myplayerptr2->getHand().empty())		//opponent discards two cards
			{
				if (myplayerptr2->getHand().size() > 2)
				{
					for (int i = 0; i < 2; i++)
					{
						myplayerptr2->getHand().pop_back();
					}
				}
				else
				{
					myplayerptr2->getHand().clear();
				}
			}
		}
		else
		{
			cout << "Not enough cards in your deck, casting this spell will cause you to lose the game.\n";
		}
	}
	else
	{
		cout << "Unable to cast, not enough energy!\n";
	}
}

void Card::SkillShot(Player * myPlayerptr, Player * myPlayerptr2)
{
	if (myPlayerptr->getplayerEnergy() > 3)
	{
		cout << "\n" << myPlayerptr->getPlayerName() << " casts SkillShot! " << myPlayerptr->getPlayerName()
			<< " deals 10 damage if " << myPlayerptr2->getPlayerName() << " has exactly 10 life.\n";
			
		myPlayerptr->setPlayerEnergy(myPlayerptr->getplayerEnergy() - 4);
		if (myPlayerptr2->getplayerLife() == 10)		//if player life exactly 10, they lose 10 life.
		{
			myPlayerptr2->setPlayerLife(0);
		}
	}
	else
	{
		cout << "Unable to cast, not enough energy!\n";
	}
}

void Card::cardDescription(Card myCard)	//works
{
	if (myCard.getValue() == 0)		//function checks cards in hand and prints these descriptions
	{
		cout << "FireBlast: Deal 6 damage to your opponent. \n Energy Cost: 7\n"
			"--Well, that's one method of turning up the heat in battle.\n\n";
	}
	else if (myCard.getValue() == 1)
	{
		cout << "Energy Incursion: Gain 12 energy and draw a card.\nEnergyCost: 0\n"
			"--Woah!  That's a lot of energy you've got there.  Use it carefully.\n\n";
	}
	else if (myCard.getValue() == 2)
	{
		cout << "MindBlast: Opponent discards two cards from hand.\nEnergyCost: 5\n"
			"--The mind of a wizard is their most powerful weapon.  At least yours used to be\n\n";
	}
	else if (myCard.getValue() == 3)
	{
		cout << "EldritchBlast: Opponent loses half of their life, rounded up.\nEnergyCost: 12\n"
			"--Hey you don't look half bad right now.\n\n";
	}
	else if (myCard.getValue() == 4)
	{
		cout << "Just like, a ton of spiders: Opponent discards a card and loses 3 life.\nEnergyCost: 12\n"
			"--Wow, they weren't kidding.\n\n";
	}
	else if (myCard.getValue() == 5)
	{
		cout << "Cure Wounds: Gain 6 life. \n Energy Cost: 5\n"
			"--My grevious injury is now a mere owie\n\n";
	}
	else if (myCard.getValue() == 6)
	{
		cout << "Absorb Life: You gain 3 life, your opponent loses 3 life.\nEnergy Cost: 8\n"
			"--Your blood is quite pleasing.  A pity there's not enough for both of us - Greg, Vampire Archmage\n\n";
	}
	else if (myCard.getValue() == 7)
	{
		cout << "Dawn of Revelation: You gain 4 life and draw 2 cards.\nEnergy Cost: 8\n"
			"--Man, learning stuff and being healthy is hard work!\n\n";
	}
	else if (myCard.getValue() == 8)
	{
		cout << "MindCulling: You draw 2 cards and your opponent discards two cards.\nEnergy Cost: 7\n"
			"--Meh, you weren't even using your brain right to begin with\n\n";
	}
	else if (myCard.getValue() == 9)
	{
		cout << "SkillShot: If your opponent has exactly 10 life, deal 10 damage to him/her.\nEnergy Cost: 4\n"		//wasn't sure if written correctly
			"--See!  I told you I could do it\n\n";
	}
	else
	{
		cout << "Invalid selection.  What kind of wizard are you?\n\n";
	}
}
