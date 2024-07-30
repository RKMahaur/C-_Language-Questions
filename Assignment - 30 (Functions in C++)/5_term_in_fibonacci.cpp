//Define a function to check whether a given number is a term in a fibonacci series or not.

#include<iostream>
using namespace std;
bool in_fibonacci(int);

bool in_fibonacci(int x)
{
    int a=-1,b=1,c=0;
    while(c<x)
    {
        c=a+b;
        if(c==x)
            return true;
        a=b;
        b=c;
    }
    return false;
}
int main()
{
    int a;
    cout<<"Enter the number to check in fibonacci series : ";
    cin>>a;
    if(in_fibonacci(a))
        cout<<a<<" is present in fibonacci series.";
    else
        cout<<a<<" is not present in fibonacci series.";
    return 0;
}