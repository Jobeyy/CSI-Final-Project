#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

#include "class.h"

// Methods Refering to class Player
Player::Player() {
	playerName = "NoName";
	playerAge = "-1";
	playerCity = "NoCity";
	health = 100;
	weapon = "NoWeapon";

	//cout << "Player was made." << endl;
}

Player::Player(string inName, string inAge, string inCity) {
	playerName = inName;
	playerAge = inAge;
	playerCity = inCity;
	health = 100;
	weapon = "NoWeapon";
	//cout << "Player was made." << endl;
}

void Player::SetPlayer(string inName, string inAge, string inCity) {
	playerName = inName;
	playerAge = inAge;
	playerCity = inCity;
}

string Player::GetPlayerName() const {
	return playerName;
}

string Player::GetPlayerAge() const {
	return playerAge;
}

string Player::GetPlayerCity() const {
	return playerCity;
}

void Player::LowerHealth(int inDamage) {
	health = health - inDamage;
}

void Player::SetWeapon(string inWeapon) {
	weapon = inWeapon;
}

string Player::GetWeapon() const {
	return weapon;
}

void Player::GetHealth() {
	cout << health << "hp" << endl;
}
int Player::ReturnHealth() {
	return health;
}


// Start of class game

void Game::LevelOne(int inWeaponDamg, Player& inFirstPlayer, vector<int>& inResults, int& counter) {

	int answer = 0;
	int choice = 0;
	int enemyHealth = 20;
	const int DMG = 5;
	// Scenario 1
	cout << "Your main goal is to get out of the forest alive your decisions will determine if you succeed. \n";
	cout << endl;
	cout << "After choosing your weapon, you decide to go out and explore the forest. Walking for around 20 minutes, \nyou run into a sleeping enemy blocking the main path.\n";
	cout << endl;
	cout << "There is a dark path to the right of him that might allow you to sneak around if. \n";
	cout << "However, if you get caught you will be in a terrible spot and will most likely not make it. Which option do you choose?\n";
	cout << endl;
	cout << "[1] Fight Enemy before he wakes up." << endl;
	cout << "[2] Sneak into the dark path." << endl;
	// End of Scenario 1

	cin >> answer;

	inResults.at(1) = answer;

	if (answer == 1) {

		while (enemyHealth > 0) {

			cout << "You attacked the monster and deal " << inWeaponDamg << "hp of damage." << endl;
			enemyHealth -= inWeaponDamg;
			cout << "The monster's health is now " << enemyHealth << endl;

			if (enemyHealth > 0) {
				cout << "The monster decided to attack dealing 5hp" << endl;
				inFirstPlayer.LowerHealth(DMG);
			}

			else {
				cout << "Your health: ";
				inFirstPlayer.GetHealth();
			}

		}
		if (enemyHealth <= 0) {
			counter++;
		}

	}
	else if (answer == 2) {
		srand(time(0));
		choice = (rand() % 2) + 1;

		if (choice == 1) {
			cout << "Congradulations you successfully Escaped!" << endl;
		}
		else if (choice == 2) {
			cout << "Unfortunately.. the monster woke up.. You lost 50hp for your risky decision but got away." << endl;
			inFirstPlayer.LowerHealth(50);

			cout << "Your health is now: ";
			inFirstPlayer.GetHealth();
		}


	}

}

bool Game::LevelTwo(Player& inFirstPlayer, vector<int>& inResults) {

	// Scenario 2

	int answer = 0;
	bool alive = true;
	cout << "It took you roughly 40 mins to get past the first monster, nightfall is upon you and happen to run into a cave.\n The nighttime is very harsh but you could cover alot of distance if you continued.\n However, it could mean certain death. What do you do? \n\n[1] Take shelter in cave.\n[2] Wonder the night" << endl;

	// End of Scenario 2

	cin >> answer;

	inResults.at(2) = answer;

	if (answer == 1) {
		cout << "You safely hid in the cave throughout the night. \n there were some noises throughout the night but other than that nothing out of the ordinary.\n";
		return alive;
	}

	else if (answer == 2) {
		cout << "Unfortunately you were attacked in the dead of night and did not make it." << endl;
		alive = false;
		return alive;
	}

}



bool Game::LevelThree(int inWeaponDamg, Player& inFirstPlayer, vector<int>& inResults, int& counter) {
	bool alive = true;
	int answer = 0;
	int choice = 0;
	int enemyHealth = 35;
	const int DMG = 15;
	// Scenario 3

	cout << "After spending the night in the cave, you decide it's time to get moving to ensure your escape. \nAfter a while of traveling you run into another monster hiding in the trees scouting. \nThis monster is larger than the rest of them but hasn't noticed you just yet. What do you do?\n";
	cout << endl;
	cout << "[1] Attack the monster while it's not looking\n[2] Try to sneak behind the monster\n";
	// End of Scenario 3

	cin >> answer;

	inResults.at(3) = answer;

	if (answer == 1) {

		while (enemyHealth > 0) {

			if (inFirstPlayer.ReturnHealth() <= 0) {
				cout << "Player Health: ";
				inFirstPlayer.GetHealth();
				cout << "Sorry You have run out of health." << endl;
				alive = false;
				break;
			}
			cout << "You attacked the monster and deal " << inWeaponDamg << "hp of damage." << endl;
			enemyHealth -= inWeaponDamg;
			cout << "The monster's health is now " << enemyHealth << endl;

			if (enemyHealth > 0) {
				cout << "The monster decided to attack dealing " << DMG << "hp" << endl;
				inFirstPlayer.LowerHealth(DMG);
			}

			else {
				cout << "Your health: ";
				inFirstPlayer.GetHealth();
			}

		}
		if (enemyHealth <= 0) {
			counter++;
		}

	}
	else if (answer == 2) {
		srand(time(0));
		choice = (rand() % 2) + 1;

		if (choice == 1) {
			cout << "Congratulations you successfully Escaped!" << endl;
		}
		else if (choice == 2) {
			cout << "Unfortunately.. the monster woke up.. You lost 50hp for your risky decision but got away." << endl;
			inFirstPlayer.LowerHealth(50);

			cout << "Your health is now: ";
			inFirstPlayer.GetHealth();

			if (inFirstPlayer.ReturnHealth() <= 0) {
				cout << "Player Health: ";
				inFirstPlayer.GetHealth();
				cout << "Sorry You have run out of health." << endl;
				alive = false;
			}
		}


	}
	return alive;

}


bool Game::LevelFour(int inWeaponDamg, Player& inFirstPlayer, vector<int>& inResults, int& counter) {
	bool alive = true;
	int answer = 0;
	int choice = 0;
	int enemyHealth = 40;
	const int DMG = 20;
	// Scenario 4

	cout << "You finally see the exit to the forest. There is one last giant monster standing in your way.\n You see Dan on the other side waiting for you do you try to get away from the monster or fight?\n";
	cout << endl;
	cout << "[1] Fight the monster.\n[2] Attempt to get away. \n";
	// End of Scenario 4

	cin >> answer;

	inResults.at(4) = answer;

	if (answer == 1) {

		while (enemyHealth > 0) {

			if (inFirstPlayer.ReturnHealth() <= 0) {
				cout << "Player Health: ";
				inFirstPlayer.GetHealth();
				cout << "Sorry You have run out of health." << endl;
				alive = false;
				break;
			}
			cout << "You attacked the monster and deal " << inWeaponDamg << "hp of damage." << endl;
			enemyHealth -= inWeaponDamg;
			cout << "The monster's health is now " << enemyHealth << endl;

			if (enemyHealth > 0) {
				cout << "The monster decided to attack dealing " << DMG << "hp" << endl;
				inFirstPlayer.LowerHealth(DMG);
			}

			else {
				cout << "Your health: ";
				inFirstPlayer.GetHealth();
			}

		}
		if (enemyHealth <= 0) {
			counter++;
		}

	}
	else if (answer == 2) {
		srand(time(0));
		choice = (rand() % 2) + 1;

		if (choice == 1) {
			cout << "Congratulations you successfully Escaped!" << endl;
		}
		else if (choice == 2) {
			cout << "Unfortunately.. the monster woke up.. You lost 50hp for your risky decision but got away." << endl;
			inFirstPlayer.LowerHealth(50);

			cout << "Your health is now: ";
			inFirstPlayer.GetHealth();

			if (inFirstPlayer.ReturnHealth() <= 0) {
				cout << "Player Health: ";
				inFirstPlayer.GetHealth();
				cout << "Sorry You have run out of health." << endl;
				alive = false;
			}
		}


	}
	return alive;

}






