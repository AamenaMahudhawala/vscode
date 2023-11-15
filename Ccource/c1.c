#include<stdio.h>
#include<stdlib.h>


int* createArr(int n)
{
    int i;
    int *p;
    p = (int*)malloc(n*sizeof(int));
    printf("\nEnter:\n");
    for (i = 0; i<n; i++)
    {
        scanf("%d",&p[i]);
    }
    return p;
}

void printArr(int n)
{
    int i;
    int *p;
    printf("\nYour Array is: ");
    for (i = 0; i<n; i++)
    {
        printf("%d ",p[i]);
    }

}

int main()
{
    
    int *p;
    int n;
    printf("Enter Size of Array: ");
    scanf("%d",&n);
    createArr(n);
    printArr(n);
    free(p);
    printf("\nThank You.\n");
    return 0;
}