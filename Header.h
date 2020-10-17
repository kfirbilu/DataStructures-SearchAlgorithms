//Name: Kfir Bilu
//I.D: 205639230

//search 1 -  Linear search
//search 2 - Binary search
//search 3 - Exponential search



#pragma once

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>

#define SIZE 1000    // changeable
using namespace std;

class Search {

private:
	float _count1 = 0;
	float _count2 = 0;
	float _count3 = 0;



public:
	Search();  // constructor 
	int Search1(int arrV[], int m, int x);
	int Search2(int arrV[], int m, int x);
	int Search3(int arrV[], int end, int x, int start = 0);
	int Search3B(int arrV[], int m, int x,int count3, int start = 0);
	void removeDup(int arr[], int arrSize);
	void bubbleSort(int arr[], int arrSize);
	void pushZeroToEnd(int arr[], int n);
	float getCount1();
	float getCount2();
	float getCount3();


};