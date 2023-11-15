#include<stdio.h>
#include<stdlib.h>

void* myRealloc(void* srcblock, unsigned oldsize, unsigned newsize);

int main()
{
    int* n; 
    n = (int*)malloc(3*sizeof(int));
    int* n2 = NULL;
    n[0]=3;
    n[1]=6;
    n[2]=8;
    if (n==NULL)
        return 1;
    
    n2 = (int*)myRealloc(n,3*sizeof(int),4*sizeof(int));

    return 0;
}

void* myRealloc(void* srcblock, unsigned oldsize, unsigned newsize)
{
    int i;
    int actualsize;
    if(oldsize>newsize) actualsize=oldsize;
    if(oldsize<newsize) actualsize=newsize;
    char* newArr=(char*)malloc(newsize);
    if(!newArr) return NULL;
    for (i = 0; i < actualsize; i++)
    {
        newArr[i]=((char*)srcblock)[i];
        free(srcblock);
    }
    return newArr;
    
}