
#include <iostream>
#include <vector>
#include <string>

/*
🧠 Program to print the monthly calendar for a given month and year.
📘 Uses Zeller’s formula to calculate the first day of the month.
📤 Example:
     Please enter a Year? 2024
     Please enter a Month ? 2

     _________________Feb_________________
       Sun  Mon  Tue  Wed  Thu  Fri  Sat
                              1    2    3
        4    5    6    7    8    9   10
       11   12   13   14   15   16   17
       18   19   20   21   22   23   24
       25   26   27   28   29

     _____________________________________
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



short DayOfWeekOrder(short day, short month, short year) {

    short a, y, m;

    a = (14 - month) / 12;

    y = year - a;

    m = month + 12 * a - 2;

    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

}


string DayShortName(short DayOfWeekOrder) {

    string arrDaysNames[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

    return arrDaysNames[DayOfWeekOrder];
}



string MonthShortName(short MonthNumber) {

    string arrMonthNames[12] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    return arrMonthNames[MonthNumber - 1];

}



void PrintMonthCalendar(short month, short year) {

    short NumberOfDays;

    short current = DayOfWeekOrder(1, month, year);

    NumberOfDays = NumberOfDaysInAMonth(year, month);

    printf("\n_________________%s_________________\n\n", MonthShortName(month).c_str());

    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    short i;

    for (i = 0; i < current; i++) {

        printf("     ");
    }

  
    for (short j = 1; j <= NumberOfDays; j++) {

        printf("%5d", j);

        if (++i == 7) {
            i = 0;
            printf("\n");
        }

    }


    printf("\n\n_____________________________________");
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




int main()
{
    short year = ReadYear();
    short month = ReadMonth();

    PrintMonthCalendar(month, year);
}





