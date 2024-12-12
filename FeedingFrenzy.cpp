#include <iostream>
#include <fstream>
#include <windows.h>
#include <cmath>
#include <ctime>
#include <ncurses/ncurses.h>
using namespace std;

bool gameOver = false;                                    
char character = 'O';
const int lebar = 50;                           
const int tinggi = 20;                       
int x, y, posisiBuahX, posisiBuahY, skor;
enum eArah { BERHENTI = 0, KIRI, KANAN, ATAS, BAWAH };    
eArah arah;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

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

void SignUp() {
    ofstream myFile, accList;
    string username, password;

    system("cls");
    gotoxy(42,13);
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
    cout << "SIGN UP" << endl;
    gotoxy(45,14);
    cout << "Enter Username : ";
    cin >> username;
    gotoxy(45,15);
    cout << "Enter Password : ";
    cin >> password;
    cout << endl;
    
    gotoxy(40,19);
	cout << "****************************************";

    myFile.open(username + ".txt");
    if (!myFile) {
        cout << "Error opening file for user data!" << endl;
        return;
    }
    myFile << password;
    myFile.close();

    accList.open("ListAccount.txt", ios::app);
    if (!accList) {
        cout << "Error opening account list!" << endl;
        return;
    }
    accList << username << endl;
    accList.close();
	
	gotoxy(50,17);
    cout <<"Sign Up Successful!" << endl;
    cin.ignore();
    cin.get();
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
void getConsoleSize(int &width, int &height) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}
void loadingAnimation() {
    int WIDTH, HEIGHT;
    getConsoleSize(WIDTH, HEIGHT); 
    
    double amplitude1 = HEIGHT / 8.0; 
    double amplitude2 = HEIGHT / 10.0;
    double frequency = 4;

    for (int i = 0; i < WIDTH; i++) {
        int x = i % WIDTH;
        int y1 = (int)(amplitude1 * sin(frequency * i));
        int y2 = (int)(amplitude2 * sin(frequency * i + M_PI));
        int y3 = (int)(amplitude1 * sin(frequency * i + M_PI));
        int y4 = (int)(amplitude2 * sin(frequency * i));

        gotoxy(x, HEIGHT / 4 + y1);
        cout << "{==>>";
        gotoxy(x + 7, HEIGHT / 4 + y2);
        cout << "*";

        gotoxy(x, 3 * HEIGHT / 4 + y3); 
        cout << "{==>>";
        gotoxy(x + 7, 3 * HEIGHT / 4 + y4);
        cout << "*";

        Sleep(50);

        gotoxy(WIDTH / 2 - 10, HEIGHT / 2); 
        cout << "WELCOME TO OUR GAME";

        Sleep(5);
    }
}
void Logic()                           
{
    switch (arah)
    {
    case KIRI:
		character = '<';                   
        x--;
        break;
    case KANAN:
    	character = '>';
        x++;
        break;
    case ATAS:
    	character = '^';
        y--;
        break;
    case BAWAH:
    	character = 'v';
        y++;
        break;
    default:
    	break;
    	
    }
    if (x >= lebar -1 || x < 0 || y >= tinggi-1 || y < 0)   
        gameOver = true;

    if (x == posisiBuahX && y == posisiBuahY)
    {
        srand(time(0));
        skor += 2;
        posisiBuahX = (rand() % (lebar - 2)) + 1;     
        posisiBuahY = (rand() % (tinggi - 2)) + 1;
    }
}

int main(){
}
