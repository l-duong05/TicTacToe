#include <iostream>
#include <vector>
#include <string>
using namespace std;

void initPlayers(vector<pair<string, char>>& names);
vector<vector<char>> initMap();
void printMap(vector<vector<char>>& map);
void makeMove(vector<vector<char>>& map, pair<string, char>& user);
bool validMove(vector<vector<char>>& map, int row, int col);
bool isDraw(vector<vector<char>>& map);
bool isGameOver(vector<vector<char>>& map, pair<string, char>& user);


int main(void) {
    bool gameOver = false;
    vector<pair<string, char>> names(2);
    initPlayers(names);

    int turn = 0;
    vector<vector<char>> map = initMap();
    printMap(map);
    while (!gameOver) {
        // take input
        makeMove(map, names[turn % 2]);
        if (isDraw(map)) {
            cout << "Game draw!" << endl;
            return 0;
        }
        if (gameOver = isGameOver(map, names[turn++ % 2])) cout << names[(turn - 1) % 2].first << " has won!" << endl;
    }

    return 0;
}


void initPlayers(vector<pair<string, char>>& names) {
    cout << "Game start!" << endl;
    string symb = " ";

    cout << "Enter name for P1: " << endl;
    getline(cin, names[0].first);
    cout << "Enter symbol for " << names[0].first << ": " << endl;
    // extracting a single character even if more is input
    getline(cin, symb);
    if (symb != " ") names[0].second = symb[0];

    cout << "Enter name for P2: " << endl;
    getline(cin, names[1].first);
    cout << "Enter symbol for " << names[1].first << ": " << endl;
    symb = " ";
    getline(cin, symb);
    if (symb != " ") names[1].second = symb[0];
}

vector<vector<char>> initMap() {
    // to add option to resize map later

    vector<vector<char>> map(3, vector<char>(3, ' '));

    return map;
}


void printMap(vector<vector<char>>& map) {
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


void makeMove(vector<vector<char>>& map, pair<string, char>& user) {
    int row, col;

    do {
        // change input for resizing
        cout << "Enter row (0-2) for " << user.first << ":" << endl;
        cin >> row;
        cout << "Enter col (0-2) for " << user.first << ":" << endl;
        cin >> col;
    } while (!validMove(map, row, col));
    
    map[row][col] = user.second;
    printMap(map);
}

bool validMove(vector<vector<char>>& map, int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        cout << "Out of bounds." << endl;
        return false;
    }
    
    if (map[row][col] != ' ') {
        cout << "Position already taken." << endl;
        return false;
    }

    return true;
}


bool isDraw(vector<vector<char>>& map) {
    bool check = false;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (map[i][j] == ' ') return false;
        }
    }

    return true;
}

bool isGameOver(vector<vector<char>>& map, pair<string, char>& user) {
    // vertical and horizontal check
    for (int i = 0; i < 3; i++) {
        if ((map[i][0] != ' ') && (map[i][0] == map[i][1]) && (map[i][0] == map[i][2]) && (map[i][1] == map[i][2])) return true;
        if ((map[0][i] != ' ') && (map[0][i] == map[1][i]) && (map[0][i] == map[2][i]) && (map[2][i] == map[1][i])) return true;
    }

    // diagonal check
    if ((map[0][0] != ' ') && (map[0][0] == map[1][1]) && (map[0][0] == map[2][2]) && (map[1][1] == map[2][2])) return true;
    if ((map[0][2] != ' ') && (map[0][2] == map[1][1]) && (map[0][2] == map[2][0]) && (map[1][1] == map[2][0])) return true;

    return false;
}