#include"Card.h"
#include"Player.h"
#include<random>
#include<time.h>
Player::Player(string name)
{
	playerLife = 25;
	playerEnergy = 30;
	playerName = name;
	createDeck(deck);
	shuffleDeck(deck);
	drawOpeningHand(deck, hand);
}

string Player::getPlayerName()		//setters and getters for members of Player class
{
	return playerName;
}

int Player::getplayerLife()
{
	return playerLife;
}

void Player::setPlayerLife(int lifeTotal)
{
	playerLife = lifeTotal;
}

int Player::getplayerEnergy()
{
	return playerEnergy;
}

void Player::setPlayerEnergy(int energyTotal)
{
	playerEnergy = energyTotal;

}

int Player::getplayerDeckSize()
{
	return deck.size();
}

int Player::getplayerHandSize()
{
	return hand.size();
}

vector<Card> & Player::getHand()		//deck and hand getters passed by reference as they will be changing.
{
	return hand;
}

queue<Card> & Player::getDeck()
{
	return deck;
}

void Player::createDeck(queue<Card> & myQueue)
{
	Card deckCard;	//creates deck out of Cards

	for (int i = 0; i < 6; i++)	//creates 4 energy incursions with a value of 1
	{
		deckCard.setName("Energy Incursion");
		deckCard.setValue(1);
		myQueue.push(deckCard);
	}

	for (int i = 0; i < 6; i++)		//creates 4 fireblast with value of 0
	{
		deckCard.setName("Fireblast");
		deckCard.setValue(0);
		myQueue.push(deckCard);
	}

	for (int i = 0; i < 3; i++)		//continues creating cards in similar fashion with different quantities and values.
	{
		deckCard.setName("Absorb Life");
		deckCard.setValue(6);
		myQueue.push(deckCard);
	}

	for (int i = 0; i < 2; i++)
	{
		deckCard.setName("Cure Wounds");
		deckCard.setValue(5);
		myQueue.push(deckCard);
	}

	for (int i = 0; i < 4; i++)
	{
		deckCard.setName("Just like, a ton of spiders");
		deckCard.setValue(4);
		myQueue.push(deckCard);
	}

	for (int i = 0; i < 3; i++)
	{
		deckCard.setName("MindBlast");
		deckCard.setValue(2);
		myQueue.push(deckCard);
	}

	for (int i = 0; i < 2; i++)
	{
		deckCard.setName("Eldritch Blast");
		deckCard.setValue(3);
		myQueue.push(deckCard);
	}
	deckCard.setName("MindCulling");
	deckCard.setValue(8);
	myQueue.push(deckCard);
	deckCard.setName("SkillShot");
	deckCard.setValue(9);
	myQueue.push(deckCard);
	for (int i = 0; i < 2; i++)
	{
		deckCard.setName("Dawn of Revelation");
		deckCard.setValue(7);
		myQueue.push(deckCard);
	}
}

void Player::shuffleDeck(queue<Card> & deck)
{
	int randomSeed;	//creates int to random Seed
	srand(time(NULL));		//uses time function to use clock to create random number
	randomSeed = rand() % 100;	//random seed is now created with time
	srand(randomSeed);	//random seed will now be different depending on what time shuffledeck function called
	Card temp;
	vector<Card>newDeck;
	while (deck.size() != 0)
	{
		newDeck.push_back(deck.front());	//pushes deck onto vector for shuffling
		deck.pop();
	}

	for (unsigned int i = 0; i < newDeck.size(); i++)
	{
		for (unsigned int j = 0; j < newDeck.size(); j++)	//nested for loop looping through vector of deck
		{
			if (rand() % 2 == 0)		//calling random function from earlier
			{
				temp = newDeck[i];	//to randomly swap values
				newDeck[i] = newDeck[j];
				newDeck[j] = temp;
			}
		}
	}

	while (newDeck.size() > 0)
	{
		deck.push(newDeck.back());	//pushes now swapped/random cards back into queue of deck.
		newDeck.pop_back();
	}
}

void Player::drawOpeningHand(queue<Card> & myDeck, vector<Card> & myHand)
{
	for (int i = 0; i < 5; i++)		//start of the game draws 5 cards
	{
		myHand.push_back(myDeck.front());
		myDeck.pop();
	}
}

void Player::drawCard()
{
	if (deck.size() > 0)		//draws one card as long as deck isn't empty
	{
		hand.push_back(deck.front());	//pushes on vector of hand
		deck.pop();		//removes from queue
	}
}

void Player::displayHand()
{
	for (unsigned int i = 1; i < hand.size() + 1; i++)	//loops through hand
	{
		cout << i << ". " << hand[i - 1].getName() << endl;	//and displays name for each card in hand
	}
	cout << endl;
}

void Player::displayHandDescription()
{
	for (unsigned int i = 0; i < hand.size(); i++)	//loops through hand
	{
		hand[i].cardDescription(hand[i]);	//and displays the description for each card in hand, calls cardDescription function
	}
}

bool Player::checkifCardinHand(int choice)
{
	for (unsigned int i = 0; i < hand.size(); i++)	//bool function to see if card requested is in the player hand
	{
		if (choice == hand[i].getValue())		//if card in hand
		{
			return true;	//returns true
		}
	}
	return false;
}