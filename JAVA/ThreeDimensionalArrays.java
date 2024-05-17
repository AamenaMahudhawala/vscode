class ThreeDimensionalArrays
{
    public static void main(String args[])
    {
        int i,j,k;
        int my3darray [][][] = new int [3][4][5];
        for(i=0;i<my3darray.length;i++)
        {
            for(j=0;j<my3darray[i].length;j++)
            {
                for(k=0;k<my3darray[i][j].length;k++)
                {
                    my3darray[i][j][k] = i*j*k;
                    System.out.print(my3darray[i][j][k]+" ");
                }
                System.out.println(); 
            }
            System.out.println(); 
        }
    }
}