#include "Sort.h"
#include <stdio.h>
#include "Triangle.h"
#include "Point.h"

//TODO do these need to be part of a class?
void Sort::swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int Sort::partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void Sort::quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

//	int n = sizeof(arr) / sizeof(arr[0]);
//	quickSort(arr, 0, n - 1);