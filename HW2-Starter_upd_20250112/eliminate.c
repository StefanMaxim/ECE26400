/* You MUST modify this file */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  int pos; //position in the array
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
	
  // Note that from here on, you can access elements of the arr with
  // expressions like a[i]
	
  // initialize all elements
  for (int i = 0; i < n; i++)
  {
    arr[i] = i;
  }

  
  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked
  pos = 0;
  for (int i = 0; i < n-1; i++)
  {
    for (int j = 0; j < k-1; j++)
    {
      pos++;
      if(pos >= n)
      {
        pos -= n;
      }
      while(arr[pos] == -1)
      {
        pos++;
        if(pos >= n)
        {
          pos -= n;
        }
      }
    }
    arr[pos] = -1;
    printf("%d\n", pos);
    pos++;
    if (pos >= n) pos -= n;
    while(arr[pos] == -1)
      {
        pos++;
        if(pos >= n)
        {
          pos -= n;
        }
      }
  }
  



  // print the last one
  printf("%d\n", pos);



  // release the memory of the array
  free (arr);
}
#endif
