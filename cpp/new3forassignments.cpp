#include<iostream>
using namespace std;

class NewClass
{

    public: int a,b; //public data members which can be accessed by object

    private: int private_sum() //private member function which objects cannot access
    {
        return a+b+5;
    }

    public: void display_sum()// Nesting of member functions
    {
        cout<<private_sum();
    }

};

int main()
{
    NewClass N1;
    N1.a = 10;
    N1.b = 15;
    N1.display_sum();
}