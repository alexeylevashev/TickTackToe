// Игра "Крестики-Нолики".
// Предусмотреть возможность журналирования ходов и возможности сохранения состояния игры.

#include<fstream>
#include <iostream>
#include <stdlib.h>
#include"Files.h"



using namespace std;

int main() {

    system("chcp 65001");

    const int SIZE = 3;
    char board[SIZE][SIZE] = {{' ', ' ', ' '},
                              {' ', ' ', ' '},
                              {' ', ' ', ' '}};

    cout << "Игра - Крестики-Нолики" << endl << endl;
    cout << "Для загрузки сохраненной игры - нажмите 1" << endl;
    cout << "Для запуска новой игры - нажмите 0" << endl;
    int choice;
    cin >> choice;
    if (choice == 1) {

        Files::ReadFile();

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
               board[i][j]=board_saved[i][j];
            }
        }

    } else {
       Files::ClearLog();
    };


    for (int i = 0; i < 3; i++) {
        cout << "\t | \t";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            cout << "\t | \t";
        }
        cout << endl;
    }

    int x, y;
    bool winX = false;
    bool win0 = false;
    int count = 0;

    cout << "Ход Крестика" << endl;
    do {

        do {
            do {
                cout << "Введите координату x: ";
                cin >> x;
                cout << "Введите координату y: ";
                cin >> y;
            } while (x < 0 || y < 0 || x > 2 || y > 2);
        } while (board[x][y] == '0' || board[x][y] == 'x');
        board[x][y] = 'x';
        count++;

        Files::AddToFileX(x,y);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board_saved[i][j]=board[i][j];
            }
        }
        Files::ReWriteGameFile();


        if (board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x') {
            winX = true;
        }
        if (board[2][0] == 'x' && board[1][1] == 'x' && board[0][2] == 'x') {
            winX = true;
        }
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == 'x' && board[i][1] == 'x' && board[i][2] == 'x') winX = true;
            if (board[0][i] == 'x' && board[1][i] == 'x' && board[2][i] == 'x') winX = true;
        }


        for (int i = 0; i < 3; i++) {
            cout << "\t | \t";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                cout << "\t | \t";
            }
            cout << endl;
        }


        cout << "Ход Нолика" << endl;
        do {
            do {
                cout << "Введите координату x: ";
                cin >> x;
                cout << "Введите координату y: ";
                cin >> y;
            } while (x < 0 || y < 0 || x > 2 || y > 2);
        } while (board[x][y] == '0' || board[x][y] == 'x');
        board[x][y] = '0';
        count++;

        Files::AddToFile0(x,y);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board_saved[i][j]=board[i][j];
            }
        }
        Files::ReWriteGameFile();


        if (board[0][0] == '0' && board[1][1] == '0' && board[2][2] == '0') {
            win0 = true;
        }
        if (board[2][0] == '0' && board[1][1] == '0' && board[0][2] == '0') {
            win0 = true;
        }
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == '0' && board[i][1] == '0' && board[i][2] == '0') win0 = true;
            if (board[0][i] == '0' && board[1][i] == '0' && board[2][i] == '0') win0 = true;
        }


        for (int i = 0; i < 3; i++) {
            cout << "\t | \t";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                cout << "\t | \t";
            }
            cout << endl;
        }

    } while (!winX && !win0 && count != 9);

    if (winX) {
        cout << "Выиграл Крестик!" << endl;
    } else if (win0) {
        cout << "Выиграл Нолик!" << endl;
    } else {
        cout << "Ничья!" << endl;
    }
}

