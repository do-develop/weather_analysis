#ifndef CONTROL_H //IO control
#define CONTROL_H
//----------------------------------------------------------------------
//----------------------------------------------------------------------
/**
 * @class Control
 * @brief It handles input and output of data
 *
 * @author Doyoung Oh
 * @version 01
 * @date 23/09/2020 Created Control class
 *
 * @author Doyoung Oh
 * @version 02
 * @date 26/09/2020 Added IO mehods from WeatherLog class
 *
 * @author Doyoung Oh
 * @version 03
 * @date 03/10/2020 The function to read multiple files has been implemented
 *
 * @author Doyoung Oh
 * @version 04
 * @date 15/10/2020 STL map implemented
 *
 * @author Doyoung Oh
 * @version 05
 * @date 22/10/2020 Pointer type is stored in Bst to improve performance from using Bst
 */

//----------------------------------------------------------------------
//----------------------------------------------------------------------
#include "WeatherLog.h"
#include "Bst.h"
//----------------------------------------------------------------------
//----------------------------------------------------------------------
class Control
{
   public:

            /**
            * @brief  whole program runs within this structure
            * @param  pass in name of the filelist in string data type
            */
        void Run(string filename);

            /**
            * @brief  reads in data inside the WeatherLog object
            * @param  file name in string data type
            * @return boolean value indicating if the reading has been successful
            */
        bool ReadFile(string filelist);

    //Menu interface
            /**
             * @brief Display the menu on screen
             */
        void MenuDisplay();

            /**
             * @brief Prompt for menu choice from user and get input
             * @param Reference to a WeatherLog and user choice
             */
        void MenuChoice(int choice);

    //Get user input
            /**
             * @brief Prompt for year value from user
             * @return user input for the year
             */
        int GetYear();

            /**
             * @brief Prompt to enter month value from user
             * @return user input for the month
             */
        int GetMonth();

            /**
             * @brief Prompt to enter a date from user
             * @return a date from user input
             */
        Date GetDate();

            /**
             * @brief Checks the string data for the validity of a date
             * @param a string that represents a date in a format d/m/yyyy
             * @return boolean value wheaterh the date is valid
             */
        bool CheckValidDate(string date);

    //Calcuation methods

            /**
             * @brief calculates the average wind speed inside the WeatherLogType binary search tree
             * @param Reference to the WeatherLogType binary search tree
             * @return average value of wind speed
             */
        float CalculateAverageSpeed(Bst<WeatherLogType*>& log);

            /**
             * @brief calculates the average ambient temperature inside the WeatherLogType binary search tree
             * @param Reference to the WeatherLogType binary search tree
             * @return average value of ambient temperature
             */
        float CalculateAverageTemperature(Bst<WeatherLogType*>& log);

            /**
             * @brief calculates the total solar radiation from the WeatherLogType binary search tree
             * @param Reference to the WeatherLogType binary search tree
             * @return total value of solar radiation
             */
        float CalculateTotalSolarRadiation(Bst<WeatherLogType*>& log);

            /**
             * @brief This method finds the highest solar radiation value of a specific date
             * @param a date
             * @return highest solar radiation value of the date
             */
        float FindHighestSolarOfTheDate(Date& dt);

            /**
             * @brief This method finds the time that reached the highest solar radiation
             * @param a date and the highest solar radiation value
             * @return a Vector that stores the times that reached the highest solar radiation value
             */
        Vector<Time> FindHighestSolarTime(Date dt, float highestSR);

    //Menu options
            /**
             * @brief get average speed and average temperature of specific year and month output to screen
             */
        void Menu1();

            /**
             * @brief get average speed and average temperature for each month of a specific year, output to screen
             */
        void Menu2();

            /**
             * @brief get total solar radiation for each month of a specific year, print on screen
             */
        void Menu3();

            /**
             * @brief output average speed, temperature & total solar radiation of specific year to a file
             */
        void Menu4();

            /**
             * @brief displays highest solar radiation of a specific date and the time that reached the highest value
             */
        void Menu5();

    //Convert format
            /**
             * @brief convert the integer value of a month to the string data
             * @param integer value of a month
             * @return month in string
             */
        string ConvertToStringMonth(int month);

            /**
             * @brief convert the w/s to km/h
             * @param speed in w/s
             * @return speed in km/h
             */
        float ConvertWindSpeed(float sp);

            /**
             * @brief convert the w/m2 to kWh/m2
             * @param speed in w/m2
             * @return speed in kWh/m2
             */
        float ConvertSolarRadiation(float sr);

    //Storage manipulation
            /**
             * @brief store data in an array of Bst
             * @param year value and an array of Bst to store monthly data from the specific year
             */
        void StoreDataMonthly(int year, Bst<WeatherLogType*> (&range)[12]);

    private:
        ///WeatherLog member variable to access to the data stored in map
        WeatherLog wlog;
};

//----------------------------------------------------------------------
//----------------------------------------------------------------------
#endif // CONTROL_H
