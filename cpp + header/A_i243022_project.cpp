#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
#include "classes.h"
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
using namespace std;
//Name: Mussa Raza, Roll Number: 24I-3022, Project#1


int main() {
    srand(time(0));
    string username;
    PlaySound(TEXT("menusong.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    cout << "Enter the User Name: ";
    getline(cin, username);
    Game g1(username);
    ifstream testFile((username + "_save.txt").c_str());
    if (testFile.good()) {
        testFile.close();
        cout << "Found saved game for " << username << ". Load it? (y/n): ";
        char choice;
        cin >> choice;
        cin.ignore();
        if (tolower(choice) == 'y') {
            g1.LoadingGame();
        }
    }
    g1.state();
    //PlaySound(0, 0, 0);
    return 0;
}