#ifndef TIME_H
#define TIME_H
//---------------------------------------------------------------
//---------------------------------------------------------------
/**
 *
 * @class Time
 * @brief Time class that stores the values of hour and minute
 *
 * @author Doyoung Oh
 * @version 01
 * @date 21/09/2020 created get/set methods and overloaded istream/ostream operator
 *
 * @author Doyoung Oh
 * @version 02
 * @date 10/10/2020 comparison operators are overloaded
 */

#include <iostream>
using namespace std;

//---------------------------------------------------------------
//CLASS DEFINITION
//---------------------------------------------------------------
class Time
{
    public:
            /**
             * @brief Default constructor for Time
             */
        Time();

            /**
             * @brief Default deconstructor for Time
             */
        ~Time();

            /**
             * @brief Copy constructor for Time
             * @param Takes in a Time object to be copied from
             */
        Time(const Time& t);

            /**
            * @brief  Overloaded assignment operator
            * @param  Takes in a Time object of the right hand side as a parameter
            * @return The reference to this Time
            */
        Time& operator = (const Time& rhs);

            /**
             * @brief Time constructor taking hour and minute value to initialise
             * @param hour- unsigned data for hour, minute - unsigned data for minute
             */
        Time(unsigned hr, unsigned mn);

            /**
             * @brief get method that returns hour value
             * @return unsigned value of hour
             */
        unsigned GetHour() const;

             /**
             * @brief get method that returns minute value
             * @return unsigned value of minute
             */
        unsigned GetMinute() const;

            /**
             * @brief set method to set hour
             * @param hour - unsigned data type for hour value
             * @return void
             */
        void SetHour(unsigned hr);

            /**
             * @brief set method to set minute
             * @param minute - unsigned data type for minute value
             * @return void
             */
        void SetMinute(unsigned mn);

    private:
        ///hour of time
        unsigned hour;
        ///minute of time
        unsigned minute;
};
//---------------------------------------------------------------
//---------------------------------------------------------------
    /**
    * @brief  Receive the input stream and set variable of Time object
    * @param  reference of the input stream, reference to the Time object
    * @return input stream reference
    */
istream & operator >> (istream & is, Time & T);

    /**
    * @brief  Display the content of the Time object
    * @param  reference of the output stream, reference to the Time object
    * @return output stream reference
    */
ostream & operator << (ostream & os, const Time & T);

    /**
    * @brief > operator is overloaded for Time class
    * @param Two Time parameters, one from left side the other from right side
    * @return The boolean value whether the left side Time is bigger than the right side Time
    */
bool operator > (const Time& lhs, const Time& rhs);

    /**
    * @brief < operator is overloaded for Time class
    * @param Two Time parameters, one from left side the other from right side
    * @return The boolean value whether the left side Time is smaller than the right side Time
    */
bool operator < (const Time& lhs, const Time& rhs);

    /**
    * @brief == operator is overloaded for Time class
    * @param Two Time parameters, one from left side the other from right side
    * @return The boolean value whether the left side Time is equal to the right side Time
    */
bool operator == (const Time& lhs, const Time& rhs);

    /**
    * @brief != operator is overloaded for Time class
    * @param Two Time parameters, one from left side the other from right side
    * @return The boolean value whether the left side Time is not equal to the right side Time
    */
bool operator != (const Time& lhs, const Time& rhs);

//---------------------------------------------------------------
//---------------------------------------------------------------
#endif // TIME_H
