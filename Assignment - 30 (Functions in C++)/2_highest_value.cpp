//Define a function to find the highest value digit in a given number.

#include<iostream>
using namespace std;
int highest_digit(int);

int highest_digit(int a)
{
    int n=-1;
    while(a)
    {
        if(a%10>n)
            n=a%10;
        a=a/10;
    }
    return n;
}
int main()
{
    int x,y;
    cout<<"Enter the number : ";
    cin>>x;
    y=highest_digit(x);
    cout<<"Highest value digit in "<<x<<" is "<<y;
    return 0;
}