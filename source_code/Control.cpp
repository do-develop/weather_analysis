#include "Control.h"
#include <fstream>
#include <sstream>
#include<limits> //validation check
#include <iomanip>
#include <cmath> //to use round() function

using namespace std;
//----------------------------------------------------------------------
const string DATA_PATH = "data/";
const string OutputFileName = "WindTempSolar.csv";
//----------------------------------------------------------------------
const string breakline ="------------------------------------------------------------------------------";
const string option1 = "1. The average wind speed and average ambient air temperature for a specified\n   month and year. (print on screen only)";
const string option2 = "2. Average wind speed and average ambient air temperature for each month of\n   a specified year. (print on screen only)";
const string option3 = "3. Total solar radiation in kWh/m2 for each month of a specified year.\n   (print on screen only)";
const string option4 = "4. Average wind speed (km/h), average ambient air temperature and total\n   solar radiation in kWh/m2 for each month of a specified year.\n   (write to a file called \"WindTempSolar.csv\")";
const string option5 = "5. The times for the highest solar radiation for the date given in the form\n   d/m/yyyy. (print on screen only)";
const string option6 = "6. Exit the program.";

//RUN PROGRAM-----------------------------------------------------------
//----------------------------------------------------------------------
void Control::Run(string filelist)
{
    if(ReadFile(filelist))
    {
        int choice;
        do
        {
            MenuDisplay();
            while (!(cin>>choice))//validate user input is integer type
            {
                cin.clear(); //clear bad input flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                cout << "Invalid input. Please re-enter.\nEnter choice: ";
            }
            MenuChoice(choice);
        }
        while(choice!=6);

    }
    else
    {
        cout<<"File reading failure"<<endl;
        return;
    }
}

//MENU INTERFACE--------------------------------------------------------
//----------------------------------------------------------------------
void Control::MenuDisplay()
{
    cout<<breakline<<endl;
    cout<<option1<<endl;
    cout<<option2<<endl;
    cout<<option3<<endl;
    cout<<option4<<endl;
    cout<<option5<<endl;
    cout<<option6<<endl;
    cout<<breakline<<endl;
    cout<<"Enter choice: ";
}

void Control::MenuChoice(int choice)
{
    switch(choice)
    {
    case 1:
        cout<<option1<<endl;
        Menu1();
        break;
    case 2:
        cout<<option2<<endl;
        Menu2();
        break;
    case 3:
        cout<<option3<<endl;
        Menu3();
        break;
    case 4:
        cout<<option4<<endl;
        Menu4();
        break;
    case 5:
        cout<<option5<<endl;
        Menu5();
        break;
    case 6:
        cout<<"----------End of Program----------"<<endl;
        break;
    default:
        cout<<"Invalid menu selected. Enter from 1 to 6"<<endl;
        break;
    }
}

//READ FROM FILE---------------------------------------------------
//-----------------------------------------------------------------
bool Control::ReadFile(string filelist)
{
    ifstream filelog(DATA_PATH + filelist);
    string filename;
    if(filelog.rdstate()==0)
    {
        while(getline(filelog, filename))
        {
            ifstream infile(DATA_PATH + filename);

            if(infile.rdstate()==0)
            {
                string line;
                getline(infile, line); //skip first line
                while(getline(infile, line))
                {
                    if(line.empty()) // if there is a blank line
                    {
                        getline(infile, line); // skip blank line
                    }
                    else
                    {
                        WeatherLogType* wlogtype =  new WeatherLogType;
                        stringstream ss(line);
                        ss>>*wlogtype;
                        wlog.AddWeatherLog(wlogtype);
                    }
                }
                cout<<"Loaded - "<<filename<<endl;
                infile.close();
            }
            else
            {
                cout<<"Load Fail - "<<filename<<endl;
                return false;
            }
        }
        filelog.close();
        return true;
    }
    else
    {
        return false;
    }

}

//GET USER INPUT---------------------------------------------------
//-----------------------------------------------------------------
int Control::GetYear()
{
    int year;
    //executes loop if the input fails (e.g., no characters were read)
    while ((cout << "Enter a year: " && !(cin >> year)) || (year<0))
    {
        cin.clear(); //clear bad input flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
        cout << "Invalid input. Please re-enter.\n"<<endl;
    }
    return year;
}

int Control::GetMonth()
{
    int month;

    while ((cout << "Enter a month: " && !(cin >> month)) || (month<=0 || month>12))
    {
        cin.clear(); //clear bad input flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
        cout << "Invalid input. Please re-enter.\n"<<endl;
    }

    return month;
}

Date Control::GetDate()
{
    Date dt;
    string date;
    bool validDate = false;

    try
    {
        while(!validDate)
        {
            cout<< "Date: ";
            cin >> date;
            validDate = CheckValidDate(date);
            if(!validDate)
            {
                cout<<"Invalid date. Please re-enter."<<endl;
            }
        }
        dt.SetDate(date);
        return dt;
    }
    catch (...)
    {
        cout<<"Invalid input."<<endl;
    }

}

bool Control::CheckValidDate(string date)
{
    stringstream ss(date);
    string tmp;
    int d=0, m=0, y=0;
    getline(ss,tmp,'/');
    d = stoi(tmp);
    getline(ss,tmp,'/');
    m = stoi(tmp);
    getline(ss,tmp);
    y = stoi(tmp);

    //check leap year
    if(y>0)
    {
        if(m>0 || m<=12)
        {
            if(m==2)
            {
                //check leap year
                if((y % 4 == 0 && y % 100 !=0) || (y % 400 == 0))
                {
                    if(d>0 && d<=28)
                    {
                        return true;
                    }
                }
                else
                {
                    if(d>0 && d<=29)
                    {
                        return true;
                    }
                }
            }
            else if(m == 1 || m == 3 || m  == 5 || m == 7 || m == 8 || m == 10 || m == 12)
            {
                if(d>0 && d<=31)
                {
                    return true;
                }
            }
            else
            {
                if(d>0 && d<=30)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

//MENU1------------------------------------------------------------
//-----------------------------------------------------------------
void Control::Menu1()//average speed, temp for specific year and month on screen
{
    int year = GetYear();
    int month = GetMonth();

    float avgWS = 0.0;
    float avgAT = 0.0;
    Bst<WeatherLogType*> wlt;

    if(wlog.GetRange(year, month, wlt))//if there's corresponding value
    {
        //wlt.inOrderTraversal();
        avgWS = CalculateAverageSpeed(wlt);
        avgAT = CalculateAverageTemperature(wlt);
        cout<<fixed<<setprecision(1);
        cout<<ConvertToStringMonth(month)<<" "<<year<<": "
        <<ConvertWindSpeed(avgWS)<<"km/h, "<<avgAT<<" degrees C"<<endl;
    }
    else
    {
        cout<<ConvertToStringMonth(month)<<" "<<year<<": No Data"<<endl;
    }
}

//MENU2------------------------------------------------------------
//-----------------------------------------------------------------
void Control::Menu2()//average speed, temp for each month of a specific year on screen
{
    int year = GetYear();

    Bst<WeatherLogType*> wlt[12];
    StoreDataMonthly(year, wlt);

    cout<<year<<endl;

    for(int j=0; j<12; ++j)
    {
        if(wlt[j].Count()>0)
        {
            float avgWS = 0.0;
            float avgAT = 0.0;
            avgWS = CalculateAverageSpeed(wlt[j]);
            avgAT = CalculateAverageTemperature(wlt[j]);

            cout<<fixed<<setprecision(1);
            cout<<ConvertToStringMonth(j+1)<<": "
            <<ConvertWindSpeed(avgWS)<<"km/h, "<<avgAT<<" degrees C"<<endl;
        }
        else
        {
            cout<<ConvertToStringMonth(j+1)<<": No Data"<<endl;
        }
    }

}

//MENU3------------------------------------------------------------
//-----------------------------------------------------------------
void Control::Menu3()//total solar radiation for each month of a specific year on screen
{
    int year = GetYear();

    Bst<WeatherLogType*> wlt[12];
    StoreDataMonthly(year, wlt);

     //generate output
    cout<<year<<endl;
    for(int j=0; j<12; j++)
    {
        if(wlt[j].Count()!=0)
        {
            float totalSR = 0.0;
            totalSR = CalculateTotalSolarRadiation(wlt[j]);

            cout<<fixed<<setprecision(1);
            cout<<ConvertToStringMonth(j+1)<<": "
            <<ConvertSolarRadiation(totalSR)<<"kWh/m2"<<endl;
        }
        else
        {
            cout<<ConvertToStringMonth(j+1)<<": No Data"<<endl;
        }
    }
}

//MENU4------------------------------------------------------------
//-----------------------------------------------------------------
void Control::Menu4()//average speed, temperature & total solar radiation of specific year to file
{
    int year = GetYear(); //get user input for year

    Bst<WeatherLogType*> wlt[12];
    StoreDataMonthly(year, wlt);
    int yearFlag = 0; //flag to see if there is data for the year
    //generate output for menu4
    ofstream output(OutputFileName);
    if(output.is_open())
    {
        output<<year<<endl;
        for(int j=0; j<12; j++)
        {
            if(wlt[j].Count()!=0)
            {
                yearFlag++;
                float avgWS = 0.0;
                float avgAT = 0.0;
                float totalSR = 0.0;

                avgWS = CalculateAverageSpeed(wlt[j]);
                avgAT = CalculateAverageTemperature(wlt[j]);
                totalSR = CalculateTotalSolarRadiation(wlt[j]);

                output<<fixed<<setprecision(1);
                output<<ConvertToStringMonth(j+1)<<','
                <<ConvertWindSpeed(avgWS)<<','<<avgAT<<','
                <<ConvertSolarRadiation(totalSR)<<endl;
            }
        }
        if(!yearFlag)
        {
            output<<"No Data"<<endl;
        }
        output.close();
        cout<<"\""<<OutputFileName<<"\" generated."<<endl;
    }
    else
    {
        cout<<"File writing unsuccessful."<<endl;
    }
}

//MENU5------------------------------------------------------------
//-----------------------------------------------------------------
void Control::Menu5()
{
    Date emptyDate;
    Date dt = GetDate();
    if (dt != emptyDate)
    {
        float highestSR = FindHighestSolarOfTheDate(dt);
        Vector<Time> highestTime = FindHighestSolarTime(dt, highestSR);
        //generate output;
        if(highestSR!=0)
        {
            cout<<"High solar radiation for the day: "<<highestSR<<" W/m2"<<endl;
            cout<<endl;
            cout<<"Time:"<<endl;
            for(int i=0; i<highestTime.GetLast(); i++)
            {
                cout<<highestTime.At(i)<<endl;
            }
        }
        else
        {
            cout<<"No data"<<endl;
        }

    }
}

//STORAGE MANIPULATION---------------------------------------------
//-----------------------------------------------------------------
void Control::StoreDataMonthly(int year, Bst<WeatherLogType*> (&range)[12])
{
    std::map<std::pair<Date, Time>, WeatherLogType*>* wmap = &wlog.GetWeatherLog();
    std::map<std::pair<Date, Time>, WeatherLogType*>::iterator itr;

    for(itr=wmap->begin(); itr!=wmap->end(); itr++)
    {
        if(itr->first.first.GetYear()==year)
        {
            for(int j=0; j<12; ++j)
            {
                if(itr->first.first.GetMonth()==(j+1))
                {
                    range[j].insertElement(itr->second);
                }
            }
        }
    }
}

//CONVERSION METHODS----------------------------------------------
//----------------------------------------------------------------
string Control::ConvertToStringMonth(int month)
{
    string stringMonth[12] = {"January","February","March","April","May",
    "June","July","August","September","October","November","December"};

    return stringMonth[month-1];
}
float Control::ConvertWindSpeed(float sp)
{
    return sp * 3.6;
}
float Control::ConvertSolarRadiation(float sr)
{
    return sr/6000;
}

//CALCULATION METHODS----------------------------------------------
//-----------------------------------------------------------------

float Control::CalculateAverageSpeed(Bst<WeatherLogType*>& log)
{
    float avgWS = 0;

    WeatherLog W;// for returning the data that is returned in the callback
                // the callback is a static method of this Class

    log.inOrderTraversal(W.SumWeatherLog); //callback
    float count = log.Count();

    if(count!=0)
    {
        avgWS = W.GetSum().GetSpeed()/count;
    }

    W.SetBack();//set sum to zero for next calculation
    return avgWS;
}

float Control::CalculateAverageTemperature(Bst<WeatherLogType*>& log)
{
    float avgAT = 0;

    WeatherLog W;
    log.inOrderTraversal(W.SumWeatherLog);
    float count = log.Count();

    if(count!=0)
    {
        avgAT = W.GetSum().GetAtemp()/count;
    }

    W.SetBack();//set sum to zero for next calculation

    return avgAT;

}

float Control::CalculateTotalSolarRadiation(Bst<WeatherLogType*>& log)
{
    WeatherLog W;
    log.inOrderTraversal(W.SumWeatherLog);

    float totalSR = W.GetSum().GetSradiation();

    W.SetBack();//set static sum to zero for next calculation

    return totalSR;
}


float Control::FindHighestSolarOfTheDate(Date& dt)
{
    std::map<std::pair<Date, Time>, WeatherLogType*>* wmap = &wlog.GetWeatherLog();
    float highestSR = 0.0;

    for(auto itr = wmap->begin(); itr!=wmap->end(); itr++)
    {
        if(itr->first.first==dt)
        {
            if(highestSR < itr->second->GetSradiation())
            {
                highestSR = itr->second->GetSradiation();
            }
        }
    }

    return highestSR;
}

Vector<Time> Control::FindHighestSolarTime(Date dt, float highestSR)
{
    std::map<std::pair<Date, Time>, WeatherLogType*>* wmap = &wlog.GetWeatherLog();
    Vector<Time> highTime;

    for(auto itr=wmap->begin(); itr!=wmap->end(); ++itr)
    {
        if(itr->first.first == dt)
        {
            if(itr->second->GetSradiation() == highestSR)
            {
                highTime.Insert(itr->first.second);
            }
        }
    }
    return highTime;
}
