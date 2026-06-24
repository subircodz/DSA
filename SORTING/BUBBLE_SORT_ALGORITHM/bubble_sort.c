#include <stdio.h>

// https://www.youtube.com/watch?v=kE1aGcfxEzE&t=368s

void print(int *arr, int size);
void bubble(int *arr, int size);

int main()
{
	int arr[] = {5, 7, 2, 3, 1}; // if 20bytes, 4bytes, 20/4 = 5
	int size;
	size = sizeof(arr) / sizeof(arr[0]);
	printf("Before sorting: ");
	print(arr, size);
	bubble(arr, size);
	printf("\nAfter sorting: ");
	print(arr, size);
	return 0;
}

void bubble(int *arr, int size)
{
	int temp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

// this function will only be used for printing the elements of the array
void print(int *arr, int size)
{
	printf("\n");
	for (int i = 0; i < size; i++)
	{
		printf("   %d  ", arr[i]);
	}
}
