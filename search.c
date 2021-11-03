#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

int min(int x, int y)
{
	return (x < y) ? x : y;
}

int linearSearch(int* arr, int n, int val)
{
	bool found = false;
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		if (arr[i] == val)
		{
			found = true;
			break;
		}
	}

	if (found)
	{
		return i;
	}
	else
	{
		return - 1;	// key not found
	}
}

int binarySearch(int* arr, int n, int val)
{
	// l, r, m stand for left, right and middle, respectively
	int l = 0;
	int r = n - 1;
	int m = -1;
	while (l <= r)
	{
		m = floor((l + r) / 2);
		if (val < arr[m])
		{
			r = m - 1;
		}
		else if (val > arr[m])
		{
			l = m + 1;
		}
		else
		{
			return m;
		}
	}
	return -1;	// key not found
}

int jumpSearch(int* arr, int n, int val)
{
	int a = 0;
	int b = floor(sqrt(n));
	while (arr[min(b, n) - 1] < val)
	{
		a = b;
		b += floor(sqrt(n));
		if (a >= n)
		{
			return -1;	// key not found
		}
	}

	while (arr[a] < val)
	{
		a += 1;
		if (a == min(b, n))
		{
			return -1;	// key not found
		}
	}

	if (arr[a] == val)
	{
		return a;
	}
	else
	{
		return -1;	// key not found
	}

}

int main(int argc, char const *argv[])
{
	int algorithmID = atoi(argv[1]);
	int n = atoi(argv[2]);
	int val = atoi(argv[3]);
	int* arr = malloc(n * sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		arr[i] = i;
	}
	double elapsedTime = -1.0;
	int keyIndex = -1;

	switch (algorithmID)
	{
		case 1:	// linear search
		{
			clock_t start = clock();
			keyIndex = linearSearch(arr, n, val);
			clock_t end = clock();
			elapsedTime = (double)(end - start) / CLOCKS_PER_SEC;
			break;
		}
		case 2:	// binary search
		{
			clock_t start = clock();
			keyIndex = binarySearch(arr, n, val);
			clock_t end = clock();
			elapsedTime = (double)(end - start) / CLOCKS_PER_SEC;
			break;
		}
		case 3:	// jump search
		{
			clock_t start = clock();
			keyIndex = jumpSearch(arr, n, val);
			clock_t end = clock();
			elapsedTime = (double)(end - start) / CLOCKS_PER_SEC;
			break;
		}
	}

	if (keyIndex == -1)
	{
		printf("Key not found.\n");
	}
	else
	{
		printf("Key found in index %d in %f seconds.\n", keyIndex, elapsedTime);	
	}
	
	return 0;
}