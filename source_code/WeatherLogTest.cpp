#include <iostream>
#include "WeatherLog.h"
using namespace std;

//WEATHERLOG UNIT TEST---------------------------------------------------
//-----------------------------------------------------------------------
void WeatherLogTest1();//Unit test WeatherLog constructor and GetWeatherLog()
void WeatherLogTest2();//testing AddWeatherLog(WeatherLogType*)
void WeatherLogTest3();//testing FindHighestSolarOfTheDate(Date&) & FindHighestSolarTime(Date, float)
void WeatherLogTest4();//testing GetRange(int, int, Bst<WeatherLogType*>& log)
void WeatherLogTest5();//testing static methods, SumWeatherLog, GetSum, SetBack
void print(WeatherLogType* &data);

int main()
{
    WeatherLogTest1();
    WeatherLogTest2();
    WeatherLogTest3();
    WeatherLogTest4();
    WeatherLogTest5();

    return 0;
}

//WEATHERLOG UNIT TEST---------------------------------------------------
//-----------------------------------------------------------------------
void WeatherLogTest1()//Unit test WeatherLog constructor and GetWeatherLog()
{
    cout<<"<<WeatherLog constructor test>>"<<endl;
    WeatherLog wlog;

    if(wlog.GetWeatherLog().empty())
    {
        cout<<"It is empty"<<endl;
    }
    cout<<endl;
}
void WeatherLogTest2()
{
    cout<<"<<WeatherLog AddWeatherLog(WeatherLogType*) test>>"<<endl;
    WeatherLogType wlt;
    Date dt(11,7,2020);
    Time t(11,30);

    wlt.SetDate(dt);
    wlt.SetTime(t);
    wlt.SetSpeed(10);
    wlt.SetAtemp(20);
    wlt.SetSradiation(500);

    WeatherLog wlog;
    wlog.AddWeatherLog(&wlt);

    std::map<std::pair<Date, Time>, WeatherLogType*>::iterator it = wlog.GetWeatherLog().begin();
    for(; it!=wlog.GetWeatherLog().end(); it++)
    {
        cout<<it->first.first<<endl;
        cout<<it->first.second<<endl;
        cout<<*(it->second)<<endl;
    }
    cout<<endl;
}

void WeatherLogTest3()//testing FindHighestSolarOfTheDate(Date&) & FindHighestSolarTime(Date, float)
{
    cout<<"<<Testing function finds the highest solar radiation of a date and the time>>"<<endl;
    cout<<"Expected result: 700, 11:50"<<endl;
    WeatherLogType wlt1;
    Date dt(11,7,2020);
    Time t1(11,30);

    wlt1.SetDate(dt);
    wlt1.SetTime(t1);
    wlt1.SetSpeed(10);
    wlt1.SetAtemp(20);
    wlt1.SetSradiation(500);

    WeatherLogType wlt2;
    Time t2(11,50);

    wlt2.SetDate(dt);
    wlt2.SetTime(t2);
    wlt2.SetSpeed(10);
    wlt2.SetAtemp(20);
    wlt2.SetSradiation(700);

    WeatherLog wlog;
    wlog.AddWeatherLog(&wlt1);
    wlog.AddWeatherLog(&wlt2);

    float highestSR = wlog.FindHighestSolarOfTheDate(dt);
    Vector<Time> highSolarTime;
    highSolarTime = wlog.FindHighestSolarTime(dt, highestSR);

    cout<<"Highest solar radiation of "<<dt<<" is "<<highestSR<<endl;
    for(int i=0; i<highSolarTime.GetLast(); i++)
    {
        cout<<"The time recorded the highest solar radiation is "<<highSolarTime.At(i)<<endl;
    }
    cout<<endl;
}
void print(WeatherLogType* &data)
{
    cout<<*data<<endl;
}
void WeatherLogTest4()//testing GetRange(int, int, Bst<WeatherLogType*>& log)
{
    cout<<"<<Testing GetRange method>>"<<endl;
    cout<<"Expected result: 11/07/2020,11:30,10,500,20"<<endl;
    WeatherLogType wlt1;
    Date dt(11,7,2020);
    Time t1(11,30);

    wlt1.SetDate(dt);
    wlt1.SetTime(t1);
    wlt1.SetSpeed(10);
    wlt1.SetAtemp(20);
    wlt1.SetSradiation(500);

    WeatherLogType wlt2;
    Time t2(11,50);

    wlt2.SetDate(dt);
    wlt2.SetTime(t2);
    wlt2.SetSpeed(10);
    wlt2.SetAtemp(20);
    wlt2.SetSradiation(700);

    WeatherLog wlog;
    wlog.AddWeatherLog(&wlt1);
    wlog.AddWeatherLog(&wlt2);
    Bst<WeatherLogType*> log;

    if(wlog.GetRange(2020, 7, log))
    {
        log.inOrderTraversal(print);
    }
    cout<<endl;
}
void WeatherLogTest5()//testing static methods, SumWeatherLog, GetSum, SetBack
{
    cout<<"<<Testing static methods: SumWeatherLog, GetSum, SetBack>>"<<endl;
    WeatherLogType wlt1;
    Date dt(11,7,2020);
    Time t1(11,30);
    wlt1.SetDate(dt);
    wlt1.SetTime(t1);
    wlt1.SetSpeed(10);
    wlt1.SetAtemp(20);
    wlt1.SetSradiation(500);

    WeatherLogType wlt2;
    Time t2(11,50);
    wlt2.SetDate(dt);
    wlt2.SetTime(t2);
    wlt2.SetSpeed(10);
    wlt2.SetAtemp(20);
    wlt2.SetSradiation(700);

    Bst<WeatherLogType*> log;
    log.insertElement(&wlt1);
    log.insertElement(&wlt2);

    WeatherLog W;

    log.inOrderTraversal(W.SumWeatherLog); //callback
    WeatherLogType sum;
    sum = W.GetSum(); //to access the result of the SumWeatherLog
    cout<<"After SumWeatherLog() and GetSum():"<<endl;
    cout<<sum<<endl;

    W.SetBack();
    sum = W.GetSum();
    cout<<"After SetBack():"<<endl;
    cout<<sum<<endl;
}
