//Write a C++ program to add all the numbers of an array of size 10.

#include<iostream>
using namespace std;
int main()
{
    int x[10],i,sum=0;
    cout<<"Enter 10 values for an array : ";
    for(i=0;i<10;i++)
    cin>>x[i];
    
    for(i=0;i<10;i++)
    sum=sum+x[i];
    cout<<"Sum of all numbers in array is "<<sum;
    return 0;
}