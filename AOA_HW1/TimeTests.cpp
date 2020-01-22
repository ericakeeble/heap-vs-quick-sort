#include "TimeTests.h"
#include "Sorts.h"

void timeTests()
{
	vector<int> Length = { 50,100,200,500,1000,2000,5000,10000,50000,100000,150000,200000,500000 };

	printRow("Size", "Quick Average", "Heap Average");

	for (int i = 0; i < (int)Length.size(); i++)
		testVector(Length[i]);	
}

void testVector(int size)
{
	vector<int> values;
	double start;
	double stop;
	int durationHeap[3];
	int durationQuick[3];
	int heapAvg;
	int quickAvg;

	for (int i = 0; i < 3; i++)
	{
		for (int i = 0; i < size; i++)
			values.push_back(rand() % 10000);

		vector<int> values1(values);

		//time heapsort
		start = clock();
		heapsort(values);
		stop = clock();
		durationHeap[i] = (int)((double)(stop - start) / (CLOCKS_PER_SEC / 1000.0));

		//time quicksort
		start = clock();
		quicksort(values1, 0, values1.size() - 1);
		stop = clock();
		durationQuick[i] = (int)((double)(stop - start) / (CLOCKS_PER_SEC / 1000.0));
	}

	quickAvg = (durationQuick[0] + durationQuick[1] + durationQuick[2]) / 3;
	heapAvg = (durationHeap[0] + durationHeap[1] + durationHeap[2]) / 3;

	printRow(size, (int)quickAvg, (int)heapAvg);
}



/* NOTE Some of the code used to print table taken from from the internet at:
	https://stackoverflow.com/questions/14765155/how-can-i-easily-format-my-data-table-in-c */
template<typename T>void printRow(T col1, T col2, T col3)
{
	int colsWidth = 15;
	int col1Width = 8;

	printElement(col1, col1Width);
	printElement(col2, colsWidth);
	printElement(col3, colsWidth);
	
	cout << endl;
}

template<typename T> void printElement(T t, const int& width)
{
	cout << left << setw(width) << setfill(' ') << t;
}
