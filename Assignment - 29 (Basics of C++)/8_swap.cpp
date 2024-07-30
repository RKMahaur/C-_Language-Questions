//Write a C++ program to swap values of two int variables without using third variable.

#include<iostream>
using namespace std;
int main()
{
    int x,y;
    cout<<"Enter value of x and y for swapping : ";
    cin>>x>>y;
    x=x+y-(y=x);
    cout<<"Value of x is "<<x<<endl<<"Value of y is "<<y;
    return 0;
}