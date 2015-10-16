#include <iostream>

using namespace std;

void main()
{
    //  Array 3 Dimensions
    int x = 4, y = 5, z = 6;

    //  Array Iterators
    int i, j, k;

    //  Allocate 3D Array
    int ***array3D = new int**[x];
    
    for(i = 0; i < x; i++)
    {
        array3D[i] = new int*[y];

        for(j = 0; j < y; j++)
        {
            array3D[i][j] = new int[z];
        }
    }
    
    //  Access array elements
    for(i = 0; i < x; i++)
    {
        cout << i << endl;

        for(j = 0; j < y; j++)
        {
            cout << endl;

            for(k = 0; k < z; k++)
            {
                array3D[i][j][k] = (i * y * z) + (j * z) + k;
                cout << '\t' << array3D[i][j][k];
            }
        }

        cout << endl << endl;
    }

    //  Deallocate 3D array
    for(i = 0; i < x; i++)
    {
        for(j = 0; j < y; j++)
        {
            delete[] array3D[i][j];
        }

        delete[] array3D[i];
    }
    delete[] array3D;
}