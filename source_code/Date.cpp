//Date.CPP - Date class implementation
#include "Date.h"
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

Date::Date()
:day(0),month(0),year(0){}

Date::~Date(){}

Date::Date(const Date& dt)
{
    day = dt.GetDay();
    month = dt.GetMonth();
    year = dt.GetYear();
}

Date& Date::operator = (const Date& rhs)
{
    day = rhs.GetDay();
    month = rhs.GetMonth();
    year = rhs.GetYear();

    return *this;
}

Date::Date(unsigned d, unsigned m, unsigned y):
day(d),month(m),year(y){}
//GET METHOD---------------------------------------------------------
//-------------------------------------------------------------------
unsigned Date::GetDay() const
{
    return day;
}
unsigned Date::GetMonth() const
{
    return month;
}
unsigned Date::GetYear() const
{
    return year;
}

//SET METHOD---------------------------------------------------------
//-------------------------------------------------------------------
void Date::SetDay(unsigned day)
{
    this->day = day;
}
void Date::SetMonth(unsigned month)
{
    this->month = month;
}
void Date::SetYear(unsigned year)
{
    this->year = year;
}

void Date::SetDate(string date)
{
    stringstream ss(date);
    string tmp;
    getline(ss,tmp,'/');
    day = stoi(tmp);
    getline(ss,tmp,'/');
    month = stoi(tmp);
    getline(ss,tmp);
    year = stoi(tmp);
}

//OVERLOADED OPERATORS-----------------------------------------------
//-------------------------------------------------------------------
bool operator > (const Date& lhs, const Date& rhs)
{
    if(lhs.GetYear()!=rhs.GetYear())
    {
        return lhs.GetYear()>rhs.GetYear();
    }
    else if(lhs.GetMonth()!=rhs.GetMonth())
    {
        return lhs.GetMonth()>rhs.GetMonth();
    }
    else if(lhs.GetDay()!=rhs.GetDay())
    {
        return lhs.GetDay()>rhs.GetDay();
    }
    else //equal date
    {
        return false;
    }
}

bool operator < (const Date& lhs, const Date& rhs)
{
    if(lhs.GetYear()!=rhs.GetYear())
    {
        return lhs.GetYear()<rhs.GetYear();
    }
    else if(lhs.GetMonth()!=rhs.GetMonth())
    {
        return lhs.GetMonth()<rhs.GetMonth();
    }
    else if(lhs.GetDay()!=rhs.GetDay())
    {
        return lhs.GetDay()<rhs.GetDay();
    }
    else //equal date
    {
        return false;
    }
}

bool operator == (const Date& lhs, const Date& rhs)
{
    return (lhs.GetYear()==rhs.GetYear() && lhs.GetMonth()==rhs.GetMonth() && lhs.GetDay()==rhs.GetDay());
}

bool operator != (const Date& lhs, const Date& rhs)
{
    return (lhs.GetYear()!=rhs.GetYear() || lhs.GetMonth()!=rhs.GetMonth() || lhs.GetDay()!=rhs.GetDay());
}

//OVERLOADED IO STREAM HELPER ROUTINE--------------------------------
//-------------------------------------------------------------------
istream & operator >>(istream & is, Date & D)
{
    int temp;
    is>>temp;
    D.SetDay(temp);

    is.ignore(1,'/');
    is>>temp;
    D.SetMonth(temp);

    is.ignore(1,' ');
    is>>temp;
    D.SetYear(temp);

    return is;
}

ostream & operator <<(ostream & os, const Date & D)
{
  os <<setfill('0')<<setw(2)<<D.GetDay()<<'/'<<
  setfill('0')<<setw(2)<<D.GetMonth()<<'/'<<D.GetYear();

  return os;
}

