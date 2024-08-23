/*
1. Define a class Person with name and age as instance variables. Provide parameterised constructor with two formal arguments name & age,
   to initialise Instance variables.
2. Define a class Complex with instance variables a and b to store real and imaginary part of a complex number. 
   Provide setData() method with formal arguments with the name a and b, to set the values of instance variables. 
   Also define showData() method to display instance member variable values.
3. In question-2, write a non member function in which instantiate Complex class dynamically. Initialise instance variables and 
   display their values.
4. Define a class Time with instance variables hr, min and sec. Provide instance methods setTime() and showTime().
   setTime() method has formal arguments with the same name as instance variables. Also define setters and getters.
5. In question-4, define a method to dynamically create an array of Time objects with specified size (received through argument) and return array.
6. In question-4, define a method to sort Time object array.
7. In question-4, define a method to display Time object array values. Array is received through argument.
8. Define a class String with char pointer and length of the string as instance member variables. Define a method to dynamically 
   create an array of char type and hold the input string in such a way that the array length is just enough to accommodate the input string.
9. In question-8, define methods to convert string into uppercase, lowercase.
10. In question-8, define methods to print string, return string, return length of string.
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;

class Person
{
    private:
        string name;
        int age;
    public:
        Person(string n,int a):name(n),age(a)
        {}  
};
class Complex
{
    private:
        int a,b;
    public:
        void setData(int a,int b)
        {
            this->a=a;
            this->b=b;
        }
        void showData()
        {
            cout<<"a="<<a<<"    b="<<b<<endl;
        }
};
void DynComplex()
{
    Complex *ptr;
    ptr=new Complex;
    ptr->setData(10,20);
    ptr->showData();
}
class Time 
{
    private:
        int hr,min,sec;
    public:
        void setTime(int hr,int min,int sec)
        {
            this->hr=hr;
            this->min=min;
            this->sec=sec;
        }
        void showTime()
        {
            cout<<hr<<":"<<min<<":"<<sec<<endl;
        }
        void setHour(int hr){this->hr=hr;}
        void setMin(int min){this->min=min;}
        void setSec(int sec){this->sec=sec;}
        int getHour(){return hr;}
        int getMin(){return min;}
        int getSec(){return sec;}
        bool operator<(Time t)
        {
            if(hr<t.hr)
                return true;
            else if(hr>t.hr)
                return false;
            else if(min<t.min)
                return true;
            else if(min>t.min)
                return false;
            else if(sec<t.sec)
                return true;
            else    
                return false;
        }
};
Time* createTimeArray(int size)
{
    return new Time[size];
}
void sort(Time T[],int size)
{
    Time temp;
    int i,r;
    for(r=1;r<=size-1;r++)
    {
        for(i=0;i<=size-1-r;i++)
        {
            if(T[i+1]<T[i])
            {
                temp=T[i];
                T[i]=T[i+1];
                T[i+1]=temp;
            }
        }
    }
}
void printTimeArray(Time T[],int size)
{
    for(int i=0;i<=size-1;i++)
        T[i].showTime();
}
class String
{
    private:
        char *s;
        int length;
    protected:
        int len(char str[])
        {
            int l,i;
            for(i=0;str[l];i++);
            return i;
        }
        char* inputString()
        {
            char ch,*p=NULL,*q=NULL;
            int i,size=1;
            printf("Enter text : ");
            p=new char[size];
            p[0]='\0';
            while(1)
            {
                ch=getchar();
                if(ch=='\n')
                    break;
                q=new char[size+1];
                for(i=0;i<size;i++)
                    q[i]=p[i];
                q[i-1]=ch;
                q[i]='\0';
                free(p);
                size++;
                p=new char[size];
                strcpy(p,q);
                free(q);
            }
            return p;
        }
    public:
        String()
        {
            s=NULL;
            length=0;
        }
        void setString()
        {
            if(s!=NULL)
            {
                delete s;
                length=0;
            }
            s=inputString();
            length=len(s);
        }
        void setString(char arr[])
        {
            if(s!=NULL)
            {
                delete s;
                length=0;
            }
            strcpy(s,arr);
            length=len(arr);
        }
        void upper()
        {
            for(int i=0;i<length;i++)
            {
                if(s[i]>='a'&&s[i]<='z')
                    s[i]-=32;
            }
        }
        void lower()
        {
            for(int i=0;i<length;i++)
            {
                if(s[i]>='A'&&s[i]<='Z')
                    s[i]+=32;
            }
        }
        ~String()
        {
            delete []s;
        }
        int stringLength()
        {
            return length;
        }
        void printString()
        {
            cout<<s;
        }
        char* getString()
        {
            return s;
        }
};
