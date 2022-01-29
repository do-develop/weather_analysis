#include "Time.h"
#include <iomanip>
#include <string>
//---------------------------------------------------------------
//CONSTRUCTORS AND DESTRUCTOR
//---------------------------------------------------------------
Time::Time()
{
    hour = 0;
    minute = 0;
}

Time::~Time(){}

Time::Time(const Time& t)
{
    hour = t.GetHour();
    minute = t.GetMinute();
}

Time& Time::operator = (const Time& rhs)
{
    hour = rhs.GetHour();
    minute = rhs.GetMinute();

    return *this;
}

Time::Time(unsigned hr, unsigned mn)
{
    hour = hr;
    minute = mn;
}

//---------------------------------------------------------------
//GET AND SET METHODS
//---------------------------------------------------------------
unsigned Time::GetHour() const
{
    return hour;
}

unsigned Time::GetMinute() const
{
    return minute;
}

void Time::SetHour(unsigned hr)
{
    hour = hr;
}

void Time::SetMinute(unsigned mn)
{
    minute = mn;
}

//---------------------------------------------------------------
//OVERLOADED COMPARISON OPERATOR
//---------------------------------------------------------------
bool operator > (const Time& lhs, const Time& rhs)
{
    if(lhs.GetHour() != rhs.GetHour())
    {
        return lhs.GetHour() > rhs.GetHour();
    }
    else if(lhs.GetMinute() != rhs.GetMinute())
    {
        return lhs.GetMinute() > rhs.GetMinute();
    }
    else
    {
        return false;
    }
}

bool operator < (const Time& lhs, const Time& rhs)
{
    if(lhs.GetHour() != rhs.GetHour())
    {
        return lhs.GetHour() < rhs.GetHour();
    }
    else if(lhs.GetMinute() != rhs.GetMinute())
    {
        return lhs.GetMinute() < rhs.GetMinute();
    }
    else //if equal
    {
        return false;
    }
}

bool operator == (const Time& lhs, const Time& rhs)
{
    return (lhs.GetHour()==rhs.GetHour() && lhs.GetMinute()==rhs.GetMinute());
}

bool operator != (const Time& lhs, const Time& rhs)
{
    return (lhs.GetHour()!=rhs.GetHour() || lhs.GetMinute()!=rhs.GetMinute());
}

//---------------------------------------------------------------
//IO HELPER ROUTINES
//---------------------------------------------------------------
istream & operator >> (istream & is, Time & T)
{
    unsigned hr, mn;

    is>>hr;
    T.SetHour(hr);
    is.ignore(1,':');
    is>>mn;
    T.SetMinute(mn);

    return is;
}

ostream & operator << (ostream & os, const Time & T)
{
    os<<setw(2)<<setfill('0')<<T.GetHour()<<':'<<setw(2)<<setfill('0')<<T.GetMinute();
    return os;
}
