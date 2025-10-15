
#include <iostream>
using namespace std;


/*
🧠 Program to find number of days in a given month and year in only one line of condition.
📤 Example: Year = 2024, Month = 2 → Number of Days = 29
*/



short IsLeapYear(short year) {

    return  (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? true : false;

}



short NumberOfDaysInAMonth(short year, short month) {

   if (month < 1 || month > 12)
        return 0;


   int numberOfDays[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31  , 30 , 31 }; 

   return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : numberOfDays[month - 1]; // one line of condition

}



short ReadYear() {

    short Year;

    cout << "\nEnter a Year to check? ";
    cin >> Year;

    return Year;
}



short ReadMonth() {

    short month;

    cout << "\nEnter a Month to check? ";
    cin >> month;

    return month;
}



int main()
{
    short year = ReadYear();
    short month = ReadMonth();

    cout << "\nNumber of    Days in Month  [" << month << "] is " << NumberOfDaysInAMonth(year, month) << endl;

}





