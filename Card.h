#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Player;	//need to include class Player as Player is used here

class Card
{
private:

	string name;	//cards have a name and value
	int value;

public:
	Card();
	Card(string cardName, int CardValue);	//constructor
	Card(int value);

	void Fireblast(Player * myPlayerptr, Player * myPlayerptr2);	//10 different functions for the 10 spells
	void EnergyIncursion(Player * myPlayerptr);	//
	void MindBlast(Player * myPlayerptr, Player * myplayerptr2);
	void EldritchBlast(Player * myPlayerptr, Player * myPlayerptr2);		//
	void JustLikeaTonofSpiders(Player * myPlayerptr, Player * myPlayerptr2);
	void CureWounds(Player * myPlayerptr);	//
	void AbsorbLife(Player * myPlayerptr, Player * myPlayerptr2);	//	
	void DawnofRevelation(Player * myPlayerptr);	//
	void MindCulling(Player * myPlayerptr, Player * playerptr2);	//
	void SkillShot(Player * myPlayerptr, Player * myPlayerptr2);	//
	void setName(string cardName);	//setters and getters
	string getName();
	int getValue();
	void setValue(int cardValue);
	void cardDescription(Card myCard);

};

