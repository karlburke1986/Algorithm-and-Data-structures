#include <iostream>

using namespace std;

int quickSortDivide(int* theArray, int first, int last);

void quickSort(int* theArray, int first, int last);

void swap1(int &num1, int &num2);

int main()
{
	int nums[10] = { 5,2,0,4,10,10,3,9,8,1 };

	for (int i = 0; i <= 9; i++)
	{
		cout << nums[i] << endl;
	}

	cout << endl;

	quickSort(nums, 0, 9); 

	for (int i = 0; i <= 9; i++)
	{
		cout << nums[i] << endl;
	}

	system("PAUSE");

	return 0;
}

void swap1(int &num1, int &num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

int quickSortDivide(int* theArray, int first, int last)
{	
	int left = first;
	int right = last;
	int piviot = theArray[(first + last) / 2];

	while (left <= right)
	{
		while (theArray[left] < piviot)
		{
			left++;
		}
		while (theArray[right] > piviot)
		{
			right--;
		}
		if (left <= right)
		{
			swap1(theArray[left], theArray[right]);
			left++;
			right--;
		}
	}

	if (first < right) {
		quickSortDivide(theArray, left, right);
	}
	if (left < last) {
		quickSortDivide(theArray, left, last);
	}

	return first;
}

void quickSort(int* theArray, int first, int last)
{
	

	if (first < last)
	{
		int mid = quickSortDivide(theArray, first, last);
		quickSort(theArray, first, last - 1);
		quickSort(theArray, mid + 1, last);

	}

}