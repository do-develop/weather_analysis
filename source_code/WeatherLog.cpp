#include "WeatherLog.h"
#include <fstream>
#include <sstream>
#include <string>

//CONSTRUCTOR------------------------------------------------------
//-----------------------------------------------------------------
WeatherLog::WeatherLog(){}

WeatherLog::~WeatherLog()
{
    for(auto itr = wmap.begin(); itr!=wmap.end(); itr++)
    {
        delete (itr->second);
    }
}

//GET METHOD-------------------------------------------------------
//-----------------------------------------------------------------

std::map<std::pair<Date, Time>, WeatherLogType*>& WeatherLog::GetWeatherLog()
{
    return wmap;
}

void WeatherLog::AddWeatherLog(WeatherLogType* wlt)
{
    wmap.insert(std::pair<pair<Date, Time>, WeatherLogType*>
        (std::make_pair(wlt->GetDate(), wlt->GetTime()),wlt));
}

bool WeatherLog::GetRange(int y, int m, Bst<WeatherLogType*> &wlog)
{
    int flag=0;


    for(auto itr = wmap.begin(); itr!=wmap.end(); itr++)
    {
        if(itr->first.first.GetYear()==y && itr->first.first.GetMonth()==m)
        {
            wlog.insertElement(itr->second);
            flag++;
        }
    }
    return flag;
}

//STATIC METHOD----------------------------------------------------
//-----------------------------------------------------------------
WeatherLogType WeatherLog::wsum;

void WeatherLog::SumWeatherLog(WeatherLogType* &log)
{
    wsum = wsum + *log;
}

WeatherLogType WeatherLog::GetSum()
{
    return wsum;
}

void WeatherLog::SetBack()
{
    WeatherLogType wlt; //empty WeatherLogType obj.
    wsum = wlt;
}
