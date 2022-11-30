// Final Project For Computer Science I
// UTRGV 
// Choose Your own adventure game

// Project made by Jose Agusin Farias


// There are 4 different endings.
// 1. Fighting and beating all the enemies
// 2. Running away from all the enemies
// 3. Fighting some and running from some enemies
// 4. Lose all your health

// Player starts off with 100 health
// Player can deal damage depending on weapon
// all enemies have 20 health

// Weapons: Fists, Knife, Sword, Axe
// Fists: Min: 4hp, Max: 6hp
// Knife: Min: 10hp, Max: 12hp
// Sword: Min: 15hp, Max: 20hp
// Axe: Min: 15hp, Max 20hp



#include <iostream>
#include <vector>
using namespace std;

#include "class.h"
#include "functions.h"

int main()
{
    bool alive = true;
    string name, age, city;
    int counter = 0; // counter for how many enemies have been defeated.
    int weaponDamg;
    const int VECTOR_SIZE = 5;
    vector<int> results(VECTOR_SIZE);


    Lines();
    Greeting();
    Lines();



    // Created a class called player


    Game StartGame;

    char answer;

    cout << "Are you ready to begin the game?(y/n)" << endl;
    cin >> answer;
    
        fillVector(results);
      
            // Beginning of Game
            if (answer == 'y') {

                GatheringInfo(name, age, city);

                Lines();
                Opening(name, age, city);
                Lines();


                Player FirstPlayer(name, age, city);


                weaponDamg = ChooseWeapon(results);

                Lines();
                StartGame.LevelOne(weaponDamg, FirstPlayer, results, counter);
                Lines();
                if (!alive) {
                    // Need to output all of the options that have been chosen so far
                    cout << "Here were all of your choices: " << endl;
                    Choices(results);
                    return 0;
                }

                alive = StartGame.LevelTwo(FirstPlayer, results);
                Lines();
                if (!alive) {
                    cout << "Here were all of your choices: " << endl;
                    Choices(results);
                    return 0;
                }

                alive = StartGame.LevelThree(weaponDamg, FirstPlayer, results, counter);
                Lines();
                if (!alive) {
                    cout << "Here were all of your choices: " << endl;
                    Choices(results);
                    return 0;
                }

                alive = StartGame.LevelFour(weaponDamg, FirstPlayer, results, counter);
                Lines();
                if (!alive) {
                    cout << "Here were all of your choices: " << endl;
                    Choices(results);
                    return 0;
                }

                if (alive) {
                    Endings(counter);
                    cout << "Here were all of your choices: " << endl;
                    Choices(results);
                    return 0;
                }


            }
            else {
                cout << "Have a good day!" << endl;
              

            }






        



    return 0;
}