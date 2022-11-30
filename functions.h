#include <iostream>
#include <vector>

using namespace std;



void GatheringInfo(string& name, string& age, string& city) {

    cout << "Please enter your Character's name: " << endl;
    cin >> name;
    cout << "Please enter " << name << "'s age: " << endl;
    cin >> age;
    cout << "Please enter the city " << name << " was born in." << endl;
    cin >> city;
    cout << endl;

}

void Greeting() {
    cout << "Hello Young Travaler, welcome to my choose your own adventure game.\n";
    cout << endl;
    cout << "This game you will be able to choose your own weapons to defend yourself and you will also be able to choose your path outside the forrest.\n";
    cout << endl;
    cout << "Whether you get out or not is all dependant on your choices. Good Luck!" << endl;
}
void Opening(string& name, string& age, string& city) {
    cout << "Phone is ringing" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "*ring...*" << endl;
    }
    cout << endl;
    cout << "Dan: " << name << " You need to get out of " << city << " NOW! its being overtaken by monstors." << endl;
    cout << "Please leave now! before its too late. We are only " << age << " years old. We have so much left to live for." << endl;
    cout << "Use the forest to escape. It's dangerous but its the only way. " << endl;
    cout << "I'm leaving right now." << endl;
    cout << "*Phone hangs up*" << endl;
    cout << endl;
}
void Lines() {
    for (int i = 0; i < 150; i++) {
        cout << "-";
    }
    cout << endl;
}

int ChooseWeapon(vector<int>& inResults) {
    // Give Scenario 
    // Get answer
    // Give player that weapon and lock them into a random generator for that said weapon
    int damage;
    ;
    int tool;
    srand(time(NULL));

    cout << "The forrest is dangerous, and you need something to protect yourself from all the dangerous monsters out there" << endl;
    cout << endl;
    cout << "Please choose bettween the weapons we have here to defend yourself. (Enter the number to choose the weapon) " << endl;

    cout << "[1] Knife\n" << "[2] Sword\n" << "[3] Axe\n" << "[4] No Weapon\n";

    cin >> tool;
    inResults.at(0) = tool;



    // Knife: Min: 10hp, Max: 12hp
    // Sword: Min: 15hp, Max: 20hp
    // Axe: Min: 15hp, Max 20hp
      // Fists: Min: 4hp, Max: 6hp
    while (true) {
        if (tool == 1) {
            //knife
            damage = (rand() % (12 - 10 + 1)) + 10;

            return damage;
        }
        else if (tool == 2) {
            //sword
            damage = (rand() % (20 - 15 + 1)) + 15;
            return damage;
        }
        else if (tool == 3) {
            //Axe
            damage = (rand() % (20 - 15 + 1)) + 15;
            return damage;
        }
        else if (tool == 4) {
            //fists
            damage = (rand() % (6 - 4 + 1)) + 4;
            return damage;
        }
        else {
            cout << "You entered the wrong value please try again." << endl;
            cin >> tool;
        }
    }
}

void Endings(int inCounter) {
    int holder = 0;
    if (inCounter == 0) {

        cout << "Congratulations! You completed the game with the 'Pacifist Ending'. Meaning you choose not to fight any enemies.\nPlay again to try to complete the game with a different ending." << endl;
        cout << "Here were your choices: " << endl;
    }

    else if (inCounter == 1 || inCounter == 2) {
        cout << "Congratulations! You completed the game with the 'Normal Ending'.\n Play the game again to find the alternate endings." << endl;
        cout << "Here were your choices: " << endl;
    }

    else {
        cout << "Congratulations! You completed the game with the 'Genocide Ending'. Meaning you choose to fight every enemy and won.\n Play the game again to find the alternate endings." << endl;
        cout << "Here were your choices: " << endl;
    }

}



void Choices(vector<int>& inResults) {

    if (inResults.at(0) == 0) {
        cout << "No Answer." << endl;
    }
    else if (inResults.at(0) == 1) {
        cout << "[1] Knife" << endl;
    }
    else if (inResults.at(0) == 2) {
        cout << "[2] Sword" << endl;
    }
    else if (inResults.at(0) == 3) {
        cout << "[3] Axe" << endl;
    }
    else {
        cout << "[4] No Weapon" << endl;
    }

    // Scenario 1
    if (inResults.at(1) == 0) {
        cout << "No Answer." << endl;
    }
    else if (inResults.at(1) == 1) {
        cout << "[1] Fight Enemy before he wakes up." << endl;
    }
    else {
        cout << "[2] Sneak into the dark path." << endl;
    }

    // Scenario 2
    if (inResults.at(2) == 0) {
        cout << "No Answer." << endl;
    }
    else if (inResults.at(2) == 1) {
        cout << "[1] Take shelter in cave." << endl;
    }
    else {
        cout << "[2] Wonder the night." << endl;
    }

    // Scenario 3
    if (inResults.at(3) == 0) {
        cout << "No Answer." << endl;
    }
    else if (inResults.at(3) == 1) {
        cout << "[1] Attack the monster while it's not looking" << endl;
    }
    else {
        cout << "[2] Try to sneak behind the monster." << endl;
    }

    // Scenario 4
    if (inResults.at(4) == 0) {
        cout << "No Answer." << endl;
    }
    else if (inResults.at(4) == 1) {
        cout << "[1] Attack the monster while it's not looking" << endl;
    }
    else {
        cout << "[2] Try to sneak behind the monster." << endl;
    }
}

void fillVector(vector<int>& inResults) {
    for (int i = 0; i < inResults.size(); i++) {
        inResults.at(i) = 0;
    }
}

