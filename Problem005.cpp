
#include <iostream>
using namespace std;

/*
🌟 Program: Month Time Calculator
🧠 Goal: Calculate days, hours, minutes, and seconds in a given month of a specific year.
📘 Rule: February → 29 days if leap year, otherwise 28; months with 31 or 30 days follow the calendar rule.
📥 Input:
   Enter a Year to check?
   Enter a Month to check?
📤 Output (example for Year = 2024, Month = 2):
     Number of    Days in Month  [2] is 29
     Number of   Hours in Month  [2] is 696
     Number of Minutes in Month  [2] is 41760
     Number of Secondes in Month [2] is 2505600
*/


short IsLeapYear(short year) {

    return  (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? true : false;

}


short NumberOfDaysInAMonth(short year , short month) {
    
    if (month < 1 || month > 12)
        return 0;

    if (month == 2)
        return IsLeapYear(year) ? 29 : 28;

    short arr31Monthes[7] = {1 , 3 , 5 , 7 , 8 , 10 , 12};

    for (int i = 1; i <= 7; i++) {

        if (month == arr31Monthes[i - 1])
            return 31;

    }

    return 30;
    
}


short NumberOfHoursInAMonth(short year, short month) {

    return NumberOfDaysInAMonth(year, month) * 24;

}


int NumberOfMinutesInAMonth(short year, short month) {

    return NumberOfHoursInAMonth(year, month) * 60;

}


int NumberOfSecondesInAMonth(short year, short month) {

    return NumberOfMinutesInAMonth(year, month) * 60;

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

    cout << "\nNumber of    Days in Month  [" << month << "] is " << NumberOfDaysInAMonth(year , month) << endl;
    cout << "\nNumber of   Hours in Month  [" << month << "] is " << NumberOfHoursInAMonth(year , month) << endl;
    cout << "\nNumber of Minutes in Month  [" << month << "] is " << NumberOfMinutesInAMonth(year , month) << endl;
    cout << "\nNumber of Secondes in Month [" << month << "] is " << NumberOfSecondesInAMonth(year , month) << endl;

}





