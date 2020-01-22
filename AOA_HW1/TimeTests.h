#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;

void timeTests();
void testVector(int size);
template<typename T> void printElement(T t, const int& width);
template<typename T>void printRow(T col1, T col2, T col3);
