#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_random(int array[], int length, int max);

int main(void)
{
  // seed the random number generator with a different value (the current time)
  // each time the program runs to ensure we get different random numbers each
  // time the program runs
  srand( time(NULL) );

  // create an int array of length 100
  int a=10000000;
  intptr;

  ptr = (int *)calloc(a, sizeof(int));
  // fill the array a with random integers between 1-200
  fill_random(ptr, 10000001, 20000000);

  // output the numbers in the array to verify correctness




  printf("a[%d]\n", ptr[a]);
  system("pause");
  return 0;
}

// fills the array of the given length with random integers between 1 - max
void fill_random(int array[], int length, int max)
{
  // loop through each index of the array... rand() % max will produce a 
  // random number between 0 - (max-1), adding 1 will shift it to 1 - max
  for (int i = 0; i < length; i++)
    array[i] = (rand() % max) + 1;
}