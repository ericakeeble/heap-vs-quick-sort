/*	GRADING: QUICK	*/
#include "Sorts.h"

int partition(vector<int> &A, int l, int r)
{
	int pivot = A[r];
	int i = l - 1;
	for (int j = l; j < r; j++)
	{
		if (A[j] <= pivot)
		{
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}

void quicksort(vector<int> &A, int l, int r)
{
	if (l < r)
	{
		int q = partition(A, l, r);
		quicksort(A, l, q - 1);
		quicksort(A, q + 1, r);
	}
}