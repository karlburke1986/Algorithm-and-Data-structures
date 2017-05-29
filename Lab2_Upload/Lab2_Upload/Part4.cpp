#include <iostream>
using namespace std;

//Karl Burke

/***************************************************************************************

*    Usage: Modified
*    Title: Quicksort
*    Author: Unknown
*    Date: 06/02/2017
*    Code version: Unknown
*    Availability: http://www.algolist.net/Algorithms/Sorting/Quicksort
*
***************************************************************************************/

template<typename T> T* quickSort(T* array1, int start, int finish)
{
	T left = start;
	T piviot = array1[((start + finish)/2)];
	T right = finish;
	
	while (left <= right)
	{
		while (array1[left] < piviot)
		{
			left++;
		}
		while (array1[right] > piviot)
		{
			right--;
		}

		if (left <= right)
		{
			swapNums(array1[left], array1[right]);			

			left++;
			right--;
		}		
	}

	if (start < right)
	{
		quickSort(array1, start, right);
	}

	if (left < finish)
	{
		quickSort(array1, left, finish);
	}	

	return array1;
}

template<typename T>void swapNums(T &num1, T &num2)
{
	T temp = num1;
	num1 = num2;
	num2 = temp;

}

int main()
{
	const int size = 10;
	int nums[size] = {5,2,0,4,10,10,3,9,8,1 };
	int *ptr = nums;

	for (int i = 0; i < size; i++)
	{
		cout << "Position " << i << " "
			<< nums[i] << endl;
	}

	cout << endl << endl;

	quickSort(ptr, 0, 9);

	for (int i = 0; i < size; i++)
	{
		cout << "Position " << i << " "
			<< nums[i] << endl;
	}

	system("PAUSE");
	
	return 0;
}