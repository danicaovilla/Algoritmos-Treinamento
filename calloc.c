#include <stdio.h>
#include <stdlib.h>
#define DIM 100000000000
int main()
{

    // This pointer will hold the
    // base address of the block created
    int *ptr;
    int n, equal, j, i = 0;

    // Get the number of elements for the array
    n = 1000000;
    printf("Enter number of elements: %d\n", n);

    // Dynamically allocate memory using calloc()
    ptr = (int *)calloc(n, sizeof(int));

    // Check if the memory has been successfully
    // allocated by calloc or not
    if (ptr == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else
    {

        // Memory has been successfully allocated
        printf("Memory successfully allocated using calloc.\n");

        do
        {
            ptr[i] = rand() % 1000000;
            equal = 0;
            
            for (j = 0; j < i; j++)
            {
                if (ptr[j] == ptr[i])
                    equal = 1;
            }
         if (equal == 0)
                i++;
        }while (i < n);
                
            for (i = 0; i < n; i++)
            {
                printf("%d, ", ptr[i]);
            }

            return 0;
    }
}