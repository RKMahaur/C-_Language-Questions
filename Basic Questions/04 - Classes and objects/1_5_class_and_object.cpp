//1. Define a class Complex to represent a complex number. Declare instance member variables to store real and imaginary part of a complex
//   number, also define instance member functions to set values of complex number and print values of complex number.
//2. Define a class Time to represent Time (like 3 hr 45 min 20 sec). Declare appropriate number of instance member variables and also define
//   instance member functions to set value for time and display values of time.
//3. Define a class Date to represent date (like d=31, m=12, y=2022). Declare appropriate number of instance member variables and also define 
//   instance member functions to set date and get date.
//4. In question 3, define a methods to display date in the following pattern
//   a) 31-12-2022
//   b) 31-Dec-2022
//5. Define a class Circle with radius as its property. Provide setRadius() and getRadius() methods. Also define methods to return area and
//   circumference of circle.

#include<iostream>
using namespace std;
class Complex
{
    private: 
        int real,imag;
    public:
        void setComplex(int a,int b)
        {
            real=a;
            imag=b;
        }
        void showComplex()
        {
            cout<<"real = "<<real<<" and imaginary = "<<imag<<endl;
        }
};
class Time
{
    private:
        int hr,min,sec;
    public: 
        void setTime(int h,int m,int s)
        {
            hr=h;
            min=m;
            sec=s;
        }
        void showTime()
        {
            cout<<"Hour="<<hr<<", Minute="<<min<<", Second="<<sec<<endl;
        }
};
class Date 
{
    private:
        int date,month,year;
    public: 
        void setDate(int d,int m,int y)
        {
            date=d;
            month=m;
            year=y;
        }
        void showDate()
        {
            cout<<date<<"/"<<month<<"/"<<year<<endl;
        }
        void showDateFormat1()
        {
            cout<<date<<"-"<<month<<"-"<<year<<endl;
        }
        void showDateFormat2()
        {
            char *months[]={"Jan",
                            "Feb",
                            "Mar",
                            "Apr",
                            "May",
                            "Jun",
                            "Jul",
                            "Aug",
                            "Sep",
                            "Oct",
                            "Nov",
                            "Dec"};
            cout<<date<<"-"<<months[month-1]<<"-"<<year<<endl;
        }
};
class Circle
{
    private:
        int radius;
    public:
        void setRadius(int r)
        {
            radius=r;
        }
        int getRadius()
        {
            return radius;
        }
        float getarea()
        {
            return 3.14*radius*radius;
        }
        float getcircumference()
        {
            return 2*3.14*radius;
        }
};