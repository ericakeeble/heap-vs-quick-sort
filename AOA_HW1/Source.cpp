
#include <iostream>
#include <iomanip>
#include <time.h>
#include <vector>
#include <chrono>
#include <sstream>
#include "Sorts.h"
#include "TimeTests.h"
using namespace std;
void test(vector<int> input);
void userInput();
void timeTests();
void printVector(vector<int> a);
void printVectorandPassFail(vector<int> a);

/******************************************************
Template function for running correctness tests
GRADING: CORRECTNESS TESTS
******************************************************/
void correctness() {
	vector<int> set1 = { 2,1 };
	vector<int> set2 = { 1, 3, 2 };
	vector<int> set3 = { 2, 2, 1, 3, 5, 4, 8, 0 };
	vector<int> set4; //fill in test4 with 9 random values
	for (int i = 0; i < 9; i++)
		set4.push_back(rand() % 1000);

	cout << endl << endl;

	cout <<  "Test 1: Basic sort with 2 elements" << endl;
	test(set1);

	cout << "Test 2: Basic sort with 3 elements" << endl;
	test(set2);

	cout << "Test 3: Basic sort with even # of elements" << endl;
	test(set3);

	cout << "Test 4: Basic sort with odd # of elements" << endl;
	test(set4);
	
	cout << endl << endl;
}

void test(vector<int> input)
{
	bool PASS = true;
	vector<int> input1(input);

	cout << "Original: ";
	printVector(input);
	cout << endl;

	/*	QUICKSORT	*/
	quicksort(input, 0, input.size() - 1);
	cout << "Quick Result: ";
	printVectorandPassFail(input);

	/*	HEAPSORT	*/
	heapsort(input1);
	cout << "Heap Result: ";
	printVectorandPassFail(input1);
	cout << endl << endl;
}

void userInput()
{
	vector<int> input;
	string str;
	int temp;

	cout << "User Format: ( # # # ... -999): " << endl << endl;
	cout << "Input: ";

	while (cin >> str && str != "-999")
	{
		if (str != "(")
		{
			temp = stoi(str);
			input.push_back(temp);
		}
	}
	
	vector<int> input1(input);

	cout << "Heapsort: ";
	heapsort(input);
	printVector(input);
	cout << endl << "Quicksort: ";
	quicksort(input1,0,input1.size()-1);
	printVector(input1);

	cout << endl << endl;
}

void printVector(vector<int> a)
{
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ", ";
}

void printVectorandPassFail(vector<int> a)
{
	bool PASS = true;
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << ", ";
		if (i > 0 && a[i - 1] > a[i])
			PASS = false;
	}
	cout << endl;
	if (PASS == true)
		cout << "PASS";
	else
		cout << "FAIL";
	cout << endl;
}

int main() {
	char choice = 'c';

	while (toupper(choice) != 'Q') {
		cout << "\nEnter T to run correctness tests\n"
			<< "Enter U to run accept user input\n"
			<< "Enter E to run time tests\n" << endl
			<< "Enter Q to quit" << endl;

		cout << "Choice: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
			case 'T':
				correctness();
				break;
			case 'U':
				userInput();
				break;
			case 'E':
				timeTests();
				break;
		}
		
	}

	return 0;

}
