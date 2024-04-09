//LAB ASSIGNMENT1
//Write a program in C++ to sort the numbers in an array using separate functions for read, display, sort and swap.
#include<iostream>
using namespace std;

int array[50];
int n;
void read_array()
{
    cout<<"\nEnter number of elements: ";
    cin>>n;
    cout<<"\nEnter elements:";
    for (int i=0;i<n;i++)
    {
        cin>>array[i];
    }
}
void display_array()
{
    
    for (int i=0;i<n;i++)
    {
        cout<<array[i]<<" ";
    }

}
void swap(int &x,int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void Bubble_sort()
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if (array[j]>array[j+1])
            {
                swap(array[j],array[j+1]);
            }
            
        }
        
        
    }
}
void Selection_sort()
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i+1; j < n; j++)
        {
            if (array[j] < array[min])
            {
            min = j;
            }
        }
        swap(array[min],array[i]);
        display_array();
    }

}
void Insertion_sort()
{
    int i,k,j;
    for(i=1;i<n;i++)
    {
        for(j=0;j<=i-1;j++)
        {
            
            if(array[j]>array[i])
            {
                for(k=i;k>0;k--)
                {
                    swap(array[k],array[k-1]);
                }               

            }
            
        }
        
               
    }
}

int main()
{
    int g;
    
    read_array();
    cout<<"\nYour Array is:";
    display_array();
    cout<<"\n1:Bubble sort\n2:Insertion sort\n3:Selection sort\nEnter your choice: "<<endl;
    scanf("%d",&g);
    switch(g)
    {
        case 1:
            Bubble_sort();
            break;
        case 2:
            Insertion_sort();
            break;
        case 3:
            Selection_sort();
            break;
        default:
            printf("Wrong choice entered\n");
            break;
    }
    cout<<"Sorted Array is:";
    display_array();      
    
    cout<<endl;
    
    return 0;
}