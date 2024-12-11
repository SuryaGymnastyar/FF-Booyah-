#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <cmath>
#include <ctime>
#include <ncurses/ncurses.h>
using namespace std;

void loadingawal() {
    system("color 3F");
	initscr();
	
	curs_set(0);
	
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	init_pair(2, COLOR_WHITE, COLOR_CYAN);	
	
	bkgd(COLOR_PAIR(2));
	
	attron(COLOR_PAIR(2));
	
	mvprintw(0,39," ______                _  _                ");                              
    mvprintw(1,39,"|  ____|              | |(_)               ");
    mvprintw(2,39,"| |                   | |                  ");
    mvprintw(3,39,"| |__   ___   ___   __| | _  _ __    __ _  ");
    mvprintw(4,39,"|  __| / _ \\ / _ \\ / _` || || '_ \\  / _` | ");
    mvprintw(5,39,"| |   |  __/|  __/| (_| || || | | || (_| | ");
    mvprintw(6,39,"|_|    \\___| \\___| \\__,_||_||_| |_| \\__  | ");
    mvprintw(7,39,"                                    __/  | ");                                  
    mvprintw(8,39,"                                   |____/  ");
	
	mvprintw(9, 40, "****************************************");
	
	for (int i = 10; i <= 18; i++) {
    mvprintw(i, 40, "*");
    mvprintw(i, 79, "*");
}

	mvprintw(12, 50, "     LOGGED IN...   ");
	mvprintw(13, 50, " ------------------ ");
	mvprintw(14, 50, "|                  |");
	mvprintw(15, 50, " ------------------ ");
	
	mvprintw(19, 40, "****************************************");
	
	mvprintw(20,39," ______                              ");                              
    mvprintw(21,39,"|  ____|                             ");
    mvprintw(22,39,"| |     _ __   ___  _ __     _____  _   _ ");
    mvprintw(23,39,"| |__  | '__| / _ \\| '_ \\   |_   / | | | |");
    mvprintw(24,39,"|  __| | |   |  __/| | | |   /  /  | | | |");
    mvprintw(25,39,"| |    | |   |   \\ | | | |  /  /   | |_| |");
    mvprintw(26,39,"|_|    |_|    \\___||_| |_| /____|   \\__, |");
    mvprintw(27,39,"                                     __/ |");                                  
    mvprintw(28,39,"                                    |___/ ");     
		
	int load = 1;
		
	for (int j = 1; j <= 100; j++){
	if (j % 6 == 0 ) load++;
	attron(COLOR_PAIR(1));
	mvprintw(14, 50 + load, " ");
	attron(COLOR_PAIR(2));
	mvprintw(16, 54, "Loading ");
	mvprintw(16, 63, "  %%", j);
	mvprintw(16, 62, "%d");
	refresh();
	Sleep(50);
	}
	
	endwin();
}

bool SignIn() {
    ifstream myFile;
    string username, password, fileUsername, filePassword;
    bool exist = false;

    system("cls");
    gotoxy(40, 9);
	cout << "****************************************";
	
	for (int i = 10; i <= 18; i++) {
    gotoxy(40, i);
	cout << "*";
    gotoxy(79, i);
	cout << "*";
}
	gotoxy(40,19);
	cout << "****************************************";

    gotoxy(56,11);
    cout << "SIGN IN" << endl;
    gotoxy(45,14);
    cout << "Enter Username : ";
    cin >> username;
    gotoxy(45,15);
    cout << "Enter Password : ";
    cin >> password;
    cout << endl;

    myFile.open(username + ".txt");
    if (!myFile) {
        cout << "Error opening user file!" << endl;
        return false;
    }

    getline(myFile, filePassword);
    if (filePassword == password) {
        exist = true;
    }
    myFile.close();

    if (exist) {
    	gotoxy(50,17);
        cout << "Sign In Successful!" << endl;
        cin.ignore();
        cin.get();
        return true;
    } else {
    	gotoxy(47,17);
        cout << "Sign In Failed! Try Again." << endl;
        cin.ignore();
        cin.get();
        return false;
    }
}
