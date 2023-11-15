#include<stdio.h>
#include<stdlib.h>

int *p;
void createArr(int n)
{
    int i;
    
    p = (int*)malloc(n*sizeof(int));
    printf("\nEnter:\n");
    for (i = 0; i<n; i++)
    {
        scanf("%d",&p[i]);
    }
    
}

void printArr(int n)
{
    int i;
    printf("\nYour Array is: ");
    for (i = 0; i<n; i++)
    {
        printf("%d ",p[i]);
    }

}

int main()
{
    
    
    int n;
    printf("Enter Size of Array: ");
    scanf("%d",&n);
    createArr(n);
    printArr(n);
    free(p);
    printf("\nThank You.\n");
    return 0;
}