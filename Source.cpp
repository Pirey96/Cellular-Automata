#include <iostream>
#include <windows.h> // for sleep()
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
#define SIZE 2150
#define DIMENSION sqrt(SIZE)
#define sleep(a) Sleep (a*1000) 
void nextState(string);
std::string State();
//global and proto
void goback();
void hideCursor();
void setInitialState(int);

char a[SIZE];

int main()
{
	cout << "Input seed: ";
	int seed;
	cin >> seed;
	system("CLS");
	hideCursor();
	setInitialState(seed);

	double row = sqrt(SIZE);
	string str;
	for (;;) {
		goback();
		str = State();
		cout << str;
		nextState(str);
		sleep(0.1);


	}
	return 0;
}
string State() {
	std::string str = "";
	int temp = sqrt(SIZE);
	for (int i = 0; i < SIZE; i++) {
		if (i % temp == 0) {
			//str += a[i];
			str += '\n';
		}
		str += a[i];
		str += ' ';
	}
	return str;

}
void nextState(string str) {
	int row = sqrt(SIZE);
	//cout << a[0+row] << endl;
	//update(str);
	int life[SIZE];

	for (int i = 0; i < SIZE; i++) {
		life[i] = 0;
		//FOUR CORNERS
		if (i == 0 || i == row || i == SIZE - row || i == SIZE) {

			if (i == 0) {
				//cout << endl << a[i + row]<< "SASUKE ";
				if (a[i + 1] == '*') {
					life[i] += 1;
				}if (a[i + row] == '*') {
					life[i] += 1;
					//cout <<endl<< "SASUKEEEE" << endl;

				}if (a[i + row + 1] == '*') {
					life[i] += 1;
				}
			}
			else if (i == row) {
				if (a[i - 1] == '*') {
					life[i] += 1;
				}if (a[i + row] == '*') {
					life[i] += 1;
				}if (a[i + row - 1] == '*') {
					life[i] += 1;
				}
			}
			else if (i == SIZE - row) {
				if (a[i - row] == '*') {
					life[i] += 1;
				}if (a[i - row + 1] == '*') {
					life[i] += 1;
				}if (a[i + 1] == '*') {
					life[i] += 1;
				}
			}
			else if (i == SIZE) {
				if (a[i - 1] == '*') {
					life[i] += 1;
				}if (a[i - row] == '*') {
					life[i] += 1;
				}if (a[i - row - 1] == '*') {
					life[i] += 1;
				}
			}
		}//FOUR CORNERS END
		 //LEFT RIGHT
		else if (i % row == 0 || (i + 1) % (row) == 0) {
			if (i % row == 0) {
				if (a[i - row] == '*') {
					life[i] += 1;
				}if (a[i - row + 1] == '*') {
					life[i] += 1;
				}if (a[i + 1] == '*') {
					life[i] += 1;
				}if (a[i + row] == '*') {
					life[i] += 1;
				}if (a[i + row + 1] == '*') {
					life[i] += 1;
				}
			}
			else {
				if (a[i - row] == '*') {
					life[i] += 1;
				}if (a[i - row - 1] == '*') {
					life[i] += 1;
				}if (a[i - 1] == '*') {
					life[i] += 1;
				}if (a[i + row] == '*') {
					life[i] += 1;
				}if (a[i + row - 1] == '*') {
					life[i] += 1;
				}

			}
		}//END LEFT RIGHT
			 //UP DOWN
		else if (i < row || i > SIZE - row) {
			if (i < row) {
				if (a[i - 1] == '*') {
					life[i] += 1;
				}if (a[i + 1] == '*') {
					life[i] += 1;
				}if (a[i + row] == '*') {
					life[i] += 1;
				}if (a[i + row + 1] == '*') {
					life[i] += 1;
				}if (a[i + row - 1] == '*') {
					life[i] += 1;
				}
			}
			else {
				if (a[i - 1] == '*') {
					life[i] += 1;
				}if (a[i + 1] == '*') {
					life[i] += 1;
				}if (a[i - row] == '*') {
					life[i] += 1;
				}if (a[i - row + 1] == '*') {
					life[i] += 1;
				}if (a[i - row - 1] == '*') {
					life[i] += 1;
				}
			}
		}
		else {
			if (a[i - 1] == '*') {
				life[i] += 1;
			}if (a[i + 1] == '*') {
				life[i] += 1;
			}if (a[i - row] == '*') {
				life[i] += 1;
			}if (a[i - row + 1] == '*') {
				life[i] += 1;
			}if (a[i - row - 1] == '*') {
				life[i] += 1;
			}if (a[i + row] == '*') {
				life[i] += 1;
			}if (a[i + row + 1] == '*') {
				life[i] += 1;
			}if (a[i + row - 1] == '*') {
				life[i] += 1;
			}

		}
	}

	for (int i = 0; i < SIZE; i++) {
		//cout << life[i];
		if (a[i] == ' ' && life[i] == 3) {
			a[i] = '*';
		}
		else if (a[i] == '*' && (life[i] < 2 || life[i] > 3)) {
			a[i] = ' ';
		}
		else {
			a[i] = a[i];
		}
	}
}





void setInitialState(int seed) {
	//generate random seed as an initial state for the program
	srand(seed);
	for (int i = 0; i < SIZE; i++) {
		int randomint = rand() % 2;
		//cout << randomint;
		if (randomint == 0) {
			a[i] = '*';
		}
		else a[i] = ' ';
	}

}

//View

void goback() {
	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor() {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	//GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.dwSize = 100;
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);

}