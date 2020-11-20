#pragma once

#include <string>
#include<fstream>

static char board_saved[3][3];
using namespace std;

class Files {
public:


    static void ReadFile() {

        string path = "C:\\Programming\\game.txt";
        ifstream file;
        file.open(path);

        string temp;
        string total;
        char val;
        if (file.is_open()) {

            for (int i = 0; i < 3; i++) {

                for (int j = 0; j < 3; j++) {
                    val = '0';
                    file >> temp;
                    if (temp == "1") { val = 'x'; }
                    else if (temp == "3") { val = ' '; }
                    board_saved[i][j] = val;
                }
            }

            file.close();

        }

    }


    static void ReWriteGameFile() {
        string path = "C:\\Programming\\game.txt";
        ofstream out;          // поток для записи
        out.open(path); // открываем файл для записи
        char val;
        int count = 0;
        if (out.is_open()) {

            for (int i = 0; i < 3; i++) {

                for (int j = 0; j < 3; j++) {
                    if (board_saved[i][j] == ' ') {
                        out << 3;
                    } else if (board_saved[i][j] == '0') {
                        out << 0;
                    } else {
                        out << 1;
                    }
                    count += 1;
                    if (count <= 9) {
                        out << ' ';
                    }
                }
            }
        }
        out.close();
    }



static void AddToFileX(int X, int Y) {
    string path = "C:\\Programming\\log.txt";
        ofstream out;          // поток для записи
    out.open(path, ios::app); // открываем файл для записи
    if (out.is_open()) {
        out << "Ход крестика:\nX - " << X << "\nY - " << Y << endl;
    }
    out.close();
}

    static void AddToFile0(int X, int Y) {
        string path = "C:\\Programming\\log.txt";
        ofstream out;          // поток для записи
        out.open(path, ios::app); // открываем файл для записи
        if (out.is_open()) {
            out << "Ход нолика:\nX - " << X << "\nY - " << Y << endl;
        }
        out.close();
    }

static void ClearLog() {
    string path = "C:\\Programming\\log.txt";
    ofstream out;          // поток для записи
    out.open(path); // открываем файл для записи
    if (out.is_open()) {
        out << "";

    }
    out.close();

}

};
