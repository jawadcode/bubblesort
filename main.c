#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void input_arr(int size, int *arr)
{
	for (int i = 0; i < size; i++)
	{
		char numstr[9];
		printf("Enter the number at index: %u\n", i);
		scanf("%s", numstr);
		arr[i] = atoi(numstr);
	}
	printf("\n");
}

void populate(int size, int *arr)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % size;
	}
}

void print_array(int size, int *arr)
{
	for (int i = 0; i < size; i++)
	{
		printf("[%u]: %u", i, arr[i]);
		if (i != size - 1)
			printf(", ");
	}
	printf("\n\n");
}

void array_swap(int size, int *arr, int a, int b)
{
	if (a >= size || b >= size)
		return;
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void bubble_sort(int size, int *arr)
{
	bool sorted = false;
	for (int i = 0; i < (size - 1) && !sorted; i++)
	{
		int count = 0;
		for (int j = 1; j < (size - i); j++)
		{
			if (arr[j - 1] > arr[j])
				array_swap(size, arr, j - 1, j);
			else
				count++;
		}
		if (count == size - 1)
			sorted = true;
	}
}

int main(int argc, char const *argv[])
{
	char lenstr[9];
	int len;
	char custom;
	char writefile;
	// FILE *fp = fopen("results.txt", "ab+");

	srand(time(NULL));
	printf("This program is an implementation of the bubble sort algorithm in C\n");
	printf("You can either enter a custom array or generate an array of random numbers and the program will sort them\n\n");

	printf("How long would you like the array to be?\n");
	fgets(lenstr, 9, stdin);
	len = atoi(lenstr);
	int arr[len];

	printf("Would you like to enter a custom array? (y/n) ");
	custom = getchar();
	if (custom == 'y' || custom == 'Y' || custom == '1')
		input_arr(len, arr);
	else
		populate(len, arr);

	printf("Original array:\n");
	print_array(len, arr);

	bubble_sort(len, arr);
	printf("Sorted array:\n");
	print_array(len, arr);
	return 0;
}
