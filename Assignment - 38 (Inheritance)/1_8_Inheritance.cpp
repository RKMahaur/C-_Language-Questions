/*
1. Define a class Person with name and age as instance variables as private members. Provide setters and getters as protected methods. 
   Derive a class Employee from Person class with private instance variable salary. Provide public methods setEmployee() and showEmployee().
2. Define a class Circle with radius as private instance variable and setRadius(), getRadius(), getArea() as public instance methods.
   Define a class ThickCircle as a subclass of Circle with thickness as private instance variable and get Thickness(),
   set Thickness() as public instance methods. Provide an overridden method getArea() to calculate area of thick portion of circle.
3. Define a class Coordinate with x and y as instance variables. Define overloaded versions of getDistance(), first with no argument
   calculating distance from origin, and second with one argument of Coordinate type to calculate distance between two coordinates. 
   Also define other methods if required.
4. Define a class Shape with shapeName as instance variable. Provide setter and getter.
5. In question 3 & 4, derive a class StraightLine from Shape with two Coordinate type objects as instance members. 
   Provide methods to setLine(), getDistance() and showLine().
6. Define a class Game with an array of 5 int variables as instance member to store the score of each of 5 rounds. 
   Provide method to setScore(int round, int score). Also provide method getScore(int round).
7. In question 6, derive a class GameResult with an array of 5 int type variables to store the result in each round. 
   Result value is 2 for win, 0 for loose and 1 for draw Provide methods to set Result and getResult. 
   Write method to calculate final result of the game.
8. Define a class Actor with name, age as instance variables and setter, getters as instance methods. 
   Define a class TVActor as a derived class of Actor with instance variable to store number of TV projects done or running and define setter,
   getter. Also define setTVActor() and showTVActor(). Define a class MovieActor as a derived class of Actor with instance variable to store 
   number of movies doe or running and define setter, getter. Also define setMovieActor() and showMovie Actor().
   Derive a class AllScreenActor from TVActor and MovieActor. Define a method to setActorData() and show ActorData().
*/
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;

class Person
{
    private:
        string name;
        int age;
    protected:
        void setName(string N)
        {
            name=N;
        }
        void setAge(int a)
        {
            age=a;
        }
        string getName()
        {
            return name;
        }
        int getAge()
        {
            return age;
        }
};
class Employee:public Person
{
    private:
        double salary;
    public:
        void setEmployee(string n,int a,double s)
        {
            setName(n);
            setAge(a);
            salary=s;
        }
        void showEmployee()
        {
            cout<<"Name: "<<getName();
            cout<<"Age: "<<getAge();
            cout<<"Salary: "<<salary;
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
        float getArea()
        {
            return 3.14*radius*radius;
        }
};
class ThickCircle:public Circle
{
    private:
        float thickness;
    public:
        void setThickness(float t)
        {
            thickness=t;
        }
        float getThickness()
        {
            return thickness;
        }
        float getArea()
        {
            float r1,r2;
            r1=getRadius()+thickness;
            r2=getRadius();
            return 3.14*(r1*r1-r2*r2);
        }
};
class Coordinate
{
    private: 
        int x,y;
    public:
        void setCoordinate(int x,int y)
        {
            this->x=x;
            this->y=y;
        }
        int getX()
        {
            return x;
        }
        int getY()
        {
            return y;
        }
        float getDistance()
        {
            return sqrt(x*x+y*y);
        }
        float getDistance(Coordinate C)
        {
            return sqrt((x-C.x)*(x-C.x)+(y-C.y)*(y-C.y));
        }
        void showCoordinate()
        {
            cout<<"("<<x<<","<<y<<")";
        }
};
class Shape
{
    private:
        string shapeName;
    public:
        void setShapeName(string name)
        {
            shapeName=name;
        }
        string getShapeName()
        {
            return shapeName;
        }
};
class Straightline:public Shape
{
    private:
        Coordinate c1,c2;
    public:
        void setLine(Coordinate A,Coordinate B)
        {
            c1=A;
            c2=B;
        }
        float getDistance()
        {
            return c1.getDistance(c2);
        } 
        void showLine()
        {
            c1.showCoordinate();
            c2.showCoordinate();
        }
};
class Game
{
    private:
        int A[5];
    public:
        void setScore(int round,int score)
        {
            A[round]=score;
        }
        int getScore(int round)
        {
            return A[round];
        }
};
class GameResult:public Game
{
    private:
        int result[5];
    public:
        void setResult(int round, int r)
        {
            result[round]=r;
        }
        int getResult(int round)
        {
            return result[round];
        }
        int getFinalResult()
        {
            int s=0;
            for(int i=0;i<5;i++)
                s=s+result[i];
            return s;
        }
};
class Actor
{
    private:
        string name;
        int age;
    public:
        void setName(string n)
        {
            name=n;
        }
        void setAge(int a)
        {
            age=a;
        }
        string getName()
        {
            return name;
        }
        int getAge()
        {
            return age;
        }
};
class TVActor:virtual public Actor
{
    private:
        int tv_projects_count;
    public:
        void setTvProjectsCount(int c)
        {
            tv_projects_count=c;
        }
        int getTvProjectsCount()
        {
            return tv_projects_count;
        }
        void setTvActor(string n,int a,int projects)
        {
            setName(n);
            setAge(a);
            setTvProjectsCount(projects);
        }
        void showTvActor()
        {
            cout<<endl;
            cout<<getName()<<endl;
            cout<<getAge()<<endl;
            cout<<getTvProjectsCount()<<endl;
        }
};
class MovieActor:virtual public Actor
{
    private:
        int movieCount;
    public:
        void setMovieCount(int m)
        {
            movieCount=m;
        }
        int getMovieCount()
        {
            return movieCount;
        }
        void setMovieActor(string n,int a,int movie)
        {
            setName(n);
            setAge(a);
            setMovieCount(movie);
        }
        void showMovieActor()
        {
            cout<<endl;
            cout<<getName()<<endl;
            cout<<getAge()<<endl;
            cout<<getMovieCount();
        }
};
class AllScreenActor:public TVActor,public MovieActor
{
    public:
        void setActorData(string n,int a,int tc,int mc)
        {
            setName(n);
            setAge(a);
            setTvProjectsCount(tc);
            setMovieCount(mc);
        }
        void showActorData()
        {
            cout<<endl;
            cout<<getName()<<endl;
            cout<<getAge()<<endl;
            cout<<getTvProjectsCount()<<endl;
            cout<<getMovieCount();
        }
};
