#ifndef WEATHERLOG_H
#define WEATHERLOG_H
//----------------------------------------------------------------------
//----------------------------------------------------------------------
/**
 * @class WeatherLog
 * @brief It stores Weather data in map and controls the access to the data
 *
 * @author Doyoung Oh
 * @version 01
 * @date 21/09/2020 Created WeatherLog class
 *
 * @author Doyoung Oh
 * @version 02
 * @date 26/09/2020 Removed IO mehods from this class
 *
 * @author Doyoung Oh
 * @version 03
 * @date 15/10/2020 Map data structure
 *
 * @author Doyoung Oh
 * @version 04
 * @date 18/10/2020 Static memebers added, to utilize function pointer of Bst to calculate sum
 */
//----------------------------------------------------------------------
//----------------------------------------------------------------------
#include <map>
#include "Vector.h"
#include "WeatherLogType.h"
#include "Bst.h"
//----------------------------------------------------------------------
//CLASS DEFINITION
//----------------------------------------------------------------------
class WeatherLog
{
    public:
            /**
             * @brief Default constructor for WeatherLog
             */
        WeatherLog();

            /**
             * @brief Destructor for WeatherLog. This eliminates the WeatherLogType pointers generated in heap.
             */
        ~WeatherLog();

            /**
             * @brief Get method for WeatherLog
             * @return Reference to the map storing weather logs
             */
        std::map<std::pair<Date, Time>, WeatherLogType*>& GetWeatherLog();

            /**
             * @brief Get range data for a specific year and a specific month
             * @param year, month and a binary search tree to store the range of data
             * @return boolean value indicating if the range of data exists
             */
        bool GetRange(int y, int m, Bst<WeatherLogType*>& log);

            /**
             * @brief WeatherLogType pointer values are passed in, to store data inside the map
             * @param WeatherLogType objects in pointer data type
             */
        void AddWeatherLog(WeatherLogType*);

            /**
             * @brief Static method for this class that calculates the sum of WeatherLogType
             * @param reference to a WeatherLogType object in pointer data type
             */
        static void SumWeatherLog(WeatherLogType* &log);

            /**
             * @brief Static method that returns the static WeatherLogType sum value
             * @return sum value in WeatherLogType data type
             */
        static WeatherLogType GetSum();

            /**
             * @brief Static method that set the value of static sum value to default value
             */
        static void SetBack();

    private:
        ///static sum value of the WeatherLogType
        static WeatherLogType wsum;
        ///WeatherLogType is stored inside the map placing date and time combination as a compound key value
        std::map<std::pair<Date, Time>, WeatherLogType*> wmap;


};

//----------------------------------------------------------------------
//----------------------------------------------------------------------
#endif // WEATHERLOG_H
