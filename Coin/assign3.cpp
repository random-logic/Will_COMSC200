#ifndef ASSIGN3
#define ASSIGN3

#include <iostream>
#include <iomanip>
#include "Coin.hpp"

int main() {
	double player_money = 0;
	double computer_money = 0;
	int round_number = 1;
	Coin nickel = Coin(); //Objects
	Coin dime = Coin();
	Coin quarter = Coin();

	while (player_money < 1 && computer_money < 1) {
		//Player tosses it
		nickel.toss(); //Calling object's methods
		dime.toss();
		quarter.toss();
		if (nickel.getSideUp() == "Heads")
			player_money += 0.05;
		if (dime.getSideUp() == "Heads")
			player_money += 0.1;
		if (quarter.getSideUp() == "Heads")
			player_money += 0.25;
		//Computer tosses it
		nickel.toss();
		dime.toss();
		quarter.toss();
		if (nickel.getSideUp() == "Heads")
			computer_money += 0.05;
		if (dime.getSideUp() == "Heads")
			computer_money += 0.1;
		if (quarter.getSideUp() == "Heads")
			computer_money += 0.25;
		cout << "Round " << round_number << endl;
		cout << "Player Money: " << player_money << endl;
		cout << "Computer Money: " << computer_money << endl;
		round_number++;
	}

	if (player_money == computer_money)
		cout << "Draw";
	else if (computer_money >= 1 && player_money >= 1)
		if (computer_money < player_money)
			cout << "Computer Wins";
		else
			cout << "Player Wins";
	else if (computer_money >= 1)
		cout << "Computer Wins";
	else
		cout << "Player Wins";

	return 0;
}

#endif