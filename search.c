#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binarySearch(int* A, int N, int key)
{
	int L = 0;
	int R = N - 1;
	while (L <= R)
	{
		int m = floor((L + R) / 2);
		if (key < A[m])
		{
			R = m - 1;
		}
		else if (key > A[m])
		{
			L = m + 1;
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
	int N = atoi(argv[1]);
	int key = atoi(argv[2]);
	int* A = malloc(N * sizeof(int));
	for (int i = 0; i < N; ++i)
	{
		A[i] = i;
	}

	int keyIndex = binarySearch(A, N, key);
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