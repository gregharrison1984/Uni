#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <conio.h>
#include <windows.h>
#include <cstdlib>    
#include <time.h>
#include <string>
#include <iostream>
#include <iomanip> 
#include <mmsystem.h>

using namespace std;

//GLobals
int totalBalance = 500;
int stake = 0;
int balance = 0;
int spinspeed = 50;

//Declare Functions
void setwheel();
void clearScreen();
void playPuggy();
void homePage();
void stakeAmount();
void SpinWheel1();
void SpinWheel2();
void SpinWheel3();
void SpinWheel4();
void SpinWheel5();
void compareResults();
void spinAndCompare();
void outputMachine();
void setupPuggy();
void paytable();
void gamble();


// compare these after all 3 spins (Globals)
char wheel1Result_1, wheel1Result_2, wheel1Result_3, wheel1Result_4, wheel1Result_5;
char wheel2Result_1, wheel2Result_2, wheel2Result_3, wheel2Result_4, wheel2Result_5;
char wheel3Result_1, wheel3Result_2, wheel3Result_3, wheel3Result_4, wheel3Result_5;
char wheel4Result_1, wheel4Result_2, wheel4Result_3, wheel4Result_4, wheel4Result_5;
char wheel5Result_1, wheel5Result_2, wheel5Result_3, wheel5Result_4, wheel5Result_5; //2D Array? 5 x 1D Arrays???


// [row][column](Globals)
char slotMachine[15][5]; //The output display (only 5 x 5 shown)
char wheel[15]; // To set the characters in the wheel(done in void setwheel())
int spinIndex[15] = { 0,14,13,12,10,9,8,7,6,5,4,3,2,1 };



void setwheel()//To create a unique wheel for each game
{
	for (int x = 0; x < 15; x++)
	{
		int y = rand() % 5 + 1;
		char i;
		switch (y)
		{
		case 1: i = 'A'; break;
		case 2: i = 'K'; break;
		case 3: i = 'Q'; break;
		case 4: i = 'J'; break;
		case 5: i = '*'; break;
		}

		wheel[x] = i;
	}
}

void clearScreen()//Created a function call to clear screen
{
	system("CLS");
}

void playPuggy()
{
	setupPuggy();
	outputMachine();
}

void homePage() // set up the main menu in homePage as opposed to main so i could call the function to return
{

	int option = 0;

	do
	{
		clearScreen();
		cout << "<-- C The Fruit Machine ++ -->" << endl << endl;
		cout << "1 - Play the slot machine!" << endl;
		cout << "2 - Look at the paytable..." << endl;
		cout << "3 - Exit the program" << endl << endl;
		cout << "Please select an option: ";
		cin >> option;

		switch (option)
		{
		case 1:
			clearScreen();
			playPuggy();
			break;
		case 2:
			paytable();
			break;
		case 3:
			cout << "Exiting program..." << endl;
			break;
		default:
			cout << "Invalid selection!" << endl;
			clearScreen();
			break;
		}
	} while (option != 3);
} // Set 

void stakeAmount()
{
	cout << "How much would you like to stake on this spin?" << endl;
	cout << "$1, $2, $5 or $10?" << endl;
	cin >> stake;
	cout << endl;
	switch (stake)
	{
	case 1: cout << "$1 is a valid (if a little small) stake!" << endl; break;
	case 2: cout << "$2 is a valid stake - lets play!" << endl; break;
	case 5: cout << "$5 is a valid stake - lets be lucky!" << endl; break;
	case 10: cout << "$10 is a big stake - you must be a high roller!" << endl; break;
	default: cout << " You haven't entered a valid amount - try again" << endl;
	}

}

void SpinWheel1()
{
	cout << "Press any key to start";
	_getch();
	//Used two of the _getch() functions as one didnt seem to work!!!
	bool spinning = true;
	do
	{
		for (int i = 0; i < 10; i++)
		{
			clearScreen();

			//      Wheel 1                                            Wheel 2                                            Wheel 3
			cout << slotMachine[spinIndex[i + 1]][0] << " | " << slotMachine[spinIndex[i + 2]][1] << " | " << slotMachine[spinIndex[i + 3]][2] << " | " << slotMachine[spinIndex[i + 2]][3] << " | " << slotMachine[spinIndex[i + 1]][4] << endl;
			cout << slotMachine[spinIndex[i + 2]][0] << " | " << slotMachine[spinIndex[i + 3]][1] << " | " << slotMachine[spinIndex[i + 4]][2] << " | " << slotMachine[spinIndex[i + 3]][3] << " | " << slotMachine[spinIndex[i + 2]][4] << endl;
			cout << slotMachine[spinIndex[i + 3]][0] << " | " << slotMachine[spinIndex[i + 4]][1] << " | " << slotMachine[spinIndex[i + 5]][2] << " | " << slotMachine[spinIndex[i + 4]][3] << " | " << slotMachine[spinIndex[i + 3]][4] << endl;
			cout << slotMachine[spinIndex[i + 4]][0] << " | " << slotMachine[spinIndex[i + 5]][1] << " | " << slotMachine[spinIndex[i + 6]][2] << " | " << slotMachine[spinIndex[i + 5]][3] << " | " << slotMachine[spinIndex[i + 4]][4] << endl;
			cout << slotMachine[spinIndex[i + 5]][0] << " | " << slotMachine[spinIndex[i + 6]][1] << " | " << slotMachine[spinIndex[i + 7]][2] << " | " << slotMachine[spinIndex[i + 6]][3] << " | " << slotMachine[spinIndex[i + 5]][4] << endl;
			//SWAP WHEEL INDEX FOR i, i+1 etc???

			if (_kbhit())//found on stackoverflow to stop the wheel spinning
			{
				// save wheel 1 values
				wheel1Result_1 = slotMachine[spinIndex[i + 1]][0];
				wheel1Result_2 = slotMachine[spinIndex[i + 2]][0];
				wheel1Result_3 = slotMachine[spinIndex[i + 3]][0];
				wheel1Result_4 = slotMachine[spinIndex[i + 4]][0];
				wheel1Result_5 = slotMachine[spinIndex[i + 5]][0];

				spinning = false;
				break;
			}

			Sleep(spinspeed);//determines the speed of the reel
		}
	} while (spinning == true);

}

void SpinWheel2()
{
	_getch();
	
	bool spinning = true;

	// spin wheel 2
	do
	{
		for (int i = 0; i < 10; i++)
		{
			clearScreen();

			

			//      Wheel 1                                            Wheel 2                                            Wheel 3
			cout << wheel1Result_1 << " | " << slotMachine[spinIndex[i + 2]][1] << " | " << slotMachine[spinIndex[i + 3]][2] << " | " << slotMachine[spinIndex[i + 2]][3] << " | " << slotMachine[spinIndex[i + 1]][4] << endl;
			cout << wheel1Result_2 << " | " << slotMachine[spinIndex[i + 3]][1] << " | " << slotMachine[spinIndex[i + 4]][2] << " | " << slotMachine[spinIndex[i + 3]][3] << " | " << slotMachine[spinIndex[i + 2]][4] << endl;
			cout << wheel1Result_3 << " | " << slotMachine[spinIndex[i + 4]][1] << " | " << slotMachine[spinIndex[i + 5]][2] << " | " << slotMachine[spinIndex[i + 4]][3] << " | " << slotMachine[spinIndex[i + 3]][4] << endl;
			cout << wheel1Result_4 << " | " << slotMachine[spinIndex[i + 5]][1] << " | " << slotMachine[spinIndex[i + 6]][2] << " | " << slotMachine[spinIndex[i + 5]][3] << " | " << slotMachine[spinIndex[i + 4]][4] << endl;
			cout << wheel1Result_5 << " | " << slotMachine[spinIndex[i + 6]][1] << " | " << slotMachine[spinIndex[i + 7]][2] << " | " << slotMachine[spinIndex[i + 6]][3] << " | " << slotMachine[spinIndex[i + 5]][4] << endl;


			if (_kbhit())
			{
				
				wheel2Result_1 = slotMachine[spinIndex[i + 2]][1];
				wheel2Result_2 = slotMachine[spinIndex[i + 3]][1];
				wheel2Result_3 = slotMachine[spinIndex[i + 4]][1];
				wheel2Result_4 = slotMachine[spinIndex[i + 5]][1];
				wheel2Result_5 = slotMachine[spinIndex[i + 6]][1];

				spinning = false;
				break;
			}

			Sleep(spinspeed);
		}
	} while (spinning);
}

void SpinWheel3()
{
	_getch();
	
	bool spinning = true;


	// spin wheel 3
	do
	{
		for (int i = 0; i < 10; i++)
		{
			clearScreen();

			//      Wheel 1                                            Wheel 2                                            Wheel 3
			cout << wheel1Result_1 << " | " << wheel2Result_1 << " | " << slotMachine[spinIndex[i + 3]][2] << " | " << slotMachine[spinIndex[i + 2]][3] << " | " << slotMachine[spinIndex[i + 1]][4] << endl;
			cout << wheel1Result_2 << " | " << wheel2Result_2 << " | " << slotMachine[spinIndex[i + 4]][2] << " | " << slotMachine[spinIndex[i + 3]][3] << " | " << slotMachine[spinIndex[i + 2]][4] << endl;
			cout << wheel1Result_3 << " | " << wheel2Result_3 << " | " << slotMachine[spinIndex[i + 5]][2] << " | " << slotMachine[spinIndex[i + 4]][3] << " | " << slotMachine[spinIndex[i + 3]][4] << endl;
			cout << wheel1Result_4 << " | " << wheel2Result_4 << " | " << slotMachine[spinIndex[i + 6]][2] << " | " << slotMachine[spinIndex[i + 5]][3] << " | " << slotMachine[spinIndex[i + 4]][4] << endl;
			cout << wheel1Result_5 << " | " << wheel2Result_5 << " | " << slotMachine[spinIndex[i + 7]][2] << " | " << slotMachine[spinIndex[i + 6]][3] << " | " << slotMachine[spinIndex[i + 5]][4] << endl;


			if (_kbhit())
			{
			
				wheel3Result_1 = slotMachine[spinIndex[i + 3]][2];
				wheel3Result_2 = slotMachine[spinIndex[i + 4]][2];
				wheel3Result_3 = slotMachine[spinIndex[i + 5]][2];
				wheel3Result_4 = slotMachine[spinIndex[i + 6]][2];
				wheel3Result_5 = slotMachine[spinIndex[i + 7]][2];

				spinning = false;
				break;
			}

			Sleep(spinspeed);
		}
	} while (spinning);

}

void SpinWheel4()
{
	_getch();
	
	bool spinning = true;

	// spin wheel 4
	do
	{
		for (int i = 0; i < 10; i++)
		{
			clearScreen();

			//      Wheel 1                                            Wheel 2                                            Wheel 3
			cout << wheel1Result_1 << " | " << wheel2Result_1 << " | " << wheel3Result_1 << " | " << slotMachine[spinIndex[i + 2]][3] << " | " << slotMachine[spinIndex[i + 1]][4] << endl;
			cout << wheel1Result_2 << " | " << wheel2Result_2 << " | " << wheel3Result_2 << " | " << slotMachine[spinIndex[i + 3]][3] << " | " << slotMachine[spinIndex[i + 2]][4] << endl;
			cout << wheel1Result_3 << " | " << wheel2Result_3 << " | " << wheel3Result_3 << " | " << slotMachine[spinIndex[i + 4]][3] << " | " << slotMachine[spinIndex[i + 3]][4] << endl;
			cout << wheel1Result_4 << " | " << wheel2Result_4 << " | " << wheel3Result_4 << " | " << slotMachine[spinIndex[i + 5]][3] << " | " << slotMachine[spinIndex[i + 4]][4] << endl;
			cout << wheel1Result_5 << " | " << wheel2Result_5 << " | " << wheel3Result_5 << " | " << slotMachine[spinIndex[i + 6]][3] << " | " << slotMachine[spinIndex[i + 5]][4] << endl;


			if (_kbhit())
			{
				
				wheel4Result_1 = slotMachine[spinIndex[i + 2]][3];
				wheel4Result_2 = slotMachine[spinIndex[i + 3]][3];
				wheel4Result_3 = slotMachine[spinIndex[i + 4]][3];
				wheel4Result_4 = slotMachine[spinIndex[i + 5]][3];
				wheel4Result_5 = slotMachine[spinIndex[i + 6]][3];

				spinning = false;
				break;
			}

			Sleep(spinspeed);
		}
	} while (spinning);

}

void SpinWheel5()
{
	_getch();
	
	bool spinning = true;

	// spin wheel 5
	do
	{
		for (int i = 0; i < 10; i++)
		{
			clearScreen();

			//      Wheel 1                                            Wheel 2                                            Wheel 3
			cout << wheel1Result_1 << " | " << wheel2Result_1 << " | " << wheel3Result_1 << " | " << wheel4Result_1 << " | " << slotMachine[spinIndex[i + 1]][4] << endl;
			cout << wheel1Result_2 << " | " << wheel2Result_2 << " | " << wheel3Result_2 << " | " << wheel4Result_2 << " | " << slotMachine[spinIndex[i + 2]][4] << endl;
			cout << wheel1Result_3 << " | " << wheel2Result_3 << " | " << wheel3Result_3 << " | " << wheel4Result_3 << " | " << slotMachine[spinIndex[i + 3]][4] << endl;
			cout << wheel1Result_4 << " | " << wheel2Result_4 << " | " << wheel3Result_4 << " | " << wheel4Result_4 << " | " << slotMachine[spinIndex[i + 4]][4] << endl;
			cout << wheel1Result_5 << " | " << wheel2Result_5 << " | " << wheel3Result_5 << " | " << wheel4Result_5 << " | " << slotMachine[spinIndex[i + 5]][4] << endl;


			if (_kbhit())
			{
				
				wheel5Result_1 = slotMachine[spinIndex[i + 1]][4];
				wheel5Result_2 = slotMachine[spinIndex[i + 2]][4];
				wheel5Result_3 = slotMachine[spinIndex[i + 3]][4];
				wheel5Result_4 = slotMachine[spinIndex[i + 4]][4];
				wheel5Result_5 = slotMachine[spinIndex[i + 5]][4];

				spinning = false;
				break;
			}

			Sleep(spinspeed);
		}
	} while (spinning);

}

void compareResults() // comparing the results of the reels to see of there is any winners
//A horrible, long, messy function!
{
	int balance1 = 0;
	int balance2 = 0;
	int balance3 = 0;
	int balance4 = 0;
	int balance5 = 0;
	int balance6 = 0;
	int balance7 = 0;

	if (wheel1Result_1 == wheel2Result_1 && wheel2Result_1 == wheel3Result_1 && wheel3Result_1 == 'K')
	{
		cout << "WINNER! K's on line 1" << endl;
		balance1 = balance1 + 10;
	}

	if (wheel1Result_2 == wheel2Result_2 && wheel2Result_2 == wheel3Result_2 && wheel3Result_2 == 'K')
	{
		cout << "WINNER! K's on line 2" << endl;
		balance2 = balance2 + 10;
	}
	if (wheel1Result_3 == wheel2Result_3 && wheel2Result_3 == wheel3Result_3 && wheel3Result_3 == 'K')
	{
		cout << "WINNER! K's on line 3" << endl;
		balance3 = balance3 + 10;
	}
	if (wheel1Result_4 == wheel2Result_4 && wheel2Result_4 == wheel3Result_4 && wheel3Result_4 == 'K')
	{
		cout << "WINNER! K's on line 4" << endl;
		balance4 = balance4 + 10;
	}
	if (wheel1Result_5 == wheel2Result_5 && wheel2Result_5 == wheel3Result_5 && wheel3Result_5 == 'K')
	{
		cout << "WINNER! K's on line 5" << endl;
		balance5 = balance5 + 10;
	}
	if (wheel1Result_1 == wheel2Result_2 && wheel2Result_2 == wheel3Result_3 && wheel3Result_3 == 'K')
	{
		cout << "WINNER! K's on line 6" << endl;
		balance6 = balance6 + 10;
	}
	if (wheel1Result_5 == wheel2Result_4 && wheel2Result_4 == wheel3Result_3 && wheel3Result_3 == 'K')
	{
		cout << "WINNER! K's on line 7" << endl;
		balance7 = balance7 + 10;
	}
	if (wheel1Result_1 == wheel2Result_1 && wheel2Result_1 == wheel3Result_1 && wheel3Result_1 == wheel4Result_1 && wheel4Result_1 == 'K')
	{
		balance1 = balance1 + 5;
	}
	if (wheel1Result_2 == wheel2Result_2 && wheel2Result_2 == wheel3Result_2 && wheel3Result_2 == wheel4Result_2 && wheel4Result_2 == 'K')
	{
		balance2 = balance2 + 5;
	}
	if (wheel1Result_3 == wheel2Result_3 && wheel2Result_3 == wheel3Result_3 && wheel3Result_3 == wheel4Result_3 && wheel4Result_3 == 'K')
	{
		balance3 = balance3 + 5;
	}
	if (wheel1Result_4 == wheel2Result_4 && wheel2Result_4 == wheel3Result_4 && wheel3Result_4 == wheel4Result_4 && wheel4Result_4 == 'K')
	{
		balance4 = balance4 + 5;
	}
	if (wheel1Result_5 == wheel2Result_5 && wheel2Result_5 == wheel3Result_5 && wheel3Result_5 == wheel4Result_5 && wheel4Result_5 == 'K')
	{
		balance5 = balance5 + 5;
	}
	if (wheel1Result_1 == wheel2Result_2 && wheel2Result_2 == wheel3Result_3 && wheel3Result_4 == wheel4Result_4 && wheel4Result_4 == 'K')
	{
		balance6 = balance6 + 5;
	}
	if (wheel1Result_5 == wheel2Result_4 && wheel2Result_4 == wheel3Result_3 && wheel3Result_2 == wheel4Result_2 && wheel4Result_2 == 'K')
	{
		balance7 = balance7 + 5;
	}
	if (wheel1Result_1 == wheel2Result_1 && wheel2Result_1 == wheel3Result_1 && wheel3Result_1 == wheel4Result_1 && wheel4Result_1 == wheel5Result_1 && wheel5Result_1 == 'K')
	{
		cout << "WOW!!! 5 K's in a row on line 1 - a chance at the bonus!" << endl;
		balance1 = balance1 + 10;
	}
	if (wheel1Result_2 == wheel2Result_2 && wheel2Result_2 == wheel3Result_2 && wheel3Result_2 == wheel4Result_2 && wheel4Result_2 == wheel5Result_2 && wheel5Result_2 == 'K')
	{
		cout << "WOW!!! 5 K's in a row on line 2 - a chance at the bonus!" << endl;
		balance2 = balance2 + 10;
	}
	if (wheel1Result_3 == wheel2Result_3 && wheel2Result_3 == wheel3Result_3 && wheel3Result_3 == wheel4Result_3 && wheel4Result_3 == wheel5Result_3 && wheel5Result_3 == 'K')
	{
		cout << "WOW!!! 5 K's in a row on line 3 - a chance at the bonus!" << endl;
		balance3 = balance3 + 10;
	}
	if (wheel1Result_4 == wheel2Result_4 && wheel2Result_4 == wheel3Result_4 && wheel3Result_4 == wheel4Result_4 && wheel4Result_4 == wheel5Result_4 && wheel5Result_4 == 'K')
	{
		cout << "WOW!!! 5 K's in a row on line 4 - a chance at the bonus!" << endl;
		balance4 = balance4 + 10;
	}
	if (wheel1Result_5 == wheel2Result_5 && wheel2Result_5 == wheel3Result_5 && wheel3Result_5 == wheel4Result_5 && wheel4Result_5 == wheel5Result_5 && wheel5Result_5 == 'K')
	{
		cout << "WOW!!! 5 K's in a row on line 5 - a chance at the bonus!" << endl;
		balance5 = balance5 + 10;
	}
	if (wheel1Result_1 == wheel2Result_2 && wheel2Result_2 == wheel3Result_3 && wheel3Result_3 == wheel4Result_4 && wheel4Result_4 == wheel5Result_5 && wheel5Result_5 == 'K')
	{
		cout << "WOW!!! 5 K's in a row on line 6 - a chance at the bonus!" << endl;
		balance6 = balance6 + 10;
	}
	if (wheel1Result_5 == wheel2Result_4 && wheel2Result_4 == wheel3Result_3 && wheel3Result_3 == wheel4Result_2 && wheel4Result_2 == wheel5Result_1 && wheel5Result_1 == 'K')
	{
		cout << "WOW!!! 5 K's in a row on line 7 - a chance at the bonus!" << endl;
		balance7 = balance7 + 10;
	}
	if (wheel1Result_1 == wheel2Result_1 && wheel2Result_1 == wheel3Result_1 && wheel3Result_1 == 'A')
	{
		cout << "WINNER! A's on line 1" << endl;
		balance1 = balance1 + 20;
	}

	if (wheel1Result_2 == wheel2Result_2 && wheel2Result_2 == wheel3Result_2 && wheel3Result_2 == 'A')
	{
		cout << "WINNER! A's on line 2" << endl;
		balance2 = balance2 + 20;
	}
	if (wheel1Result_3 == wheel2Result_3 && wheel2Result_3 == wheel3Result_3 && wheel3Result_3 == 'A')
	{
		cout << "WINNER! A's on line 3" << endl;
		balance3 = balance3 + 20;
	}
	if (wheel1Result_4 == wheel2Result_4 && wheel2Result_4 == wheel3Result_4 && wheel3Result_4 == 'A')
	{
		cout << "WINNER! A's on line 4" << endl;
		balance4 = balance4 + 20;
	}
	if (wheel1Result_5 == wheel2Result_5 && wheel2Result_5 == wheel3Result_5 && wheel3Result_5 == 'A')
	{
		cout << "WINNER! A's on line 5" << endl;
		balance5 = balance5 + 20;
	}
	if (wheel1Result_1 == wheel2Result_2 && wheel2Result_2 == wheel3Result_3 && wheel3Result_3 == 'A')
	{
		cout << "WINNER! A's on line 6" << endl;
		balance6 = balance6 + 20;
	}
	if (wheel1Result_5 == wheel2Result_4 && wheel2Result_4 == wheel3Result_3 && wheel3Result_3 == 'A')
	{
		cout << "WINNER! 3 A's on line 7" << endl;
		balance7 = balance7 + 20;
	}
	if (wheel1Result_1 == wheel2Result_1 && wheel2Result_1 == wheel3Result_1 && wheel3Result_1 == wheel4Result_1 && wheel4Result_1 == 'A')
	{
		balance1 = balance1 + 10;
	}
	if (wheel1Result_2 == wheel2Result_2 && wheel2Result_2 == wheel3Result_2 && wheel3Result_2 == wheel4Result_2 && wheel4Result_2 == 'A')
	{
		balance2 = balance2 + 10;
	}
	if (wheel1Result_3 == wheel2Result_3 && wheel2Result_3 == wheel3Result_3 && wheel3Result_3 == wheel4Result_3 && wheel4Result_3 == 'A')
	{
		balance3 = balance3 + 10;
	}
	if (wheel1Result_4 == wheel2Result_4 && wheel2Result_4 == wheel3Result_4 && wheel3Result_4 == wheel4Result_4 && wheel4Result_4 == 'A')
	{
		balance4 = balance4 + 10;
	}
	if (wheel1Result_5 == wheel2Result_5 && wheel2Result_5 == wheel3Result_5 && wheel3Result_5 == wheel4Result_5 && wheel4Result_5 == 'A')
	{
		balance5 = balance5 + 10;
	}
	if (wheel1Result_1 == wheel2Result_2 && wheel2Result_2 == wheel3Result_3 && wheel3Result_4 == wheel4Result_4 && wheel4Result_4 == 'A')
	{
		balance6 = balance6 + 10;
	}
	if (wheel1Result_5 == wheel2Result_4 && wheel2Result_4 == wheel3Result_3 && wheel3Result_2 == wheel4Result_2 && wheel4Result_2 == 'A')
	{
		balance7 = balance7 + 10;
	}
	if (wheel1Result_1 == wheel2Result_1 && wheel2Result_1 == wheel3Result_1 && wheel3Result_1 == wheel4Result_1 && wheel4Result_1 == wheel5Result_1 && wheel5Result_1 == 'A')
	{
		cout << "WOW!!! 5 A's in a row on line 1 - a chance at the bonus!" << endl;
		balance1 = balance1 + 20;
	}
	if (wheel1Result_2 == wheel2Result_2 && wheel2Result_2 == wheel3Result_2 && wheel3Result_2 == wheel4Result_2 && wheel4Result_2 == wheel5Result_2 && wheel5Result_2 == 'A')
	{
		cout << "WOW!!! 5 A's in a row on line 2 - a chance at the bonus!" << endl;
		balance2 = balance3 + 20;
	}
	if (wheel1Result_3 == wheel2Result_3 && wheel2Result_3 == wheel3Result_3 && wheel3Result_3 == wheel4Result_3 && wheel4Result_3 == wheel5Result_3 && wheel5Result_3 == 'A')
	{
		cout << "WOW!!! 5 A's in a row on line 3 - a chance at the bonus!" << endl;
		balance3 = balance3 + 20;
	}
	if (wheel1Result_4 == wheel2Result_4 && wheel2Result_4 == wheel3Result_4 && wheel3Result_4 == wheel4Result_4 && wheel4Result_4 == wheel5Result_4 && wheel5Result_4 == 'A')
	{
		cout << "WOW!!! 5 A's in a row on line 4 - a chance at the bonus!" << endl;
		balance4 = balance4 + 20;
	}
	if (wheel1Result_5 == wheel2Result_5 && wheel2Result_5 == wheel3Result_5 && wheel3Result_5 == wheel4Result_5 && wheel4Result_5 == wheel5Result_5 && wheel5Result_5 == 'A')
	{
		cout << "WOW!!! 5 A's in a row on line 5 - a chance at the bonus!" << endl;
		balance5 = balance5 + 20;
	}
	if (wheel1Result_1 == wheel2Result_2 && wheel2Result_2 == wheel3Result_3 && wheel3Result_3 == wheel4Result_4 && wheel4Result_4 == wheel5Result_5 && wheel5Result_5 == 'A')
	{
		cout << "WOW!!! 5 A's in a row on line 6 - a chance at the bonus!" << endl;
		balance6 = balance6 + 20;
	}
	if (wheel1Result_5 == wheel2Result_4 && wheel2Result_4 == wheel3Result_3 && wheel3Result_3 == wheel4Result_2 && wheel4Result_2 == wheel5Result_1 && wheel5Result_1 == 'A')
	{
		cout << "WOW!!! 5 A's in a row on line 7 - a chance at the bonus!" << endl;
		balance7 = balance7 + 20;
	}
	if (wheel1Result_1 == wheel2Result_1 && wheel2Result_1 == wheel3Result_1 && wheel3Result_1 == 'Q')
	{
		cout << "WINNER! Q's on line 1" << endl;
		balance1 = balance1 + 5;
	}

	if (wheel1Result_2 == wheel2Result_2 && wheel2Result_2 == wheel3Result_2 && wheel3Result_2 == 'Q')
	{
		cout << "WINNER! Q's on line 2" << endl;
		balance2 = balance2 + 5;
	}
	if (wheel1Result_3 == wheel2Result_3 && wheel2Result_3 == wheel3Result_3 && wheel3Result_3 == 'Q')
	{
		cout << "WINNER! Q's on line 3" << endl;
		balance3 = balance3 + 5;
	}
	if (wheel1Result_4 == wheel2Result_4 && wheel2Result_4 == wheel3Result_4 && wheel3Result_4 == 'Q')
	{
		cout << "WINNER! Q's on line 4" << endl;
		balance4 = balance4 + 5;
	}
	if (wheel1Result_5 == wheel2Result_5 && wheel2Result_5 == wheel3Result_5 && wheel3Result_5 == 'Q')
	{
		cout << "WINNER! Q's on line 5" << endl;
		balance5 = balance5 + 5;
	}
	if (wheel1Result_1 == wheel2Result_2 && wheel2Result_2 == wheel3Result_3 && wheel3Result_3 == 'Q')
	{
		cout << "WINNER! Q's on line 6" << endl;
		balance6 = balance6 + 5;
	}
	if (wheel1Result_5 == wheel2Result_4 && wheel2Result_4 == wheel3Result_3 && wheel3Result_3 == 'Q')
	{
		cout << "WINNER! Q's on line 7" << endl;
		balance7 = balance7 + 5;
	}
	if (wheel1Result_1 == wheel2Result_1 && wheel2Result_1 == wheel3Result_1 && wheel3Result_1 == wheel4Result_1 && wheel4Result_1 == 'Q')
	{
		balance1 = balance1 + 5;
	}
	if (wheel1Result_2 == wheel2Result_2 && wheel2Result_2 == wheel3Result_2 && wheel3Result_2 == wheel4Result_2 && wheel4Result_2 == 'Q')
	{
		balance2 = balance2 + 5;
	}
	if (wheel1Result_3 == wheel2Result_3 && wheel2Result_3 == wheel3Result_3 && wheel3Result_3 == wheel4Result_3 && wheel4Result_3 == 'Q')
	{
		balance3 = balance3 + 5;
	}
	if (wheel1Result_4 == wheel2Result_4 && wheel2Result_4 == wheel3Result_4 && wheel3Result_4 == wheel4Result_4 && wheel4Result_4 == 'Q')
	{
		balance4 = balance4 + 5;
	}
	if (wheel1Result_5 == wheel2Result_5 && wheel2Result_5 == wheel3Result_5 && wheel3Result_5 == wheel4Result_5 && wheel4Result_5 == 'Q')
	{
		balance5 = balance5 + 5;
	}
	if (wheel1Result_1 == wheel2Result_2 && wheel2Result_2 == wheel3Result_3 && wheel3Result_4 == wheel4Result_4 && wheel4Result_4 == 'Q')
	{
		balance6 = balance6 + 5;
	}
	if (wheel1Result_5 == wheel2Result_4 && wheel2Result_4 == wheel3Result_3 && wheel3Result_2 == wheel4Result_2 && wheel4Result_2 == 'Q')
	{
		balance7 = balance7 + 5;
	}
	if (wheel1Result_1 == wheel2Result_1 && wheel2Result_1 == wheel3Result_1 && wheel3Result_1 == wheel4Result_1 && wheel4Result_1 == wheel5Result_1 && wheel5Result_1 == 'Q')
	{
		cout << "WOW!!! 5 Q's in a row on line 1 - a chance at the bonus!" << endl;
		balance1 = balance1 + 10;
	}
	if (wheel1Result_2 == wheel2Result_2 && wheel2Result_2 == wheel3Result_2 && wheel3Result_2 == wheel4Result_2 && wheel4Result_2 == wheel5Result_2 && wheel5Result_2 == 'Q')
	{
		cout << "WOW!!! 5 Q's in a row on line 2 - a chance at the bonus!" << endl;
		balance2 = balance2 + 10;
	}
	if (wheel1Result_3 == wheel2Result_3 && wheel2Result_3 == wheel3Result_3 && wheel3Result_3 == wheel4Result_3 && wheel4Result_3 == wheel5Result_3 && wheel5Result_3 == 'Q')
	{
		cout << "WOW!!! 5 Q's in a row on line 3 - a chance at the bonus!" << endl;
		balance3 = balance3 + 10;
	}
	if (wheel1Result_4 == wheel2Result_4 && wheel2Result_4 == wheel3Result_4 && wheel3Result_4 == wheel4Result_4 && wheel4Result_4 == wheel5Result_4 && wheel5Result_4 == 'Q')
	{
		cout << "WOW!!! 5 Q's in a row on line 4 - a chance at the bonus!" << endl;
		balance4 = balance4 + 10;
	}
	if (wheel1Result_5 == wheel2Result_5 && wheel2Result_5 == wheel3Result_5 && wheel3Result_5 == wheel4Result_5 && wheel4Result_5 == wheel5Result_5 && wheel5Result_5 == 'Q')
	{
		cout << "WOW!!! 5 Q's in a row on line 5 - a chance at the bonus!" << endl;
		balance5 = balance5 + 10;
	}
	if (wheel1Result_1 == wheel2Result_2 && wheel2Result_2 == wheel3Result_3 && wheel3Result_3 == wheel4Result_4 && wheel4Result_4 == wheel5Result_5 && wheel5Result_5 == 'Q')
	{
		cout << "WOW!!! 5 Q's in a row on line 6 - a chance at the bonus!" << endl;
		balance6 = balance6 + 10;
	}
	if (wheel1Result_5 == wheel2Result_4 && wheel2Result_4 == wheel3Result_3 && wheel3Result_3 == wheel4Result_2 && wheel4Result_2 == wheel5Result_1 && wheel5Result_1 == 'Q')
	{
		cout << "WOW!!! 5 Q's in a row on line 7 - a chance at the bonus!" << endl;
		balance7 = balance7 + 10;
	}
	if (wheel1Result_1 == wheel2Result_1 && wheel2Result_1 == wheel3Result_1 && wheel3Result_1 == 'J')
	{
		cout << "WINNER! J's on line 1" << endl;
		balance1 = balance1 + 5;
	}

	if (wheel1Result_2 == wheel2Result_2 && wheel2Result_2 == wheel3Result_2 && wheel3Result_2 == 'J')
	{
		cout << "WINNER! J's on line 2" << endl;
		balance2 = balance2 + 1;
	}
	if (wheel1Result_3 == wheel2Result_3 && wheel2Result_3 == wheel3Result_3 && wheel3Result_3 == 'J')
	{
		cout << "WINNER! J's on line 3" << endl;
		balance3 = balance3 + 1;
	}
	if (wheel1Result_4 == wheel2Result_4 && wheel2Result_4 == wheel3Result_4 && wheel3Result_4 == 'J')
	{
		cout << "WINNER! J's on line 4" << endl;
		balance4 = balance4 + 1;
	}
	if (wheel1Result_5 == wheel2Result_5 && wheel2Result_5 == wheel3Result_5 && wheel3Result_5 == 'J')
	{
		cout << "WINNER! J's on line 5" << endl;
		balance5 = balance5 + 1;
	}
	if (wheel1Result_1 == wheel2Result_2 && wheel2Result_2 == wheel3Result_3 && wheel3Result_3 == 'J')
	{
		cout << "WINNER! J's on line 6" << endl;
		balance6 = balance6 + 1;
	}
	if (wheel1Result_5 == wheel2Result_4 && wheel2Result_4 == wheel3Result_3 && wheel3Result_3 == 'J')
	{
		cout << "WINNER! J's on line 7" << endl;
		balance7 = balance7 + 1;
	}
	if (wheel1Result_1 == wheel2Result_1 && wheel2Result_1 == wheel3Result_1 && wheel3Result_1 == wheel4Result_1 && wheel4Result_1 == 'Q')
	{
		balance1 = balance1 + 1;
	}
	if (wheel1Result_2 == wheel2Result_2 && wheel2Result_2 == wheel3Result_2 && wheel3Result_2 == wheel4Result_2 && wheel4Result_2 == 'Q')
	{
		balance2 = balance2 + 1;
	}
	if (wheel1Result_3 == wheel2Result_3 && wheel2Result_3 == wheel3Result_3 && wheel3Result_3 == wheel4Result_3 && wheel4Result_3 == 'Q')
	{
		balance3 = balance3 + 1;
	}
	if (wheel1Result_4 == wheel2Result_4 && wheel2Result_4 == wheel3Result_4 && wheel3Result_4 == wheel4Result_4 && wheel4Result_4 == 'Q')
	{
		balance4 = balance4 + 1;
	}
	if (wheel1Result_5 == wheel2Result_5 && wheel2Result_5 == wheel3Result_5 && wheel3Result_5 == wheel4Result_5 && wheel4Result_5 == 'Q')
	{
		balance5 = balance5 + 1;
	}
	if (wheel1Result_1 == wheel2Result_2 && wheel2Result_2 == wheel3Result_3 && wheel3Result_4 == wheel4Result_4 && wheel4Result_4 == 'Q')
	{
		balance6 = balance6 + 1;
	}
	if (wheel1Result_5 == wheel2Result_4 && wheel2Result_4 == wheel3Result_3 && wheel3Result_2 == wheel4Result_2 && wheel4Result_2 == 'Q')
	{
		balance7 = balance7 + 1;
	}
	if (wheel1Result_1 == wheel2Result_1 && wheel2Result_1 == wheel3Result_1 && wheel3Result_1 == wheel4Result_1 && wheel4Result_1 == wheel5Result_1 && wheel5Result_1 == 'Q')
	{
		cout << "WOW!!! 5 J's in a row on line 1 - a chance at the bonus!" << endl;
		balance1 = balance1 + 3;
	}
	if (wheel1Result_2 == wheel2Result_2 && wheel2Result_2 == wheel3Result_2 && wheel3Result_2 == wheel4Result_2 && wheel4Result_2 == wheel5Result_2 && wheel5Result_2 == 'Q')
	{
		cout << "WOW!!! 5 J's in a row on line 2 - a chance at the bonus!" << endl;
		balance2 = balance2 + 3;
	}
	if (wheel1Result_3 == wheel2Result_3 && wheel2Result_3 == wheel3Result_3 && wheel3Result_3 == wheel4Result_3 && wheel4Result_3 == wheel5Result_3 && wheel5Result_3 == 'Q')
	{
		cout << "WOW!!! 5 J's in a row on line 3 - a chance at the bonus!" << endl;
		balance3 = balance3 + 3;
	}
	if (wheel1Result_4 == wheel2Result_4 && wheel2Result_4 == wheel3Result_4 && wheel3Result_4 == wheel4Result_4 && wheel4Result_4 == wheel5Result_4 && wheel5Result_4 == 'Q')
	{
		cout << "WOW!!! 5 J's in a row on line 4 - a chance at the bonus!" << endl;
		balance4 = balance4 + 3;
	}
	if (wheel1Result_5 == wheel2Result_5 && wheel2Result_5 == wheel3Result_5 && wheel3Result_5 == wheel4Result_5 && wheel4Result_5 == wheel5Result_5 && wheel5Result_5 == 'Q')
	{
		cout << "WOW!!! 5 J's in a row on line 5 - a chance at the bonus!" << endl;
		balance5 = balance5 + 3;
	}
	if (wheel1Result_1 == wheel2Result_2 && wheel2Result_2 == wheel3Result_3 && wheel3Result_3 == wheel4Result_4 && wheel4Result_4 == wheel5Result_5 && wheel5Result_5 == 'Q')
	{
		cout << "WOW!!! 5 J's in a row on line 6 - a chance at the bonus!" << endl;
		balance6 = balance6 + 3;
	}
	if (wheel1Result_5 == wheel2Result_4 && wheel2Result_4 == wheel3Result_3 && wheel3Result_3 == wheel4Result_2 && wheel4Result_2 == wheel5Result_1 && wheel5Result_1 == 'Q')
	{
		cout << "WOW!!! 5 J's in a row on line 7 - a chance at the bonus!" << endl;
		balance7 = balance7 + 3;
	}

	totalBalance = totalBalance - stake; //Staking off the stake from the balance
	balance1 = balance1 * stake; // mutliplied by stake to determine winnings for line
	balance2 = balance2 * stake;
	balance3 = balance3 * stake;
	balance4 = balance4 * stake;
	balance5 = balance5 * stake;
	balance6 = balance6 * stake;
	balance7 = balance7 * stake;
	balance = balance1 + balance2 + balance3 + balance4 + balance5 + balance6 + balance7; // total winnings from spin

	if (balance == 0) // Losers message
	{
		cout << "Unlucky - Try Again" << endl;
		cout << "Your balance is now $" << totalBalance << endl;
	}
	else { //winners message

		cout << "Line 1 winnings $" << balance1 << endl;
		cout << "Line 2 winnings $" << balance2 << endl;
		cout << "Line 3 winnings $" << balance3 << endl;
		cout << "Line 4 winnings $" << balance4 << endl;
		cout << "Line 5 winnings $" << balance5 << endl;
		cout << "Line 6 winnings $" << balance6 << endl;
		cout << "Line 7 winnings $" << balance7 << endl << endl;

		//if statement so if there is 5 in a row then user goes onto toin coss gamble feature
		if ((wheel1Result_1 == wheel2Result_1 && wheel2Result_1 == wheel3Result_1 && wheel3Result_1 == wheel4Result_1 && wheel4Result_1 == wheel5Result_1 && wheel5Result_1 != '*') || (wheel1Result_2 == wheel2Result_2 && wheel2Result_2 == wheel3Result_2 && wheel3Result_2 == wheel4Result_2 && wheel4Result_2 == wheel5Result_2 && wheel5Result_2 != '*') || (wheel1Result_3 == wheel2Result_3 && wheel2Result_3 == wheel3Result_3 && wheel3Result_3 == wheel4Result_3 && wheel4Result_3 == wheel5Result_3 && wheel5Result_3 != '*') || (wheel1Result_4 == wheel2Result_4 && wheel2Result_4 == wheel3Result_4 && wheel3Result_4 == wheel4Result_4 && wheel4Result_4 == wheel5Result_4 && wheel5Result_4 != '*') || (wheel1Result_5 == wheel2Result_5 && wheel2Result_5 == wheel3Result_5 && wheel3Result_5 == wheel4Result_5 && wheel4Result_5 == wheel5Result_5 && wheel5Result_5 != '*') || (wheel1Result_1 == wheel2Result_2 && wheel2Result_2 == wheel3Result_3 && wheel3Result_3 == wheel4Result_4 && wheel4Result_4 == wheel5Result_5 && wheel5Result_5 != '*') || (wheel1Result_5 == wheel2Result_4 && wheel2Result_4 == wheel3Result_3 && wheel3Result_3 == wheel4Result_2 && wheel4Result_2 == wheel5Result_1 && wheel5Result_1 != '*'))
		{
			cout << "ON TO THE GAMBLE FEATURE!!!!";
			Sleep(5000);
			gamble();
		}

		cout << "Total winnings for the game is $" << balance << endl;
		totalBalance = totalBalance + balance;
		cout << "Your total balance is $" << totalBalance << endl;
	}

	

	Sleep(2000);
}

void gamble()
{
	clearScreen();


	cout << "You are now in the gamble feature!!!" << endl;
	cout << "You winnings from the main game are now getting gambled on the toss of a coin!" << endl;
	char coin = ' ';
	
	do
	{
		cout << "Type H for Heads or T for Tails...." << endl;
		cin >> coin;

	} while (coin != 'T' && coin != 'H');

	cout << "Press any key to start the coin toss then again to stop it!";

	_getch();
	system("CLS");
	bool turning = true;
	do
	{

	for (int gamb = 1; gamb < 3; gamb++)

	{
		if (gamb = 1)
		{
			cout << "  _________  " << endl;
			cout << "      |      " << endl;
			cout << "      |      " << endl;
			cout << "      |      " << endl;
			cout << "      |      " << endl;
			Sleep(500);
			if (_kbhit())
			{
				if (coin == 'T')
				{
					balance = balance * 2;
				}
				else { balance = 0; }
				turning = false;
				break;
			}

			system("CLS");
		}

		if (gamb = 2)
		{
			cout << "  |       |   " << endl;
			cout << "  |       |   " << endl;
			cout << "  |_______|   " << endl;
			cout << "  |       |   " << endl;
			cout << "  |       |   " << endl;
			Sleep(500);
			if (_kbhit())
			{
				if (coin == 'H')
				{
					balance = balance * 2;
				}
				
				else {
					balance = 0;
				}
				turning = false;
				break;
				
				turning = false;
				break;
			}
			system("CLS");
			gamb = 1;
		}

	}

	} while (turning == true);

}



void spinAndCompare() //spin wheel and compare result. I split this function up from the stake so it was quicker and easier to respin
{

	SpinWheel1();
	SpinWheel2();
	SpinWheel3();
	SpinWheel4();
	SpinWheel5();

	compareResults();

	char cont = ' ';
	cout << "If you want to spin again with the same stake press any key then enter or press M to return to the main menu..." << endl;
	cin >> cont;

	switch (cont)
	{
	case 'm': clearScreen(); homePage(); break; //returns user to main menu if they dont want to play again at the same stake
	case 'M': clearScreen(); homePage(); break;
	default: spinAndCompare();
	}
}

void outputMachine()
{
	stakeAmount();
	spinAndCompare();
}




void setupPuggy() // This sets up the 2D array with the values from the wheel generator
{
	

	for (int row = 0; row < 15; row++)
	{
		setwheel();
		slotMachine[row][0] = wheel[row];
		slotMachine[row][1] = wheel[row];
		slotMachine[row][2] = wheel[row];
		slotMachine[row][3] = wheel[row];
		slotMachine[row][4] = wheel[row];
	}
}



void paytable() // A paytable for the user to see what they could win
{
	clearScreen();
	int t = 0;
	cout << "The game can be played at $1, $2, $5 or $10 stakes" << endl << "and payouts change accordingly" << endl << endl;
	cout << "What stake level would you like to see the paytable for?" << endl;
	cin >> t;
	switch (t)
	{
	case 1: clearScreen();
		cout << "-------Paytable($1 stake)---------" << endl << endl;
		cout << "--------in a row-------" << endl;
		cout << setw(8) << "3" << setw(7) << "4" << setw(7) << "5" << endl;
		cout << "A" << setw(7) << "$20" << setw(7) << "$30" << setw(7) << "$50" << endl;
		cout << "K" << setw(7) << "$10" << setw(7) << "$15" << setw(7) << "$25" << endl;
		cout << "Q" << setw(7) << "$5" << setw(7) << "$10" << setw(7) << "$20" << endl;
		cout << "J" << setw(7) << "$1" << setw(7) << "$2" << setw(7) << "$5" << endl << endl;
		cout << "Press any key to return to the main menu";
		_getch();
		clearScreen();
		break;

	case 2:
		clearScreen();
		cout << "-------Paytable($2 stake)---------" << endl << endl;
		cout << "--------in a row-------" << endl;
		cout << setw(8) << "3" << setw(7) << "4" << setw(7) << "5" << endl;
		cout << "A" << setw(7) << "$40" << setw(7) << "$60" << setw(7) << "$100" << endl;
		cout << "K" << setw(7) << "$20" << setw(7) << "$30" << setw(7) << "$50" << endl;
		cout << "Q" << setw(7) << "$10" << setw(7) << "$20" << setw(7) << "$40" << endl;
		cout << "J" << setw(7) << "$2" << setw(7) << "$4" << setw(7) << "$10" << endl << endl;
		cout << "Press any key to return to the main menu";
		_getch();
		clearScreen();
		break;

	case 5: clearScreen();
		cout << "-------Paytable($5 stake)---------" << endl << endl;
		cout << "--------in a row-------" << endl;
		cout << setw(8) << "3" << setw(7) << "4" << setw(7) << "5" << endl;
		cout << "A" << setw(7) << "$100" << setw(7) << "$150" << setw(7) << "$250" << endl;
		cout << "K" << setw(7) << "$50" << setw(7) << "$75" << setw(7) << "$125" << endl;
		cout << "Q" << setw(7) << "$25" << setw(7) << "$50" << setw(7) << "$100" << endl;
		cout << "J" << setw(7) << "$5" << setw(7) << "$10" << setw(7) << "$25" << endl << endl;
		cout << "Press any key to return to the main menu";
		_getch();
		clearScreen();
		break;

	case 10: clearScreen();
		cout << "-------Paytable($10 stake)---------" << endl << endl;
		cout << "--------in a row-------" << endl;
		cout << setw(8) << "3" << setw(7) << "4" << setw(7) << "5" << endl;
		cout << "A" << setw(7) << "$200" << setw(7) << "$300" << setw(7) << "$500" << endl;
		cout << "K" << setw(7) << "$100" << setw(7) << "$150" << setw(7) << "$250" << endl;
		cout << "Q" << setw(7) << "$50" << setw(7) << "$100" << setw(7) << "$200" << endl;
		cout << "J" << setw(7) << "$10" << setw(7) << "$20" << setw(7) << "$50" << endl << endl;
		cout << "Press any key to return to the main menu";
		_getch();
		clearScreen();
		break;

	default: cout << "Unvalid stake i'm afraid! Try again..."; Sleep(1000); paytable();
	}
}

int main()
{
	homePage();

	return 0;
}
