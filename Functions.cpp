//Name: Kfir Bilu
//I.D: 205639230

//search 1 -  Linear search
//search 2 - Binary search
//search 3 - Exponential search


#include "Header.h"


//////////*********  Constructor and get functions  *********//////////


Search::Search()    // constructor for new search, initializes the counts to zero
{
	this->_count1 = 0;
	this->_count2 = 0;
	this->_count3 = 0;
}

float Search::getCount1()   // gets number of iterations after Linear search
{
	return this->_count1;
}

float Search::getCount2()   // gets number of iterations after Binary search
{
	return this->_count2;
}

float Search::getCount3()   // gets number of iterations after Exponential search
{
	return this->_count3;
}




//////////*********  search 1 -  Linear search *********//////////
// goes through each cell of the array


int Search:: Search1(int arrV[], int m, int x)    // O(n)
{
	int count1 = 0;   // counter that sums the number of iterations
	int i = 0;
	while (arrV[i] != 0)
	{
		if (arrV[i] == x)     // if you hace reached the number you are looking for
		{
			count1++;
			//cout <<"Linear search (O(n)) - Number of iterations: "<< count1 << endl;
			//cout << "Linear search (O(n)) - Number found at index: " << i << endl;
			this->_count1 += count1;
			return i;
		}
		count1++;
		i++;
	}
	//cout << "Linear search (O(n)) - Number of iterations: " << count1 << endl;
	//cout << "Linear search (O(n)) - Number not found" << endl;
	this->_count1 += count1;
	return -1;
}



//////////*********  search 2 - Binary search  *********//////////
// spliting the array by two each iteration, making it smaller and smaller


int Search::Search2(int arrV[], int m, int x)
{
	int count2 = 0;
	int low = 0;
	int middle;
	int high = m - 1;



	while (low <= high)   // while checking range is bigger than 0
	{
		middle = (low + high) / 2;   // middle of the array

		if (x == arrV[middle])
		{
			count2++;// counts the iterations this for does
			this->_count2 += count2;    // saves the number of iterations
			//cout << "Binary search (O(log(m))) - Number of iterations: " << count2 << endl;
			//cout << "Binary search (O(log(m))) - Number found at index: " << middle << endl;
			return middle;
		}
		else if (x > arrV[middle])
		{
			low = middle + 1;
			count2++;
		}
		else
		{
			count2++;
			high = middle - 1;
		}
	}
	count2++;
	this->_count2 += count2;
	//cout << "Binary search (O(log(m))) - Number of iterations: " << count2 << endl;
	//cout << "Binary search (O(log(m))) - Number not found" << endl;
	return -1;

}




//////////*********  search 3 - Exponential search   *********//////////
// spliting the array by two each iteration, making it smaller and smaller


int Search::Search3(int arrV[], int end, int x, int start)
{
	int count3 = 0;
	if (end - start < 0)  // if the array has no numbers in it
	{
		count3++;
		this->_count3 += count3;
		return -1;
	}

	int i = 1;

	while (i < end - start)   // while i is smaller than the size of the array
	{

		if (arrV[i] < x)  // if the specific item is smaller than the the number we are looking for multiply i by 2
		{

			i = (i * 2);  // multiplies the left cell to check by 2 
			count3++;

		}
		else  
		{

			break;

		}

	}
	count3++;
	this->_count3 += count3;
	if (i > end)
	{
		return Search3B(arrV, end, x, count3, i / 2);   // send end of the array in case that i is greater than the size of the array
	}
	else return Search3B(arrV, i, x, count3, i / 2);   // sends to the binary search function the most limited range of cells to find x
	
	

}


int Search::Search3B(int arrV[], int m, int x,int count3, int start)   // binary search on a smaller range of the array 
{
	
	int count33 = 0;
	int low = start;
	int middle;
	int high = m - 1;



	while (low <= high)
	{
		middle = (low + high) / 2;

		if (x == arrV[middle])
		{
			count33++;
			this->_count3 += count33;
			//cout << "Exponential search - Number of iterations: " << count33 << endl;
			//cout << "Exponential search - Number found at index: " << middle << endl;
			return middle;
		}
		else if (x > arrV[middle])
		{
			low = middle + 1;
			count33++;
		}
		else
		{
			count33++;
			high = middle - 1;
		}
	}
	count33++;
	this->_count3 += count33;
	//cout << "Exponential search - Number of iterations: " << count33 << endl;
	//cout << "Exponential search - Number not found" << endl;
	return -1;

}












//////////*********  Remove Duplicates  *********//////////

void Search::removeDup(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		for (int k = i+1; k < arrSize-1; k++)
		{
			if (arr[i] == arr[k])
			{
				arr[k] = 0;
			}
		}
	}
}


//////////*********  Bubble Sort  *********//////////

void Search::bubbleSort(int arr[], int arrSize)
{
	int k = 0, i = 0;
	int temp;
	while (k < arrSize)
	{
		for (i = 0; i < arrSize; i++)
		{
			for (int j = 0; j < arrSize-1; j++)
			{
				if (arr[i] < arr[j]&&arr[i]!=0&&arr[j]!=0)
				{
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
				
			}
		}
		k++;
	}
}




//////////*********  push zero to end  *********//////////


void Search::pushZeroToEnd(int arr[], int size)
{
	int count = 0;  // Count of non-zero elements 

   
	for (int i = 0; i < size; i++)
		if (arr[i] != 0)
		{
			arr[count++] = arr[i];
		}
								   
	while (count < size)
	{
		arr[count++] = 0;
	}
}






