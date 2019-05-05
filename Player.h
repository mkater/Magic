#pragma once
#include"Card.h"
#include<string>
#include<queue>
#include<vector>
using namespace std;

class Card;

class Player
{
private:
	int playerLife;		//players have life, energy, a name, deck, and hand.
	int playerEnergy;
	string playerName;
	queue<Card> deck;
	vector<Card> hand;
public:
	Player(string name);		//players are instantiated with a name picked by user
	string getPlayerName();		//setters and getters for private members
	int getplayerLife();
	void setPlayerLife(int lifeTotal);
	int getplayerEnergy();
	void setPlayerEnergy(int energyTotal);
	int getplayerDeckSize();
	int getplayerHandSize();
	vector<Card> & getHand();
	queue<Card> & getDeck();
	void createDeck(queue<Card> & myQueue);	
	void shuffleDeck(queue<Card> & myDeck);
	void drawOpeningHand(queue<Card> & myDeck, vector<Card> & myHand);
	void drawCard();
	void displayHand();
	void displayHandDescription();
	bool checkifCardinHand(int choice);
};

