#pragma once
#include <iostream>
#include <vector>
using namespace std;

void maxHeapify(vector<int> &A, int i, int heapSize);
void buildMaxHeap(vector<int> &A);
void heapsort(vector<int> &A);
int leftChild(int parentIndex);
int rightChild(int parentIndex);

void quicksort(vector<int> &A, int l, int r);
int partition(vector<int> &A, int l, int r);

