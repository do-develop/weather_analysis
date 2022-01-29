#include "WeatherLogType.h"
#include <iostream>
#include <string>
const float MIN_SOLAR = 100;
//-----------------------------------------------------------
//CONSTRUCTORS AND DESTRUCTOR
//-----------------------------------------------------------
WeatherLogType::WeatherLogType()
{
    d = Date();
    t = Time();
    wspeed = 0;
    atemp = 0;
    sradiation = 0;
}

WeatherLogType::~WeatherLogType(){}

WeatherLogType::WeatherLogType(const WeatherLogType & cp)
{
    d = cp.GetDate();
    t = cp.GetTime();
    wspeed = cp.GetSpeed();
    atemp = cp.GetAtemp();
    sradiation = cp.GetSradiation();
}

WeatherLogType& WeatherLogType::operator = (const WeatherLogType & rhs)
{
    d = rhs.GetDate();
    t = rhs.GetTime();
    wspeed = rhs.GetSpeed();
    atemp = rhs.GetAtemp();
    sradiation = rhs.GetSradiation();

    return *this;
}
//-----------------------------------------------------------
//GET METHOD
//-----------------------------------------------------------
Date WeatherLogType::GetDate() const
{
    return d;
}
Time WeatherLogType::GetTime() const
{
    return t;
}
float WeatherLogType::GetSpeed() const
{
    return wspeed;
}
float WeatherLogType::GetAtemp() const
{
    return atemp;
}
float WeatherLogType::GetSradiation() const
{
    return sradiation;
}
//-----------------------------------------------------------
//SET METHOD
//-----------------------------------------------------------
void WeatherLogType::SetDate(Date date)
{
    d = date;
}
void WeatherLogType::SetTime(Time time)
{
    t = time;
}
void WeatherLogType::SetSpeed(float windsp)
{
    wspeed = windsp;
}
void WeatherLogType::SetAtemp(float ambitemp)
{
    atemp = ambitemp;
}
void WeatherLogType::SetSradiation(float solarr)
{
    sradiation = solarr;
}



//------------------------------------------------------------
//IO HELPER ROUTINES
//------------------------------------------------------------
istream & operator >> (std::istream & is, WeatherLogType & wlt)
{
    Date dobj;
    Time tobj;
    is>> dobj;
    is>> tobj;
    wlt.SetDate(dobj);
    wlt.SetTime(tobj);
    //is.clear();

    unsigned count=1; //1st column for  WAST is counted first

    std::string line;
    while(getline(is,line,','))
    {
        if(count==11) //11th column for speed
        {
            line != "N/A";
            {
                wlt.SetSpeed(std::atof(line.c_str()));
            }
        }
        if(count==12) //12th column solar radiation
        {
            line != "N/A";
            {
                wlt.SetSradiation(std::atof(line.c_str()));
            }
        }
        if(count==18) //18th column ambient temperature
        {
            line != "N/A";
            {
                wlt.SetAtemp(std::atof(line.c_str()));
            }
        }
        count++;
    }
    return is;
}

ostream & operator << (std::ostream & os, WeatherLogType & wlt)
{
    os<<wlt.GetDate()<<','<<wlt.GetTime()<<','<<wlt.GetSpeed()<<
    ','<<wlt.GetSradiation()<<','<<wlt.GetAtemp()<<'\n';
    return os;
}

//------------------------------------------------------------
//OVERLOADED + OPERATOR
//------------------------------------------------------------
WeatherLogType operator + (const WeatherLogType & lhs, const WeatherLogType & rhs)
{
    WeatherLogType w = WeatherLogType();

    w.SetSpeed(lhs.GetSpeed()+rhs.GetSpeed());
    w.SetAtemp(lhs.GetAtemp()+rhs.GetAtemp());

    if(lhs.GetSradiation()>=MIN_SOLAR)
    {
        w.SetSradiation(lhs.GetSradiation());
        if(rhs.GetSradiation()>=MIN_SOLAR)
        {
            w.SetSradiation(lhs.GetSradiation()+ rhs.GetSradiation());
        }
    }
    else
    {
        if(rhs.GetSradiation()>=MIN_SOLAR)
        {
            w.SetSradiation(rhs.GetSradiation());
        }
    }

    return w;
}
