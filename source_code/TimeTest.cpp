#include <iostream>
#include "Time.h"
using namespace std;

//TIME UNIT TEST-------------------------------------------------
//---------------------------------------------------------------
void TimeTest1();//Unit test Time constructor
void TimeTest2();//Unit test Time constructor initializing value through parameter
void TimeTest3();//Unit test Time, set method for hour
void TimeTest4();//Unit test Time, set method for minute
void TimeTest5();//overloaded < operator test
void TimeTest6();//overloaded > operator test
void TimeTest7();//overloaded == operator test
void TimeTest8();//overloaded != operator test

int main()
{
    TimeTest1();
    TimeTest2();
    TimeTest3();
    TimeTest4();
    TimeTest5();
    TimeTest6();
    TimeTest7();
    TimeTest8();

    return 0;
}

//TIME UNIT TEST-------------------------------------------------
//---------------------------------------------------------------
void TimeTest1()//Unit test Time constructor
{
    cout<<"Time constructor test"<<endl;
    cout<<"Expected result: 00:00"<<endl;
    Time t;
    cout<<t<<endl;
    cout<<endl;
}
void TimeTest2()//Unit test Time constructor initializing value through parameter
{
    cout<<"Time constructor with initializer test"<<endl;
    cout<<"Expected result: 16:58"<<endl;
    Time t(16,58);
    cout<<t<<endl;
    cout<<endl;
}
void TimeTest3()//Unit test Time, set method for hour
{
    cout<<"Time SetHour() test"<<endl;
    cout<<"Expected result: 16:00"<<endl;
    Time t;
    t.SetHour(16);
    cout<<t<<endl;
    cout<<endl;
}
void TimeTest4()//Unit test Time, set method for minute
{
    cout<<"Time SetMinute() test"<<endl;
    cout<<"Expected result: 00:58"<<endl;
    Time t;
    t.SetMinute(58);
    cout<<t<<endl;
    cout<<endl;
}

void TimeTest5()//overloaded > operator test
{
    cout<<"Time overloaded > operator test"<<endl;
    Time t1(10,45);
    Time t2(10,43);

    if(t1>t2)
    {
        cout<<t1<<" is bigger than "<<t2<<endl;
    }
    else
    {
        cout<<t1<<" is smaller than "<<t2<<endl;
    }
    cout<<endl;
}

void TimeTest6()//overloaded < operator test
{
    cout<<"Time overloaded < operator test"<<endl;
    Time t1(10,40);
    Time t2(10,43);

    if(t1<t2)
    {
        cout<<t1<<" is smaller than "<<t2<<endl;
    }
    else
    {
        cout<<t1<<" is bigger than "<<t2<<endl;
    }
    cout<<endl;
}

void TimeTest7()//overloaded == operator test
{
    cout<<"Time overloaded == operator test"<<endl;
    Time t1(10,50);
    Time t2(10,50);

    if(t1==t2)
    {
        cout<<t1<<" is equal to "<<t2<<endl;
    }
    else
    {
        cout<<t1<<" is not equal to "<<t2<<endl;
    }
    cout<<endl;
}

void TimeTest8()//overloaded != operator test
{
    cout<<"Time overloaded != operator test"<<endl;
    Time t1(10,50);
    Time t2(10,51);

    if(t1!=t2)
    {
        cout<<t1<<" is not equal to "<<t2<<endl;
    }
    else
    {
        cout<<t1<<" is equal to "<<t2<<endl;
    }
    cout<<endl;
}
