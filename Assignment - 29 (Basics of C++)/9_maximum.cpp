//Write a C++ program to find the maximum of two numbers.

#include<iostream>
using namespace std;
int main()
{
    int x,y;
    cout<<"Enter two numbers : ";
    cin>>x>>y;
    if(x>y)
        cout<<x<<" is maximum.";
    else
        cout<<y<<" is maximum.";
    return 0;
}