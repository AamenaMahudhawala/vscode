#include <stdio.h>

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

}
void printarray(int array[],int n)
{
    int i;
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}



void quick_sort(int array[],int pivot,int p,int q,int n)
{
   
    if(p>n)
    return;
    while (array[q]>array[pivot])
    {
        q--;
    }
    while (array[p]<array[pivot]&&p<=n)
    {
        p++;
    }
    if(q==pivot)
    return;
    if(p<q)
    {
    swap(&array[p],&array[q]);
    quick_sort(array,pivot,p,q,n);
    
    }
    else if(p>q)
    {
        swap(&array[pivot],&array[q]);
        
        quick_sort(array,pivot,pivot+1,q-1,q);
        quick_sort(array,q+1,q+2,n-1,n);
        
    }
    else
    return;
    
    
}

int main()
{
    int array[7]={4,2,6,1,7,3,5};
    printarray(array,7);
    quick_sort(array,0,1,6,7);
    printarray(array,7);
   
}