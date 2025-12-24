#include <iostream>
#include <string>


/*
🧠 Program to check if a given date is the last day of the month or the last month of the year.
📅 Example:
   Date = 31/12/2025
📤 Output →
         Yes , Day is Last Day in Month.
         Yes , Month is Last Month in Year.
*/


using namespace std;


short IsLeapYear(short year) {

    return  (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? true : false;

}


struct sDate {

    short Day;
    short Month;
    short Year;

};


short NumberOfDaysInAMonth(short month , short year) {

    if (month < 1 || month > 12)
        return 0;


    int numberOfDays[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31  , 30 , 31 };

    return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : numberOfDays[month - 1]; // one line of condition

}


bool IsLastDayInMonth(sDate Date) {

    return NumberOfDaysInAMonth(Date.Month, Date.Year) == Date.Day;

}


bool IsLastMonthInYear(short Month) {

    return Month == 12 ;

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



sDate ReadFullDate() {

    sDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}



int main()
{
    sDate Date = ReadFullDate();


    if (IsLastDayInMonth(Date)) {

        cout << "\nYes , Day is Last Day in Month.\n";

    }
    else {

        cout << "\nYes , Day is NOT Last Day in Month.\n";

    }


    if (IsLastMonthInYear(Date.Month)) {

        cout << "\nYes , Month is Last Month in Year.\n";

    }
    else {

        cout << "\nYes , Month is NOT Last Month in Year.\n";

    }

    system("pause>0");
}
