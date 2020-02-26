#pragma once
#include <string>
using namespace std;

class results
{
private:
	string scoreTitle;
	double scoreTimes;
	double scorePerc;

public:
	results(string, double, double);
	~results();

	////setters////
	void setScoreTitle(string);
	void setScoreTimes(double);
	void setScorePerc(double);

	///getters////
	string getScoreTitle();
	double getScoreTimes();
	double getScorePerc();

	///functions///
	void calcPerc(double);
};

