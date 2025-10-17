
#include <iostream>
#include <vector>
#include <string>

/*
🧠 Program to calculate the number of days passed since the beginning of a given year.
📅 Takes user input for day, month, and year, and computes the total number of days up to that date.
🔢 Automatically accounts for leap years when calculating February’s days.
📤 Example:
     Please enter a Day ? 29
     Please enter a Month ? 2
     Please enter a Year ? 2024
     → The Number Of Days from beginning of the year is : 60
*/


using namespace std;

short IsLeapYear(short year) {

    return  (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? true : false;

}



short NumberOfDaysInAMonth(short year, short month) {

    if (month < 1 || month > 12)
        return 0;


    int numberOfDays[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31  , 30 , 31 };

    return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : numberOfDays[month - 1]; // one line of condition

}



short NumberOfDaysFromTheBeginningOfTheYear(short day,short month ,short year) {

    short TotalDays = 0;


    for (short j = 1; j <= month - 1; j++) {

        TotalDays += NumberOfDaysInAMonth(year, j);


    }
    
    TotalDays += day;

    return TotalDays;

}




short ReadYear() {

    short Year;

    cout << "\nPlease enter a Year? ";
    cin >> Year;

    return Year;
}



short ReadMonth() {

    short month;

    cout << "\nPlease enter a Month ? ";
    cin >> month;

    return month;
}



short ReadDay() {

    short day;

    cout << "\nPlease enter a Day ? ";
    cin >> day;

    return day;
}



int main()
{

    short day = ReadDay();
    short month = ReadMonth();
    short year = ReadYear();

    cout << "\n\nThe Number Of Days from beginning of the year is : " << NumberOfDaysFromTheBeginningOfTheYear(day, month, year) << "\n\n";
 
}





