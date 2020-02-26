#include "player.h"
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include "conio.h"
using namespace std;

player::player() {}

player::player(string a, int b, int c, int d, int e)
{
	name = a; //name//
	b_accuracy = b;  //accuracy at bull//
	d_accuracy = c;  //accuracy on doubles//
	t_accuracy = d;  //accuracy on trebles//
	s_accuracy = e; //single accuracy//
}


player::~player() {}

///setters///
void player::setName(string a) { name = a; }
void player::setB_accuracy(int b) { b_accuracy = b; }
void player::setD_accuracy(int c) { d_accuracy = c; }
void player::setT_accuracy(int d) { t_accuracy = d; }
void player::setS_accuracy(int e) { s_accuracy = e; }
void player::setG_score(int f) { g_score = f; }
void player::setL_score(int g) { l_score = g; }
void player::setS_score(int h) { s_score = h; }

///getters///
string player::getName() { return name; }
int player::getB_accuracy() { return b_accuracy; }
int player::getD_accuracy() { return d_accuracy; }
int player::getT_accuracy() { return t_accuracy; }
int player::getS_accuracy() { return s_accuracy; }
int player::getG_score() { return g_score; }
int player::getL_score() { return l_score; }
int player::getS_score() { return s_score; }


//functions
int player::throw_bull() {

	//  Throw for the bull with accuracy p%  (20<p<85)

	int r = rand() % 100;

	if (r < (b_accuracy - 20))
		return 50;
	else if (r < 85)
		return 25;
	else
		return 1 + rand() % 20;
}

bool player::throw_start() 
{
// Throw for bull for throw//
	int r = rand() % 100;

	if (r < (b_accuracy))
		return 1;

	else return 0;
}

int player::throw_treble(int d) {

	//  return result of throwing for treble d with accuracy p%  (o<90)

	// Board neighbours ignoring slot zero
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };

	int r = rand() % 100; //tested and random every single time!!!//


	if (r < t_accuracy)
		return 3 * d;
	else if (r < 90)
		return d;
	else if (r < 93)
		return 3 * bd[0][d];
	else if (r < 96)
		return 3 * bd[1][d];
	else if (r < 98)
		return bd[0][d];
	else
		return bd[1][d];
}

int player::throw_double(int d)
{

	//  return result of throwing for double d

	// Board neighbours ignoring slot zero
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };
	int r = rand() % 100;

	if (r < d_accuracy)
		return 2 * d;
	else if (r < 85)
		return 0;
	else if (r < 90)
		return d;
	else if (r < 93)
		return 2 * bd[0][d];
	else if (r < 96)
		return 2 * bd[1][d];
	else if (r < 98)
		return bd[0][d];
	else
		return bd[1][d];
}

int player::throw_single(int d) {

	//  return result of throwing for single d with accuracy 88% (or 80% for the outer)

	// Board neighbours ignoring slot zero
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };
	int r = rand() % 100;

	if (d == 25) {		// outer  80%
		if (r < (s_accuracy-5))
			return 25;
		else if (r > (s_accuracy-5))
			return 50;
		else
			return 1 + rand() % 20;
	}
	else			// 1 to 20 single
		if (r < s_accuracy)
			return d;
		else if (r < (s_accuracy +3))
			return bd[0][d];
		else if (r < (s_accuracy +5))
			return bd[1][d];
		else if (r < (s_accuracy +8))
			return 3 * d;
		else
			return 2 * d;
}

void player::deductScore(int ds)
{
	g_score = g_score - ds;
}

int player::strategy(int remaining, int dartsLeft) ////lost 3 hours not entering "player::" ////
{
	if ((remaining == 50) && (dartsLeft == 1)) ///lost another 3 days not having "==" and seperating the else if statements! ////
	{
		return throw_bull();
	}
	else if (remaining == 139 || remaining == 129 || remaining == 126 || remaining == 123 || remaining == 119 
		|| remaining == 115 || remaining == 108 || remaining == 105 || remaining == 102 || remaining == 99 
		|| remaining == 97 || remaining == 95 || remaining == 93 || remaining == 89 || remaining == 81 || remaining == 79 || remaining == 73)
	{
		return throw_treble(19);
	}
	else if (remaining == 128 || remaining == 121 || remaining == 104 || remaining == 94 || remaining == 90 
		|| remaining == 86 || remaining == 78 || remaining == 70)
	{
		return throw_treble(18);
	}
	else if (remaining == 103 || remaining == 101 || remaining == 91 || remaining == 87 || remaining == 83 
		|| remaining == 75 || remaining == 67)
	{
		return throw_treble(17);
	}
	else if (remaining == 88 || remaining == 72 || remaining == 64)
	{
		return throw_treble(16);
	}
	else if (remaining == 85 || remaining == 77 || remaining == 69 || remaining == 61)
	{
		return throw_treble(15);
	}
	else if (remaining == 82 || remaining == 74 || remaining == 66)
	{
		return throw_treble(14);
	}
	else if (remaining == 71 || remaining == 63)
	{
		return throw_treble(13);
	}
	else if (remaining == 65)
	{
		return throw_treble(11);
	}
	else if (remaining == 62)
	{
		return throw_treble(10);
	}
	else if (remaining == 132 || remaining == 125)
	{
		return throw_single(25);
	}
	else if (remaining == 60)
	{
		return throw_single(20);
	}
	else if (remaining == 59)
	{
		return throw_single(19);
	}
	else if (remaining == 58)
	{
		return throw_single(18);
	}
	else if (remaining == 57)
	{
		return throw_single(17);
	}
	else if (remaining == 56)
	{
		return throw_single(16);
	}
	else if (remaining == 55)
	{
		return throw_single(15);
	}
	else if (remaining == 54)
	{
		return throw_single(14);
	}
	else if (remaining == 53 || remaining == 45 || remaining == 35)
	{
		return throw_single(13);
	}
	else if (remaining == 52 || remaining == 44)
	{
		return throw_single(12);
	}
	else if (remaining == 51 || remaining == 43 || remaining == 27)
	{
		return throw_single(11);
	}
	else if (remaining == 50 || remaining == 42)
	{
		return throw_single(10);
	}
	else if (remaining == 49 || remaining == 41 || remaining == 25 || remaining == 33)
	{
		return throw_single(9);
	}
	else if (remaining == 48)
	{
		return throw_single(8);
	}
	else if (remaining == 47 || remaining == 39 || remaining == 31 || remaining == 23)
	{
		return throw_single(7);
	}
	else if (remaining == 46)
	{
		return throw_single(6);
	}
	else if (remaining == 37 || remaining == 29 || remaining == 21)
	{
		return throw_single(5);
	}
	else if (remaining == 19 || remaining == 15 || remaining == 11 || remaining == 7)
	{
		return throw_single(3);
	}
	else if (remaining == 17 || remaining == 13 || remaining == 9 || remaining == 5 || remaining == 3)
	{
		return throw_single(1);
	}
	////////TO WIN//////

	else 
	{
	//check to see if left on a double and shorten code//
	int doubles[20]{ 40,38,36,34,32,30,28,26,24,22,20,18,16,14,12,10,8,6,4,2 };
	for (int i = 0; i < 20; i++)
	{
		if (remaining == doubles[i])
		{
			return throw_double(doubles[i] / 2);
		}
	}
		return throw_treble(20);
	}
}