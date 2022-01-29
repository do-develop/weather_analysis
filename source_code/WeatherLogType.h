#ifndef WEATHERLOGTYPE_H
#define WEATHERLOGTYPE_H
//---------------------------------------------------------------
//---------------------------------------------------------------
/**
 * @class WeatherLogType
 * @brief It contains date, time, wind speed, ambient temperature and solar radiation data
 *
 * @author Doyoung Oh
 * @version 01
 * @date 21/09/2020 Created WeatherLogType class
 *
 * @author Doyoung Oh
 * @version 02
 * @date 15/10/2020 + operator and an assignment operator are overloaded
 *
 */
//---------------------------------------------------------------
//---------------------------------------------------------------
#include "Date.h"
#include "Time.h"
//---------------------------------------------------------------
//CLASS DEFINITION
//---------------------------------------------------------------
class WeatherLogType
{
    public:
            /**
             * @brief Default constructor of WeatherLogType. Member variables are initialised.
             */
        WeatherLogType();

            /**
             * @brief Default destructor of WeatherLogType
             */
        ~WeatherLogType();

            /**
             * @brief Copy constructor of WeatherLogType
             * @param A WeatherLogType object to be copied from
             */
        WeatherLogType(const WeatherLogType & cp);

            /**
             * @brief Overloaded assignment operator for WeatherLogType
             * @param A WeatherLogType object to be copied from
             */
        WeatherLogType& operator = (const WeatherLogType & rhs);

            /**
             * @brief Get method for WeatherLogType
             * @return Date value of the WeatherLogType
             */
        Date GetDate() const;

            /**
             * @brief Get method for WeatherLogType
             * @return Time value of the WeatherLogType
             */
        Time GetTime() const;

            /**
             * @brief Get method for WeatherLogType
             * @return wind speed value
             */
        float GetSpeed() const;

            /**
             * @brief Get method for WeatherLogType
             * @return ambient temperature value
             */
        float GetAtemp() const;

            /**
             * @brief Get method for WeatherLogType
             * @return solar radiation value
             */
        float GetSradiation() const;

            /**
             * @brief Set method for WeatherLogType
             * @param date in Date data type
             */
        void SetDate(Date date);

            /**
             * @brief Set method for WeatherLogType
             * @param time in Time data type
             */
        void SetTime(Time time);

            /**
             * @brief Set method for WeatherLogType
             * @param takes in wind speed
             */
        void SetSpeed(float windsp);

            /**
             * @brief Set method for WeatherLogType
             * @param takes in ambient temperature
             */
        void SetAtemp(float ambitemp);

            /**
             * @brief Set method for WeatherLogType
             * @param takes in solar radiation
             */
        void SetSradiation(float solarr);

    private:
        ///date
        Date d;
        ///time
        Time t;
        ///wind speed
        float wspeed;
        ///ambient temperature
        float atemp;
        ///solar radiation
        float sradiation;

};
//---------------------------------------------------------------
//HELPER ROUTINES
//---------------------------------------------------------------
    /**
    * @brief  helper routine that receives the input stream and set members of WeatherLogType object
    * @param  reference of the input stream, reference to the WeatherLogType object
    * @return input stream reference
    */
istream & operator >> (std::istream & is, WeatherLogType & wlt);

    /**
    * @brief  helper routine that outputs the content of the WeatherLogType object
    * @param  reference of the output stream, reference to the WeatherLogType object
    * @return output stream reference
    */
ostream & operator << (std::ostream & os, WeatherLogType & wlt);

    /**
    * @brief  Overloaded + opeartor for WeatherLogType
    * @param  Two WeatherLogType objects, one frome left-side, the other from right-side
    * @return The result of the sum of the left-side and the right-side
    */
WeatherLogType operator + (const WeatherLogType & lhs, const WeatherLogType & rhs);

//---------------------------------------------------------------
//---------------------------------------------------------------
#endif // WEATHERLOGTYPE_H
