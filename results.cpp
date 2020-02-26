#include "results.h"
#include <string>
#include <iostream>
results::results(string a, double b, double c)
{
	scoreTitle = a;
	scoreTimes = b;
	scorePerc = c;
}

results::~results()
{
}

///setters//

void results::setScoreTitle(string a) { scoreTitle = a; }
void results::setScoreTimes(double b) { scoreTimes = b; }
void results::setScorePerc(double c) { scorePerc = c; }

///getters
string results::getScoreTitle() { return scoreTitle; }
double results::getScoreTimes() { return scoreTimes; }
double results::getScorePerc() { return scorePerc; }

///functions///
void results::calcPerc(double times)
{
	scorePerc = ((scoreTimes / times) * 100);
}

