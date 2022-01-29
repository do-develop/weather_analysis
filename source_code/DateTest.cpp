#include <iostream>
#include "Date.h"
using namespace std;

//DATE UNIT TEST-------------------------------------------------
//---------------------------------------------------------------
void DateTest1();//Unit test Date constructor
void DateTest2();//Unit test Date constructor with parameter initializing day, month, and year
void DateTest3();//Unit test Date, set method for day
void DateTest4();//Unit test Date, set method for month
void DateTest5();//Unit test Date, set method for year
void DateTest6();//overloaded > operator test
void DateTest7();//overloaded < operator test
void DateTest8();//overloaded == operator test
void DateTest9();//overloaded != operator test

int main()
{
    DateTest1();
    DateTest2();
    DateTest3();
    DateTest4();
    DateTest5();
    DateTest6();
    DateTest7();
    DateTest8();
    DateTest9();

    return 0;
}

//DATE UNIT TEST-------------------------------------------------
//---------------------------------------------------------------
void DateTest1()//Unit test Date constructor
{
    cout<<"Date constructor test"<<endl;
    cout<<"Expected result: 00/00/0"<<endl;
    Date dt;
    cout<<dt<<endl;
    cout<<endl;
}
void DateTest2()//Unit test Date constructor with parameter initializing day, month, and year
{
    cout<<"Date constructor with intializer test"<<endl;
    cout<<"Expected result: 29/09/2020"<<endl;
    Date dt(29,9,2020);
    cout<<dt<<endl;
    cout<<endl;
}
void DateTest3()//Unit test Date, set method for day
{
    cout<<"Date SetDay() test"<<endl;
    cout<<"Expected result: 29/00/0"<<endl;
    Date dt;
    dt.SetDay(29);
    cout<<dt<<endl;
    cout<<endl;
}
void DateTest4()//Unit test Date, set method for month
{
    cout<<"Date SetMonth() test"<<endl;
    cout<<"Expected result: 00/09/0"<<endl;
    Date dt;
    dt.SetMonth(9);
    cout<<dt<<endl;
    cout<<endl;
}
void DateTest5()//Unit test Date, set method for year
{
    cout<<"Date SetYear() test"<<endl;
    cout<<"Expected result: 00/00/2020"<<endl;
    Date dt;
    dt.SetYear(2020);
    cout<<dt<<endl;
    cout<<endl;
}

void DateTest6()//overloaded > operator test
{
    Date dt1(1,1,2013);
    Date dt2(2,2,2012);

    cout<<"Date overloaded > operator test"<<endl;
    if(dt1>dt2)
    {
        cout<<dt1<<" is bigger than "<<dt2<<endl;
    }
    else
    {
        cout<<dt1<<" is smaller than "<<dt2<<endl;
    }
    cout<<endl;
}
void DateTest7()//overloaded < operator test
{
    Date dt1(1,1,2012);
    Date dt2(2,2,2012);

    cout<<"Date overloaded < operator test"<<endl;
    if(dt1<dt2)
    {
        cout<<dt1<<" is smaller than "<<dt2<<endl;
    }
    else
    {
        cout<<dt1<<" is bigger than "<<dt2<<endl;
    }
    cout<<endl;
}
void DateTest8()//overloaded == operator test
{
    Date dt1(1,1,2012);
    Date dt2(1,1,2012);

    cout<<"Date overloaded == operator test"<<endl;
    if(dt1==dt2)
    {
        cout<<dt1<<" is equal to "<<dt2<<endl;
    }
    else
    {
        cout<<dt1<<" is not equal to "<<dt2<<endl;
    }
    cout<<endl;
}
void DateTest9()//overloaded != operator test
{
    Date dt1(2,1,2012);
    Date dt2(1,1,2012);

    cout<<"Date overloaded != operator test"<<endl;
    if(dt1!=dt2)
    {
        cout<<dt1<<" is not equal to "<<dt2<<endl;
    }
    else
    {
        cout<<dt1<<" is equal to "<<dt2<<endl;
    }
    cout<<endl;
}
