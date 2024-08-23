//Write a C++ program to calculate an average of 3 numbers.

#include<iostream>
using namespace std;
int main()
{
    int x,y,z;
    float avg;
    cout<<"Enter three numbers for average : ";
    cin>>x>>y>>z;
    avg=(x+y+z)/3.0;
    cout<<"Average is "<<avg;
    return 0;
}