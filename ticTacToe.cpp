#include <iostream>
#include <vector>
#include <string>
using namespace std;

void initPlayers(vector<string>& names);

int main(void) {
    bool gameOver = false;
    vector<string> names(2);
    initPlayers(names);

    int turn = 0;
    // while (!gameOver)
    // {
    //     // run stuff here
    // }

    return 0;
}

void initPlayers(vector<string>& names) {
    cout << "Game start!" << endl;
    cout << "Enter name for P1: " << endl;
    getline(cin, names[0]);
    cout << "Enter name for P2: " << endl;
    getline(cin, names[1]);
}

void initMap() {

}

void makeMove() {

}

bool isGameOver() {
    
}
