#include <stdio.h>
#include <stdlib.h>

void main()
{
    //  Array 3 Dimensions
    int x = 4, y = 5, z = 6;

    //  Array Iterators
    int i, j, k;

    //  Allocate 3D Array
    int *allElements = malloc(x * y * z * sizeof(int));
    int ***array3D = malloc(x * sizeof(int **));
    
    for(i = 0; i < x; i++)
    {
        array3D[i] = malloc(y * sizeof(int *));

        for(j = 0; j < y; j++)
        {
            array3D[i][j] = allElements + (i * y * z) + (j * z);
        }
    }
    
    //  Access array elements
    for(i = 0; i < x; i++)
    {
        printf("%d\n", i);

        for(j = 0; j < y; j++)
        {
            printf("\n");

            for(k = 0; k < z; k++)
            {
                array3D[i][j][k] = (i * y * z) + (j * z) + k;
                printf("\t%d", array3D[i][j][k]);
            }
        }

        printf("\n\n");
    }

    //  Deallocate 3D array
    free(allElements);
    for(i = 0; i < x; i++)
    {
        free(array3D[i]);
    }
    free (array3D);
}