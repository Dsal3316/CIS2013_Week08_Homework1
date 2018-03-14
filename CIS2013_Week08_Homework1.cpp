#include <iostream>
#include <fstream>

using namespace std;

void print (char field [10][10]);

int main () {
	
	int x,y;
	char b;
	
	ifstream game;
	
	char display_field [10][10];
	char game_buffer [10][10];
	
	int count = 20;
	
	cout << endl;
	cout << "Welcome to Battleship, Please choose a board: Enter 1, 2 or 3 " << endl;
	cin >> b;
	
	if (b== '1') {
		game.open("board1.dat");
	}
	else if (b == '2') {
		game.open("board2.dat");
	}
	else if (b == '3') {
		game.open("board3.dat");
	}
	else {
		cout << "Board not available, purchase DLC addon map pack";
		exit(1);
	}
	
	if(game.fail()) {
		cout << "Something went wrong " << b << endl;
		exit(1);
	}
	else {
		cout << "Beginning game.";
		cout << endl;
	}
	
		char temp_buffer[100];
		game >> temp_buffer;
		
		for (int x = 0; x < 10; x++)
		{
			for (int y = 0; y < 10; y++)
			{
				game_buffer[y][x] = temp_buffer[y * 10 + x];
			}
		}
		
		
		for(int x = 0; x < 10; x++) {
			for(int y = 0; y < 10; y++) {
				display_field[x][y] = '.';
			}
		}
		
		
		
		print(display_field);
		
		while(1) {
			
			cout << endl;
			cout << "Enter coordinate between 0 and 9 " << endl;
			cout << endl;
			cout << "x = ";
			cin >> x;
			cout << "y = ";
			cin >> y;
			cout << endl;
			
			if (cin.fail()) {
				cout << "coordinate does not match";
				exit(1);
			}
			
			if (x > 9 || x < 0 || y < 0 || y > 9)
			{
			cout << "Wrong coordinate";
			
			cout << endl;
			cout << "Enter coordinate between 0 and 9 " << endl;
			cout << endl;
			cout << "x = ";
			cin >> x;
			cout << "y = ";
			cin >> y;
			}
			
			if (display_field[x][y] != '.')
			{
				cout << "Coordinates all ready entered.  Re-enter new coordinates. " << endl;
			}
			else
			{
				
				if (game_buffer[x][y] == 'x')
				{
					display_field[x][y] = 'X';
					cout << "HIT! " << endl;
					count--;
					print(display_field);
					cout << endl;
					if (count==0)
					{
						print(display_field);
						cout << endl;
						cout << "All ships sunk.  Good Game. ";
						
						break;
					}
				}
				
				else 
				{
					
					cout << "MISS!";
					display_field[x][y] = '0';
					
					cout << endl;
					print(display_field);
				}
			}
			
			
			
		cout << "--------------------------------------------";
		}
		return 0;
}

void print (char field [10][10]) {
	
	cout << endl << "		  0 1 2 3 4 5 6 7 8 9" << endl;
	for (int x = 0; x < 10; x++) {
		cout << "		" <<x << " ";
		for (int y = 0; y < 10; y++) {
			cout << field [x][y] << " ";
		}
		cout << endl;
	}
}


		
		
		