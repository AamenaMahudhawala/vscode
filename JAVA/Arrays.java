class Arrays
{
    public static void main(String args[]){

        int a[] = {2,4,6,8,7};
        float sum = 0;

        for(int i=0;i<a.length;i++)
        {
            sum+=a[i];

        }
        System.out.println("The average of the elements is: "+(sum/a.length));
    }
}