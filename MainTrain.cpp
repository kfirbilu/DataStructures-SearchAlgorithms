//Name: Kfir Bilu
//I.D: 205639230

//search 1 -  Linear search
//search 2 - Binary search
//search 3 - Exponential search

#include <iostream>
using namespace std;

#include "Header.h"


int main()
{
	Search newSearch;

	
	srand((unsigned)time(0));
	int randomNumber;
	int N;  // number of numbers that are not zero


	for (int i = 0; i < SIZE; i++)   // runs the search functions on 1000 different arrays
	{
		//cout << "********  Iteration number: "<<i+1 <<"  ********" << endl;
		randomNumber = rand() % SIZE + 1;   // generates a random number between 0-1000
		
		N = randomNumber;   // the amout of numbers that are not zero
		
		int arr[SIZE] = { 0 };  // creates new array and fills it with 0
		for (int k = 0; k < randomNumber; k++)  //fills the array with random numbers until random location, the rest are 0
		{
			arr[k]= rand() % SIZE+1;
		}


		int x= (rand() % SIZE+1);   // generates a random number to find in the array
		

		//cout << "Random number of filled cells: " << N << endl;
		//cout << "Random number to find (x): " << x << endl;
		

		newSearch.removeDup(arr, SIZE);   // removes duplicate numbers in the array
		newSearch.bubbleSort(arr, SIZE);  //sorting the array from smallest to largest
		newSearch.pushZeroToEnd(arr, SIZE);  // pushes all the zeros to the end of the array

		newSearch.Search1(arr, SIZE, x);   // runs search 1 on the array
		newSearch.Search2(arr, SIZE, x);   // runs search 2 on the array
		newSearch.Search3(arr,SIZE,x,0);   // runs search 3 on the array
		

	

		//cout << "Done checking array number " << i+1 << endl<<endl;
	
	}


	cout << "Linear search (O(n)) - The average number of iterations is:  " << newSearch.getCount1() / SIZE << endl << endl;
	cout << "Binary search (O(log(m))) - The average number of iterations is:  " << newSearch.getCount2() / SIZE << endl << endl;
	cout << "Exponential search (O(log(m))) - The average number of iterations is:  " << newSearch.getCount3() / SIZE /2 << endl << endl;

	cout << "Linear search (O(n)) - Total iterations:  " << newSearch.getCount1() << endl << endl;
	cout << "Binary search (O(log(m))) - Total iterations:  " << newSearch.getCount2() << endl << endl;
	cout << "Exponential search (O(log(m))) - Total iterations:  " << newSearch.getCount3()/2  << endl << endl;



	return 0;
}








