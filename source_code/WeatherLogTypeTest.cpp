#include <iostream>
#include "WeatherLogType.h"
using namespace std;

//WEATHERLOGTYPE UNIT TEST---------------------------------------
//---------------------------------------------------------------
void WeatherLogTypeTest1();//Unit test WeatherLogType, constructor and get methods for all attributes
void WeatherLogTypeTest2();//Unit test WeatherLogType, SetSpeed()
void WeatherLogTypeTest3();//Unit test WeatherLogType, SetAtemp()
void WeatherLogTypeTest4();//Unit test WeatherLogType, SetSradiation()
void WeatherLogTypeTest5();//overloaded + operator test

int main()
{
    WeatherLogTypeTest1();
    WeatherLogTypeTest2();
    WeatherLogTypeTest3();
    WeatherLogTypeTest4();
    WeatherLogTypeTest5();

    return 0;
}

//WEATHERLOGTYPE UNIT TEST---------------------------------------
//---------------------------------------------------------------
void WeatherLogTypeTest1()//Unit test WeatherLogType, constructor and get methods for all attributes
{
    WeatherLogType wlt;
    cout<<"WeatherLogType constructor and get methods test"<<endl;
    cout<<"Expected result: 00/00/0, 00:00, 0, 0, 0"<<endl;
    cout<<wlt.GetDate()<<endl;
    cout<<wlt.GetTime()<<endl;
    cout<<wlt.GetSpeed()<<endl;
    cout<<wlt.GetAtemp()<<endl;
    cout<<wlt.GetSradiation()<<endl;
    cout<<endl;
}
void WeatherLogTypeTest2()//Unit test WeatherLogType, SetSpeed()
{
    cout<<"WeatherLogType SetSpeed() test"<<endl;
    cout<<"Expected result 10"<<endl;
    WeatherLogType wlt;
    wlt.SetSpeed(10);
    cout<<wlt.GetSpeed()<<endl;
    cout<<endl;
}
void WeatherLogTypeTest3()//Unit test WeatherLogType, SetAtemp()
{
    cout<<"WeatherLogType SetAtemp(), GetAtemp() test"<<endl;
    cout<<"Expected result 25"<<endl;
    WeatherLogType wlt;
    wlt.SetAtemp(25);
    cout<<wlt.GetAtemp()<<endl;
    cout<<endl;
}
void WeatherLogTypeTest4()//Unit test WeatherLogType, SetSradiation()
{
    cout<<"WeatherLogType SetSradiation(), GetSradiation() test"<<endl;
    cout<<"Expected result 10"<<endl;
    WeatherLogType wlt;
    wlt.SetSradiation(10);
    cout<<wlt.GetSradiation()<<endl;
    cout<<endl;
}

void WeatherLogTypeTest5()
{
    cout<<"WeatherLogType overloaded + operator test"<<endl;
    cout<<"Expected result 40, 50, 200"<<endl;
    WeatherLogType wlt1;
    wlt1.SetSpeed(20);
    wlt1.SetAtemp(25);
    wlt1.SetSradiation(100);

    WeatherLogType wlt2;
    wlt2.SetSpeed(20);
    wlt2.SetAtemp(25);
    wlt2.SetSradiation(100);

    WeatherLogType wlt3;
    wlt3 = wlt1 + wlt2;

    cout<<wlt3.GetSpeed()<<endl;
    cout<<wlt3.GetAtemp()<<endl;
    cout<<wlt3.GetSradiation()<<endl;
    cout<<endl;
}
