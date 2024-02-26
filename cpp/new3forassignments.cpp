#include<iostream>
using namespace std;

class NewClass
{

    public: int a,b;

    private: int private_sum()
    {
        return a+b+5;
    }

    public: void display_sum()
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