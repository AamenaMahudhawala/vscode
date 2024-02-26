//Static Data Members
#include<iostream>
using namespace std;


class Product
{
    public:
    static int count; 
    
    float price=45;
    public:Product()
    {
        count++;
    }
    public:~Product() //destructor
    {
        printf("\nProduct discontinued.");
        
        
    }
    
      

};
int Product::count = 0; //initializing count as 0
int main()
{
    Product P1,P2;
    
    cout<<P1.count<<endl;
    return 0;
}