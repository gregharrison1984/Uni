
#include<chrono>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <cstdlib>
#include <fstream>
using std::chrono::duration_cast;
using std::chrono::nanoseconds;
using the_clock = std::chrono::steady_clock;

using namespace std;
//create data type Position to handle very long numbers
using Position = long long int;
using the_clock = chrono::steady_clock;

enum Algorithm
{
	bruteForce = 1,
	boyerMoore = 2,
	boyerMooreVector = 3
};

void die(const string& msg) {
	cerr << "Error: " << msg << "\n";
#ifdef _DEBUG
	abort();
#else
	exit(1);
#endif
}

void StartTimer();
void EndTimer(int, string);
void CalculateTimeTaken(the_clock::time_point startTime, the_clock::time_point endTime, int algorithm, string filename);

// numbers of chars in alphabet
const int alpha = 256;
int badc[alpha];

list<Position> bruteforce(string &pattern, string &text, string &filename)
{
	list <Position> results;
	list<Position>::iterator it = results.begin();
	int m = pattern.size();
	int n = text.size();
	int q = (n - m) - 1;
	int j;

	StartTimer();

	for (int i = 0; i < q; i++)
	{
		for (j = 0; j < m; j++)
			if (text[i + j] != pattern[j])
				break;
		if (j == m) results.insert(it, i);
	}

	EndTimer(bruteForce, filename);
	return results;
}

//Boyer-Moore 
list<Position> search_BM_list(string &pattern, string &text, string &filename)
{	
	//set results var and it
	list<Position> results;
	list<Position>::iterator it = results.begin();

	//get string sizes and ititiate skipp
	Position m = pattern.size();
	Position n = text.size();
	Position skip;

	//sets all characters as -1
	for (Position i = 0; i < 256; i++)
	{
		badc[i] = -1;
	}
	
	//set all characters in pattern to distance from right
	for (Position i = 0; i < m; i++)
	{
		badc[pattern[i]] = i;
	}
	
	for (Position i = 0; i <= n - m; i += skip)
	{
		skip = 0;
		for (Position j = m - 1; j >= 0; j--)
		{
			if ((char)pattern[j] != (char)text[i + j])
			{
				skip = j - badc[(char)text[i + j]];
				if (skip < 1) 
				{ 
					skip = 1; 
				}
			}
		}
		if (skip == 0)
		{
			results.insert(it, i); //found at position i
			i++;
		}
	}

	EndTimer(boyerMoore, filename);
	return results; // not found so returns end of pattern
}

vector<Position> results;
//Boyer-Moore Vector
vector<Position> search_BM_vector(string &pattern, string &text, string &filename)
{
	//set results var and it
	
	vector<Position>::iterator it = results.begin();

	//get string sizes and ititiate skipp
	Position m = pattern.size();
	Position n = text.size();
	Position skip;

	//sets all characters as -1
	for (Position i = 0; i < 256; i++)
	{
		badc[i] = -1;
	}

	//set all characters in pattern to distance from right
	for (Position i = 0; i < m; i++)
	{
		badc[pattern[i]] = i;
	}

	for (Position i = 0; i <= n - m; i += skip)
	{
		skip = 0;
		for (Position j = m - 1; j >= 0; j--)
		{
			if ((char)pattern[j] != (char)text[i + j])
			{
				skip = j - badc[(char)text[i + j]];
				if (skip < 1)
				{
					skip = 1;
				}
			}
		}
		if (skip == 0)
		{
			it = results.insert(it, i); //found at position i
			i++;
		}
	}

	EndTimer(boyerMooreVector, filename);
	return results; // not found so returns end of pattern
}

the_clock::time_point starttime;
the_clock::time_point endtime;
void StartTimer()
{
	starttime = the_clock::now();
}

void EndTimer(int algorithm, string filename)
{
	endtime = the_clock::now();

	CalculateTimeTaken(starttime, endtime, algorithm, filename);
}

void WriteToFile(ofstream file, string text)
{

}

fstream csvFile;
void CalculateTimeTaken(the_clock::time_point startTime, the_clock::time_point endTime, int algorithm, string filename)
{
	auto time_taken = duration_cast<nanoseconds>(endtime - starttime).count();


	char filenameCSV[] = "algorithm_data.csv";
	

	csvFile.open(filenameCSV, std::fstream::in | std::fstream::out | std::fstream::app);

	switch (algorithm)
	{
	case bruteForce:
		// If file does not exist, Create new file
		if (!csvFile)
		{
			csvFile.open(filenameCSV, fstream::in | fstream::out | fstream::trunc);
			csvFile << endl << "Algorithm: Bruteforce (list) " << "," << time_taken << " ,nanoseconds " << ",Book: " << "," << filename;
			csvFile.close();
		}
		else
		{
			csvFile << endl << "Algorithm: Bruteforce (list) " << "," << time_taken << " ,nanoseconds " << ",Book: " << "," << filename;
			csvFile.close();
		}
		break;
	case boyerMoore:
		if (!csvFile)
		{
			csvFile.open(filenameCSV, fstream::in | fstream::out | fstream::trunc);
			csvFile << endl << "Algorithm: Boyer-Moore (list) " << "," << time_taken << " ,nanoseconds " << ",Book: " << "," << filename;
			csvFile.close();
		}
		else
		{
			csvFile << endl << "Algorithm: Boyer-Moore (list) " <<  "," << time_taken << " ,nanoseconds " << ",Book: " << "," << filename;
			csvFile.close();
		}
		break;
	case boyerMooreVector:
		if (!csvFile)
		{
			csvFile.open(filenameCSV, fstream::in | fstream::out | fstream::trunc);
			csvFile << endl << "Algorithm: Boyer-Moore (vector) " << "," << time_taken << " ,nanoseconds " << ",Book: " << "," << filename;
			csvFile.close();
		}
		else
		{
			csvFile << endl << "Algorithm: Boyer-Moore (vector) " << "," << time_taken << " ,nanoseconds " << ",Book: " << "," << filename;
			csvFile.close();
		}
		break;
	default:
		break;
	}
}

///Adam's function to load a text file
void load_file(const string& filename, string& str) {
	// To make this program less fussy about where exactly it's run
	// from relative to the file, try looking in parent directories too.
	std::string directory = "";
	for (int i = 0; i < 6; i++) {
		ifstream f(directory + filename, std::ios_base::binary);
		if (!f.good()) {
			directory = "../" + directory;
			continue;
		}

		// Seek to the end of the file to find its length.
		f.seekg(0, std::ios_base::end);
		const size_t length = f.tellg();

		// Seek back to the start of the file and read the data.
		vector<char> buf(length);
		f.seekg(0);
		f.read(buf.data(), length);
		str.assign(buf.begin(), buf.end());

		return;
	}
	die("Unable to find " + filename);
}

// overload for list results
void OutputResults(list<Position> results, string pattern)
{
	//outputs results
	for (Position n : results)
	{
		cout << n << '\n';
	}

	cout << "There are " << results.size() << " instances of " << pattern << " in the text" << endl;
	cout << "happy?" << endl << endl;
}

// overload for vector results
void OutputResults(vector<Position> results, string &pattern)							
{
	//outputs results
	for (Position n : results)
	{
		cout << n << '\n';
	}

	cout << "There are " << results.size() << " instances of " << pattern << " in the text" << endl;
	cout << "happy?" << endl << endl;
}

int main()
{
	int inputdoc;
	string pattern;
	string text;
	string filename;

	cout << "What string do you want to find?" << endl;
	cin >> pattern;

	cout << endl << endl << "What text document do you want to search" << endl;
	cout << "1. hacktest.txt(approx 19k)" << endl;
	cout << "2. csv.txt(100k)" << endl;
	cout << "3. dickens_scrooge.txt(approx 150k)" << endl;
	cout << "4. darwin_species.txt(approx 1m)" << endl;
	cout << "5. wealth_nations.txt(approx 2m)" << endl;
	cin >> inputdoc;

	if (inputdoc == 1) { filename = "hacktest.txt"; }
	if (inputdoc == 2) { filename = "csv.txt"; }
	if (inputdoc == 3) { filename = "dickens_scrooge.txt"; }
	if (inputdoc == 4) { filename = "darwin_species.txt"; }
	if (inputdoc == 5) { filename = "wealth_nations.txt"; }

	load_file(filename, text);

	int searchtype = 0;
	while (searchtype != 1 && searchtype != 2 && searchtype != 3)
	{
		cout << "What search should we run" << endl;
		cout << "Type 1 for a bruteforce with lists, 2 for Boyer-Moore with lists or 3 for Boyer-Moore with Vectors" << endl;
		cin >> searchtype;
	}

	switch (searchtype)
	{
	case 1:
		OutputResults(bruteforce(pattern, text, filename), pattern);
		break;
	case 2:
		OutputResults(search_BM_list(pattern, text, filename), pattern);
		break;
	case 3:
		OutputResults(search_BM_vector(pattern, text, filename), pattern);
		break;
	default: 
		break;
	}

	system("pause");
}