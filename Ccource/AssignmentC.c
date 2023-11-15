#include<stdio.h>
#include<stdlib.h>

int* createArray(int n)
{
    int i;
    int *p;
    p = (int*)malloc(n*sizeof(int));

    return p;
}

void initArray(int *p,int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        p[i]=i;
    }
    
}

void displayArray(int *p,int n)
{
    int i;
    
    printf("\nYour Array is: ");
    for (i = 0; i<n; i++)
    {
        printf("%d ",p[i]);
    }

}

int doubleArraySize(int **p,int n)
{
    int *newArr;
    int i;
    newArr = realloc(*p,2*sizeof(int)*n);
    if(newArr==NULL) return -1;

    *p=newArr;
    for (i = 0; i < 2*n; i++)
    {
        (*p)[i] = 0;
    }
    return 2*n;

}

void freeMemory(int *p)
{
    free(p);
}

int main()
{
    int n = 5;
    int *arr;
    arr=createArray(n);
    initArray(arr,n);
    displayArray(arr,n);
    printf("\nSize is: %d",n);
    n = doubleArraySize(&arr,n);
    printf("\nNew Size is: %d",n);
    displayArray(arr,n);
    freeMemory(arr);
    return 0;
}

