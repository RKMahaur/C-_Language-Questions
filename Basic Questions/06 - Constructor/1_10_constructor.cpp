//1. Define a class Cuboid with length, breadth and height as instance member variables. Define constructors to initialise member variables.
//2. Define a class Customer with instance members cust_id, name, email, mobile. Define non parameterised constructor and parameterised 
//   constructor in the class.
//3. Define a class Time with hr, min, sec as instance member variables. Define constructor to initialise time object.
//4. Define a class Book with booked, title and price as instance member variables. Define non parameterised and parameterised constructor
//   in the class.
//5. Define a class Complex with instance variables for real and imaginary part of a complex number. Define only one parameterised constructor 
//  in the class to initialise complex object. Also define showData method in the class to display object data. Now create an array of 
//   Complex class with size 5 and display values of each object.
//6. Define a class Numbers with size and arr pointer as instance variables. Provide constructor to initialise instance members,
//   dynamically allocate an array of given size and store address in arr variable of object. Also define destructor to deallocate memory of 
//   array. Implement deep copy using copy constructor to avoid memory issues.
//7. Define a class student and write a program to enter student details using constructor and define member function to display all the details.
//8. Define a class Date with d,m,y as instance variables. Initialise members using initilisers.
//9. Define a class Room for a hotel management project with room number, room type, is_AC, price as instance variables. Initialise instance
//   variables using constructor.
//10. Define Circle class with radius as instance variables. Define two constructors in the class non parameterised and parameterised.  

#include<iostream>
using namespace std;
class Cuboid
{
    private:
        int length,breadth,height;
    public:
        Cuboid(int l,int b,int h):length(l),breadth(b),height(h)
        {}
};
class Customer
{
    private:
        int cust_id;
        string name,email,mobile;
    public: 
        Customer()
        {
            cust_id=0;
            name="Anonymous";
            email="xyz@email.com";
            mobile="9998887776";
        }
        Customer(int id,string n,string e,string m):cust_id(id),name(n),email(e),mobile(m)
        {}
};
class Time 
{
    private:
        int hr,min,sec;
    public:
        Time(int h,int m,int s):hr(h),min(m),sec(s)
        {}
};
class Book
{
    private:
        int book_id;
        string title;
        float price;
    public:
        Book()
        {
            book_id=0;
            title="abc";
            price=0.0;
        }
        Book(int id,string t,float p):book_id(id),title(t),price(p)
        {}
};
class Complex
{
    private:
        int real,imag;
    public:
        Complex(int r,int i):real(r),imag(i)
        {}
        void showData()
        {
            cout<<"Real="<<real<<"  Imaginary="<<imag<<endl;
        }
};
void example()
{
    Complex c[5]={Complex(4,6),
                  Complex(10,20),
                  Complex(5,2),
                  Complex(2,3),
                  Complex(6,8)};
    for(int i=0;i<=4;i++)
        c[i].showData();
}
class Number
{
    private:
        int size;
        int *arr;
    public:
        Number(int s)
        {
            size=s;
            arr=new int[size];
        }
        Number(Number &N)
        {
            size=N.size;
            arr=new int[size];
            for(int i=0;i<=size;i++)
                arr[i]=N.arr[i];
        }
        ~Number()
        {
            delete arr;
        }
};
class student
{
    private:
        int rollno;
        string name;
    public:
        student()
        {
            cout<<"Enter Roll No: ";
            cin>>rollno;
            cout<<"Enter name: ";
            cin>>name;
        }
        void showstudent()
        {
            cout<<endl<<rollno<<"  "<<name;
        }
};
class Date
{
    private:
        int d,m,y;
    public: 
        Date(int d,int m,int y):d(d),m(m),y(y)
        {}
};
class Room 
{
    private:
        int roomNo;
        string roomType;
        bool is_AC;
        float price;
    public: 
        Room(int rNo,string rT,bool AC,float p):roomNo(rNo),roomType(rT),is_AC(AC),price(p)
        {}
};
class Circle
{
    private:
        int radius;
    public:
        Circle()
        {
            radius=1;
        }
        Circle(int r):radius(r)
        {}
};
int main()
{
    example();
    return 0;
}