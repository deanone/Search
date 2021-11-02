#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int main(int argc, char const *argv[])
{
	int n = atoi(argv[1]);
	int val = atoi(argv[2]);
	int* arr = malloc(n * sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		arr[i] = i;
	}

	int keyIndex = binarySearch(arr, n, val);
	if (keyIndex == -1)
	{
		printf("Key not found.\n");
	}
	else
	{
		printf("Key found in index %d.\n", keyIndex);	
	}
	
	return 0;
}