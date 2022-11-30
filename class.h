// This includes Functions and Classes

#include <iostream>
#include <vector>
using namespace std;



class Player {
public:
    Player(); // Default Constructor No parameters

    // Constructor with Parameters
    Player(string inName, string inAge, string inCity);

    // Only made SetPlayer In case of defautl parameter is used.
    void SetPlayer(string inName, string inAge, string inCity); // Sets the players' info
    void LowerHealth(int inDamage);
    string GetPlayerName() const; // Gets name
    string GetPlayerAge() const; // Gets Age
    string GetPlayerCity() const; // Gets City;
    void SetWeapon(string inWeapon); // Sets Weapon
    string GetWeapon() const; // Gets Weapon
    void GetHealth();
    int ReturnHealth();


private:
    string playerName;
    string playerAge;
    string playerCity;
    int health;
    string weapon;

};


class Game {
public:

    void LevelOne(int inWeaponDamg, Player& inFirstPlayer, vector<int>& inResults, int& counter);

    bool LevelTwo(Player& inFirstPlayer, vector<int>& inResults);

    bool LevelThree(int inWeaponDamg, Player& inFirstPlayer, vector<int>& inResults, int& counter);

    bool LevelFour(int inWeaponDamg, Player& inFirstPlayer, vector<int>& inResults, int& counter);


};








