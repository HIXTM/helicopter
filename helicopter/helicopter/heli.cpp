#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

char helicopter = '^';
char obstacle = '#';
char finishLine = '=';
int posX = 10, posY = 10;
vector<pair<int, int>> obstacles;
bool finish = false;

void setup() {
    system("cls");
    obstacles.clear();
    for (int i = 0; i < 25; i++) {
        int obsX = rand() % 20;
        int obsY = rand() % 19;
        obstacles.push_back({ obsY, obsX });
    }
}

void draw() {
    system("cls");
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (i == posY && j == posX) {
                cout << helicopter;
            }
            else if (i == 19) {
                cout << finishLine;
            }
            else {
                bool isObstacle = false;
                for (auto& obs : obstacles) {
                    if (obs.first == i && obs.second == j) {
                        cout << obstacle;
                        isObstacle = true;
                        break;
                    }
                }
                if (!isObstacle)
                    cout << '.';
            }
        }
        cout << endl;
    }
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'w': posY--; break;
        case 's': posY++; break;
        case 'a': posX--; break;
        case 'd': posX++; break;
        case 'x': exit(0); 
        }
    }
}

void logic() {
    if (posX < 0) posX = 0;
    if (posX > 19) posX = 19;
    if (posY < 0) posY = 0;
    if (posY > 19) posY = 19;

    for (auto& obs : obstacles) {
        if (obs.first == posY && obs.second == posX) {
            cout << "Game Over! You hit an obstacle!" << endl;
            exit(0);
        }
    }

    if (posY == 19) {
        finish = true;
        cout << "Congratulations! You've reached the finish line!" << endl;
        exit(0);
    }
}

int main() {
    srand(time(0));
    setup();
    while (true) {
        draw();
        input();
        logic();
        Sleep(100);
    }
    return 0;
}

