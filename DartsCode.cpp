#include <iostream>
#include <cstdlib>    // random numbers header file//
#include <ctime>	// used to get date and time information
#include <string>
#include <time.h>
#include "conio.h"
#include "player.h"
#include "results.h"
#include <cstdio>
#include <iomanip>  // for setpresision//

const int scOpt = 14;   //const int for score options listed below//
const int players = 6;

player *playerP[players]; //create array of player objects//
results *resultsP[scOpt]; //array of result objects//

	//create players//
player MVG("Michael Van Gerwen", 60, 75, 72, 90);//highest single accuracy figue can be is 91//
player GA("Gary Anderson", 65, 65, 68, 90);  //name, bull, double, treble, single//
player PW("Peter Wright", 57, 70, 66, 89);
player JW("James Wade", 55, 71, 67, 88);
player RVB("Raymond Van Berneveld", 56, 60, 50, 87);
player DG("Daryl Gurney", 55, 63, 70, 89);

//create results//
results r1("7-0", 0, 0); //score title, amount, percentage//
results r2("7-1", 0, 0);
results r3("7-2", 0, 0);
results r4("7-3", 0, 0);
results r5("7-4", 0, 0);
results r6("7-5", 0, 0);
results r7("7-6", 0, 0);
results r8("0-7", 0, 0);
results r9("1-7", 0, 0);
results r10("2-7", 0, 0);
results r11("3-7", 0, 0);
results r12("4-7", 0, 0);
results r13("5-7", 0, 0);
results r14("6-7", 0, 0);

int player1, player2;

int setNum = 0;///counter for number of sets//
char opt = 'n';

void clearScreen();
int dartsleg1();//player1 throwing first//
int dartsleg2();//player2 throwing first//
int throwForBull();//to decide who throws first in the first set//
int dartsset();//made up of dartsleg1 + dartsleg2 functions//
bool checkFirst(int); // check whether and odd or even numbered leg to decide throw//
int dartsMatch(); 
void runSimulation();


void runSimulation()
{
	double times;

	for (int j = 0; j < scOpt; j++)
	{
		resultsP[j]->setScoreTimes(0);///sets all scores to 0 - was a problems when running multiple simulations//
	}

	cout << "How many time do you want the match to run?" << endl;
	cin >> times;

	for (int i = 0; i < times; i++)
	{
		dartsMatch();
		
		///used a loop here as opposed to 14 if statements(feedback from CMP104)//

		for (int i = 0; i < 7; i++)
		{
			if (((playerP[player1]->getS_score()) == 7) && ((playerP[player2]->getS_score()) == i))
			{
				resultsP[i]->setScoreTimes(resultsP[i]->getScoreTimes()+1);//first 7 options in array
			}

			if (((playerP[player1]->getS_score()) == i) && ((playerP[player2]->getS_score()) == 7))
			{
				resultsP[i+7]->setScoreTimes(resultsP[i+7]->getScoreTimes()+1);
			}
		}
		for (int i = 0; i < scOpt; i++)
		{
			resultsP[i]->calcPerc(times);
		}
		
	}
	clearScreen();
	
	cout << "The predicted results if " << playerP[player1]->getName() << " plays " << playerP[player2]->getName() << " in a World Championship game is.." << endl << endl;
	cout << "-- SCORE ----------- TIMES --------- PERCENT --" << endl << endl;
	for (int i = 0; i < scOpt; i++)
	{
		cout << "    " << resultsP[i]->getScoreTitle() << "                " << resultsP[i]->getScoreTimes() << "             "<< setprecision(5) << resultsP[i]->getScorePerc() <<"%" << endl;
	}
}

int dartsMatch()//takes returns from dartsset and loops until a player wins the match//
{
	playerP[player1]->setS_score(0);
	playerP[player2]->setS_score(0);
	int setResult;

	while (0 < 1)//return will end the loop once player wins 7 sets//
	{
		setResult = dartsset();
		if (setResult == 1)
		{
			playerP[player1]->setS_score(playerP[player1]->getS_score() + 1);
			if ((playerP[player1]->getS_score()) == 7) { return 1; }

		}
		if (setResult == 2)
		{
			playerP[player2]->setS_score(playerP[player2]->getS_score() + 1);
			if ((playerP[player2]->getS_score()) == 7) { return 2; }

		}
	}
}


bool checkFirst(int set) //function to get if an even or odd set (odd = player1 goes first, even = p2)//
{
	bool who;
	if (set % 2 == 0)
		who = true; //is even//
	else
		who = false; // is odd//

	return who;
}


int dartsset()
{
	playerP[player1]->setL_score(0);//sets Legs score to zero at the start of each set//
	playerP[player2]->setL_score(0);
	
	
	if (checkFirst(setNum)==true) //player 1 to throw first//
	{
		while (0 < 1)
		{
			int result = 0;
			result = dartsleg1();
			if (result == 1) { playerP[player1]->setL_score((playerP[player1]->getL_score()) + 1); }//if leg won then add to l_score//
			if (result == 2) { playerP[player2]->setL_score((playerP[player2]->getL_score()) + 1); }
			if ((playerP[player1]->getL_score()) == 3) { setNum++; return 1; } //if player has won 3 legs then set is won//add 1 to setNum//
			if ((playerP[player2]->getL_score()) == 3) { setNum++; return 2; }

			result = dartsleg2();
			if (result == 1) { playerP[player1]->setL_score((playerP[player1]->getL_score()) + 1); }
			if (result == 2) { playerP[player2]->setL_score((playerP[player2]->getL_score()) + 1); }
			if ((playerP[player1]->getL_score()) == 3) { setNum++; return 1; }
			if ((playerP[player2]->getL_score()) == 3) { setNum++; return 2; }
		}
	}

	if (checkFirst(setNum)==false)  //player two to throw first//
	{
		while (0 < 1)
		{
			int result;
			result = dartsleg2();
			if (result == 1) { playerP[player1]->setL_score((playerP[player1]->getL_score()) + 1); }
			if (result == 2) { playerP[player2]->setL_score((playerP[player2]->getL_score()) + 1); }
			if ((playerP[player1]->getL_score()) == 3) { setNum++; return 1; }
			if ((playerP[player2]->getL_score()) == 3) { setNum++; return 2; }

			result = dartsleg1();
			if (result == 1) { playerP[player1]->setL_score((playerP[player1]->getL_score()) + 1); }//if leg won then add to l_score//
			if (result == 2) { playerP[player2]->setL_score((playerP[player2]->getL_score()) + 1); }
			if ((playerP[player1]->getL_score()) == 3) { setNum++; return 1; } //if player has won 3 legs then set is won//
			if ((playerP[player2]->getL_score()) == 3) { setNum++; return 2; }
		}
	}
}

int throwForBull()  ////function to decide who throws first using throw_start() in player class///
{
	while (0 < 1) ///loop until return value - if value are the same(both miss or both hit) the loop will rerun///
	{
		bool bullstart1 = playerP[player1]->throw_start();//attempt to hit bull for " the cork"//
		bool bullstart2 = playerP[player2]->throw_start();
		if ((bullstart1 == 1) && (bullstart2 == 0))
		{
			return 2; //even number for p1 start//
		}
		else if ((bullstart1 == 0) && (bullstart2 == 1))
		{
			return 1; //odd for p2 start//
		}
	}
}

void clearScreen()
{
	system("CLS");
}

int dartsleg1()//player 1 throwing first////
{
	playerP[player1]->setG_score(501);//set gamescores to 501//
	playerP[player2]->setG_score(501);
	int threedartscore1 = 0; ///three darts score kept incase player goes bust//
	int threedartscore2 = 0;

	while (1>0)      ////constant loop until return value exits function/////
	{
		//////player 1 throw//////
		int remainBefore1 = playerP[player1]->getG_score();
		for (int dart = 3; dart > 0; dart--)
		{
			int throwScore = playerP[player1]->strategy(playerP[player1]->getG_score(), dart); //calling strategy with remaining score and amount od darts left as para's//
			
			if ((playerP[player1]->getG_score() - throwScore) == 0)            
			{
				return 1;
			}

			playerP[player1]->deductScore(throwScore);
			threedartscore1 = threedartscore1 + throwScore; 
		}

		if (remainBefore1 < threedartscore1)////reset score if player goes bust//
		{
			playerP[player1]->setG_score(remainBefore1);
		}
		threedartscore1 = 0; //reset three dart score at end of the three darts//


		///////player 2 throw////
		int remainBefore2 = playerP[player2]->getG_score();
		for (int dart = 3; dart > 0; dart--)
		{
			int throwScore = playerP[player2]->strategy(playerP[player2]->getG_score(), dart); //calling strategy with remaining score and amount od darts left as para's//
			
			if  ((playerP[player2]->getG_score() - throwScore) == 0)    
			{
				return 2;
			}

			playerP[player2]->deductScore(throwScore);
			threedartscore2 = threedartscore2 + throwScore;
		}
		
		if (remainBefore2 < threedartscore2)
		{
			playerP[player2]->setG_score(remainBefore2);
		}
		threedartscore2 = 0;//reset three dart score at end of the three darts//
	}

}

int dartsleg2()//player2 throwing first//
{
	{
		playerP[player2]->setG_score(501);//set gamescores to 501//
		playerP[player1]->setG_score(501);
		int threedartscore1 = 0; ///three darts score kept incase player goes bust//
		int threedartscore2 = 0;

		while (1 > 0)      ////constant loop until return value exits function/////
		{
			//////player 2 throw//////
			int remainBefore2 = playerP[player2]->getG_score();
			for (int dart = 3; dart > 0; dart--)
			{
				int throwScore = playerP[player2]->strategy(playerP[player2]->getG_score(), dart); //calling strategy with remaining score and amount od darts left as para's//

				if ((playerP[player2]->getG_score() - throwScore) == 0)   ///player is a winner when throw score = the score they had remaining & that score =0//
				{
					return 2;
				}

				playerP[player2]->deductScore(throwScore);
				threedartscore2 = threedartscore2 + throwScore;

			}

			if (remainBefore2 < threedartscore2)////reset score if player goes bust//
			{
				playerP[player2]->setG_score(remainBefore2);
			}
			threedartscore2 = 0; //reset three dart score at end of the three darts//

			///////player 1 throw////
			int remainBefore1 = playerP[player1]->getG_score();
			for (int dart = 3; dart > 0; dart--)
			{
				int throwScore = playerP[player1]->strategy(playerP[player1]->getG_score(), dart); //calling strategy with remaining score and amount od darts left as para's//

				if ((playerP[player1]->getG_score() - throwScore) == 0)             /////((throwScore == playerP[player2 - 1]->getG_score()) && (((playerP[player2 - 1]->getG_score() - throwScore) == 0)))
				{
					return 1;
				}


				playerP[player1]->deductScore(throwScore);
				threedartscore1 = threedartscore1 + throwScore;
			}

			
			if (remainBefore1 < threedartscore1)
			{
				playerP[player1]->setG_score(remainBefore1);
			}
			threedartscore1 = 0;//reset three dart score at end of the three darts//
		}
	}
}


int main()
{
	int player1form=0;
	int player2form=0 ;
	srand(time(NULL));//initialise random seed//

	//put players into pointer array//
	playerP[0] = &MVG;
	playerP[1] = &GA;
	playerP[2] = &PW;
	playerP[3] = &JW;
	playerP[4] = &RVB;
	playerP[5] = &DG;

	///results into pointer array//
	resultsP[0] = &r1;
	resultsP[1] = &r2;
	resultsP[2] = &r3;
	resultsP[3] = &r4;
	resultsP[4] = &r5;
	resultsP[5] = &r6;
	resultsP[6] = &r7;
	resultsP[7] = &r8;
	resultsP[8] = &r9;
	resultsP[9] = &r10;
	resultsP[10] = &r11;
	resultsP[11] = &r12;
	resultsP[12] = &r13;
	resultsP[13] = &r14;

	do
	{
		clearScreen();
		cout << "Please pick what players we want to simulate playing..." << endl;
		cout << "1. Michael Van Gerwen" << endl;
		cout << "2. Gary Anderson" << endl;
		cout << "3. Peter Wright" << endl;
		cout << "4. James Wade" << endl;
		cout << "5. Raymond Van Barneveld" << endl;
		cout << "6. Daryl Gurney" << endl << endl;
		cout << "Who would you like the first player to be(enter player number)?";
		
		do {
			cin >> player1;
			if (player1 < 1 || player1 > 6) { cout << "That is not a valid player - choose again!"; }///late addition to the program to ensure valid player & form//
		} while (player1 < 1 || player1 > 6);
	
		cout << "What is his form (1 rubbish -> 5 excellent)";//add/subtract from treble & double stats//
		
		
		do {
			cin >> player1form;
			if (player1form < 1 || player1form>5) { cout << "That is not a vaid form figure - try again entering a number between 1 and 5..." << endl; }
		} while (player1form < 1 || player1form>5);
		cout << "Who would you like the second player to be(enter player number)?";
		
		
		do {
			cin >> player2;
			if (((player2 < 1 || player2 > 6) || (player1 == player2))) { cout << "That is not a valid player - choose again!"; }
		} while ((player2 < 1 || player2 > 6) || (player1 == player2));
	
		
		
		cout << "What is his form (1 rubbish -> 5 excellent)";
		do {
			cin >> player2form;
			if (player2form < 1 || player2form>5) { cout << "That is not a vaid form figure - try again entering a number between 1 and 5..." << endl; }
		} while (player2form < 1 || player2form>5);
		cout << "Who would you like the second player to be(enter player number)?";

		clearScreen();

		player1 = player1 - 1; // so input value = arraynumber//
		player2 = player2 - 1;

		playerP[player1]->setT_accuracy(playerP[player1]->getT_accuracy() + (player1form - 3)); //5= +2 improvement   1= -2 detraction//
		playerP[player2]->setT_accuracy(playerP[player2]->getT_accuracy() + (player2form - 3)); //5= +2 improvement   1= -2 detraction//
		playerP[player1]->setD_accuracy(playerP[player1]->getD_accuracy() + (player1form - 3)); //5= +2 improvement   1= -2 detraction//
		playerP[player2]->setD_accuracy(playerP[player2]->getD_accuracy() + (player2form - 3));

		cout << endl << "LETS PLAY DARTS!!!!" << endl;
		cout << "The match we are going to simulate is " << playerP[player1]->getName() << " vs " << playerP[player2]->getName() << endl << endl;
		cout << "You have given " << playerP[player1]->getName() << " a form figue of " << player1form << " and " << playerP[player2]->getName() << " a form figue of " << player2form << endl;

		setNum = throwForBull(); //starts on set 1(odd) if player1 wins throw off, starts on 2 for P2//

		runSimulation();
		
		cout << "Would you like to simulate another match? Type y for Yes(anything else will exit)";
		cin >> opt;
	} while (opt=='y');

		return 0;

}
