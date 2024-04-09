//LAB ASSIGNMENT2
//Write a C++ program that illustrates the concept of Function over loading
#include <iostream>
using namespace std;
int add(int x, int y) // first definition
{
    cout<< x+y << endl;
    return 0;
}
float add(float a, float b)
{
    cout << a+b << endl;
    return 0;
}
double add(double x, double y)
{
    cout << x+y << endl;
    return 0;
}

int main()
{
    add(20, 40);
    add(23.45f, 34.5f);
    add(40.24, 20.433);
}