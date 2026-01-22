/* MODIFY this file */

#include "sort.h"

void ssort(int * arr, int size) {
	
	int i; // index for looping outside
	int j; //index for looping inside
	int extreme_idx; //the index of the extreme element being searched for (can be min or max)
	int temp; //temporary variable for the swap

	for (i = 0; i < size; i++)
	{
		extreme_idx = i;
		for(j = i; j < size; j++)
		{	
			#ifdef ASCENDING
			if (arr[j] < arr[extreme_idx])
			#else
			if (arr[j] > arr[extreme_idx])
			#endif
			{
				extreme_idx = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[extreme_idx];
		arr[extreme_idx] = temp;
	}
}
