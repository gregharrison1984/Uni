#pragma once
#include <string>
using namespace std;

class player
{
private:
	///varables///
	string name;
	int b_accuracy;  //accuracy at bull//
	int d_accuracy;  //accuracy on doubles//
	int t_accuracy;  //accuracy on trebles//
	int s_accuracy;   //accuracy on singles//
	int g_score;  //game score(from 501)//
	int l_score;  //leg score//
	int s_score;  //set score//

public:
	player();
	player(string, int, int, int, int);
	~player();


	///setters////
	void setName(string);
	void setB_accuracy(int);
	void setD_accuracy(int);
	void setT_accuracy(int);
	void setS_accuracy(int);
	void setG_score(int);
	void setL_score(int);
	void setS_score(int);
	

	///getters///
	string getName();
	int getB_accuracy();
	int getD_accuracy();
	int getT_accuracy();
	int getS_accuracy();
	int getG_score();
	int getL_score();
	int getS_score();
	
	///functions///

	int throw_single(int);
	int throw_double(int);
	int throw_treble(int);
	int throw_bull();
	bool throw_start();
	void deductScore(int);
	int strategy(int, int);


};

