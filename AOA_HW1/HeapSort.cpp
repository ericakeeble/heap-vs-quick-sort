/*	GRADING: HEAP	*/
#include "Sorts.h"

void maxHeapify(vector<int> &A, int i, int heapSize)
{
	int indexOfLargest;
	int l = leftChild(i);
	int r = rightChild(i);
	
	if (l < heapSize && A[l] > A[i])
		indexOfLargest = l;
	else
		indexOfLargest = i;

	if (r < heapSize && A[r] > A[indexOfLargest])
		indexOfLargest = r;
	
	if (indexOfLargest != i)
	{
		swap(A[i], A[indexOfLargest]);
		maxHeapify(A, indexOfLargest, heapSize);
	}
}


void buildMaxHeap(vector<int> &A)
{
	for (int i = A.size() / 2; i >= 0; i--)
		maxHeapify(A, i, A.size());
}


void heapsort(vector<int> &A)
{
	int heapSize = A.size();
	buildMaxHeap(A);
	for(int i = A.size()-1; i > 0; i--)
	{
		swap(A[0], A[i]);
		heapSize--;
		maxHeapify(A, 0, heapSize);
	}
}

int leftChild(int parentIndex)
{
	return parentIndex * 2 + 1;
}

int rightChild(int parentIndex)
{
	return parentIndex * 2 + 2;
}
