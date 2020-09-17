#ifndef APP_CPP
#define APP_CPP

#include <iostream>
#include <string>
#include "Die.hpp"

using namespace std;

int main()
{
	int ai_pts = 0, play_pts = 0;
	Die die1(6);
	Die die2(6);
	string ans;

	//comment
	do {
		die1.roll();
		die2.roll();
		ai_pts += die1.getValue();
		ai_pts += die2.getValue();
		
		die1.roll();
		die2.roll();
		play_pts += die1.getValue();
		play_pts += die2.getValue();

		cout << "Your points: " << play_pts << endl;

		if (play_pts > 21)
			break;

		cout << "AI points: Unknown" << endl;
		cout << "Do you want to roll again? (Put Y or y if yes, N or n if no) ";
		getline(cin, ans);

	} while (ans.at(0) == 'y' || ans.at(0) == 'Y');

	cout << "AI points: " << ai_pts << endl;

	if (play_pts == ai_pts || (play_pts > 21 && ai_pts > 21))
		cout << "Draw!";
	else if (play_pts > 21)
		cout << "AI Wins";
	else if (ai_pts > 21)
		cout << "Player Wins";
	else if (play_pts < ai_pts)
		cout << "AI Wins";
	else
		cout << "Player Wins";

	return 0;
}

#endif