#ifndef DATE_H
#define DATE_H
//-------------------------------------------------------------------
//-------------------------------------------------------------------
/**
 * @class  Date
 * @brief  simulates Date data in int/int/int data type
 *
 * @author KRI
 * @version 01
 *
 * @author Doyoung Oh
 * @version 02
 * @date 15/09/2020 friend function is declared outside of the class
 *
 * @author Doyoung Oh
 * @version 03
 * @date 10/10/2020 comparison operators overloaded
 *
 */

#include <string>
using namespace std;

//-------------------------------------------------------------------
//CLASS DEFINITION
//-------------------------------------------------------------------
class Date
{
    public:
//CONSTRUCTOR--------------------------------------------------------
//-------------------------------------------------------------------
        /**
        * @brief  Default constructor of Date class
        * This function will set initial value of each variable to zero
        */
    Date();

        /**
        * @brief  Default destructor of Date class
        */
    ~Date();

        /**
        * @brief  Copy constructor of Date class
        * @param  Takes in a Date object as a parameter
        */
    Date(const Date& dt);

        /**
        * @brief  Overloaded assignment operator
        * @param  Takes in a Date object of the right hand side as a parameter
        * @return Reference to this Date
        */
    Date& operator = (const Date& rhs);

        /**
        * @brief  Constructor that takes in values to initialise
        * @param  Takes in three integers representing day, month and year for each
        */
    Date(unsigned d, unsigned m, unsigned y);
//FUNCTION PROTOTYPES------------------------------------------------
//-------------------------------------------------------------------
    //get methods
        /**
        * @brief  Get and return the value of day
        * @return integer value of day
        */
    unsigned GetDay() const;

        /**
        * @brief  Get and return the value of month
        * @return integer value of month
        */
    unsigned GetMonth() const;

        /**
        * @brief  Get and return the value of year
        * @return integer value of year
        */
    unsigned GetYear() const;

    //set methods
        /**
        * @brief  Set the day from the input
        * @param  integer value of day
        * @return void
        */
    void SetDay(unsigned day);

        /**
        * @brief  Set the month from the input
        * @param  integer value of month
        * @return void
        */
    void SetMonth(unsigned month);

        /**
        * @brief  Set the year from the input
        * @param  integer value of year
        * @return void
        */
    void SetYear(unsigned year);

        /**
        * @brief  Set the date from the string input
        * @pre    The date string must be in correct format
        * @param  date in string form
        * @return void
        */
    void SetDate(string date);

//MEMBER VARIABLES---------------------------------------------------
//-------------------------------------------------------------------
    private:
        ///day of the date
        unsigned day;
        ///month of the date
        unsigned month;
        ///year of the date
        unsigned year;
};

//OVERLOADED OPERATORS-----------------------------------------------
//-------------------------------------------------------------------
    /**
    * @brief > operator is overloaded for Date class
    * @param Two Date parameters, one from left side the other from right side
    * @return The boolean value whether the left Date is bigger than the right Date
    */
bool operator > (const Date& lhs, const Date& rhs);

    /**
    * @brief < operator is overloaded for Date class
    * @param Two Date parameters, one from left side the other from right side
    * @return The boolean value whether the left Date is smaller than the right Date
    */
bool operator < (const Date& lhs, const Date& rhs);

    /**
    * @brief == operator is overloaded for Date class
    * @param Two Date parameters, one from left side the other from right side
    * @return The boolean value whether the left Date is equal to the right Date
    */
bool operator == (const Date& lhs, const Date& rhs);

    /**
    * @brief != operator is overloaded for Date class
    * @param Two Date parameters, one from left side the other from right side
    * @return The boolean value whether the left Date is not equal to the right Date
    */
bool operator != (const Date& lhs, const Date& rhs);

//IO HELPER ROUTINES-------------------------------------------------
//-------------------------------------------------------------------
    /**
    * @brief  Receive the input stream and set variable of Date object
    * @param  reference of the input stream, reference to a Date object
    * @return input stream reference
    */
istream & operator >>( istream & is, Date & D );

    /**
    * @brief  Display the content of the Date object
    * @param  reference of the output stream, reference to a Date object
    * @return output stream reference
    */
ostream & operator <<( ostream & os, const Date & D);

//-------------------------------------------------------------------
//-------------------------------------------------------------------
#endif // DATE_H
