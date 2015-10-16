package multij;

public class Main
{
    public static void main(String[] args)
    {
        //  Array 3 Dimensions
        int x = 4, y = 5, z = 6;

        //  Array Iterators
        int i, j, k;

        //  Allocate 3D Array
        int[][][] array3D = new int[x][y][z];

        //  Access array elements
        for (i = 0; i < x; i++)
        {
            System.out.println(i);

            for (j = 0; j < y; j++)
            {
                System.out.println();

                for (k = 0; k < z; k++)
                {
                    array3D[i][j][k] = (i * y * z) + (j * z) + k;
                    System.out.print("\t" + array3D[i][j][k]);
                }
            }

            System.out.println('\n');
        }
    }
}
