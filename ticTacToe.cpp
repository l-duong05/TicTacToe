#include <iostream>
#include <vector>
#include <string>
using namespace std;

void initPlayers(vector<pair<string, char>>& names);
vector<vector<char>> initMap();
void printMap(vector<vector<char>> map);

int main(void) {
    bool gameOver = false;
    vector<pair<string, char>> names(2);
    initPlayers(names);

    int turn = 0;
    vector<vector<char>> map = initMap();
    printMap(map);
    // while (!gameOver)
    // {
    //     // run stuff here
    // }

    return 0;
}

void initPlayers(vector<pair<string, char>>& names) {
    cout << "Game start!" << endl;

    cout << "Enter name for P1: " << endl;
    getline(cin, names[0].first);
    cout << "Enter symbol for " << names[0].first << ": " << endl;
    names[0].second = getchar();

    cout << "Enter name for P2: " << endl;
    getline(cin, names[1].first);
    cout << "Enter symbol for " << names[1].first << ": " << endl;
    names[1].second = getchar();
}

vector<vector<char>> initMap() {
    // to add option to resize map

    vector<vector<char>> map(3, vector<char>(3, ' '));

    return map;
}

void printMap(vector<vector<char>> map) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 2) {
                cout << " " << map[i][j] << " " << endl;
            } else {
                cout << " " << map[i][j] << " " << "|";
            }
        }
        if (i != 2) {
            cout << "------------" << endl;
        }
    }
}

void makeMove() {

}

bool isGameOver() {
    return false;
}