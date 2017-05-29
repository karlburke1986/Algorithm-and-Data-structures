#include "stdafx.h"
#include <iostream>

using namespace std;

//Karl Burke

void merge(int arr[], int startIndex, int LengthTosort);

void mergeSort(int arrayToSort[], int startIndex, int LengthTosort);

int main()
{
	int array1[10] = { 9, 1, 0, 3, 2 , 7, 8, 5, 6, 4 };
	int *ptr = array1;
		
	mergeSort(array1, 0, 9);

	for (int i = 0; i <= 9; i++)
	{
		cout << array1[i] << endl;
	}
	
	system("PAUSE");

    return 0;
}

void merge(int arr[], int startIndex, int LengthTosort)
{
	int mid = ((startIndex + LengthTosort) / 2);
	int left = mid - startIndex + 1;
	int right = LengthTosort - mid;

	int leftArr[10]; 
	int rightArr[10];


	for (int i = 0; i < left; i++)
		leftArr[i] = arr[startIndex + i];
	for (int j = 0; j < right; j++)
		rightArr[j] = arr[mid + 1 + j];

	
	int i = 0; 
	int j = 0; 
	int k = startIndex; 
	while (i < left && j < right)
	{
		if (leftArr[i] <= rightArr[j])
		{
			arr[k] = leftArr[i];
			i++;
		}
		else
		{
			arr[k] = rightArr[j];
			j++;
		}
		k++;
	}

	while (i < left)
	{
		arr[k] = leftArr[i];
		i++;
		k++;
	}

	while (j < right)
	{
		arr[k] = rightArr[j];
		j++;
		k++;
	}
}

void mergeSort(int arrayToSort[], int startIndex, int LengthTosort)
{
	if (startIndex < LengthTosort)
	{
		int mid = (startIndex + (LengthTosort - startIndex) / 2);

		mergeSort(arrayToSort, startIndex, mid);
		mergeSort(arrayToSort, mid + 1, LengthTosort);

		merge(arrayToSort, startIndex, LengthTosort);
	}
	else
	{
		return;
	}
}