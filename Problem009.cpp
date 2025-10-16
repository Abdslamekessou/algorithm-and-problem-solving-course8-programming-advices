
#include <iostream>
#include <vector>
#include <string>

/*
🧠 Program to print the full year calendar for a given year.
📅 Displays all 12 months with correct days and alignment using Zeller’s formula.
🧩 Handles leap years automatically for February (29 days).
📤 Example:
     Please enter a Year? 2024
     → Prints the full 2024 calendar month by month.
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



void PrintYearCalendar(short year) {
    
    printf("\n_____________________________________\n");
    printf("\n              Calendar - %d", year);
    printf("\n_____________________________________\n");

    for (short i = 1; i <= 12; i++) {
        cout << "\n\n";
        PrintMonthCalendar(i, year);
        
    }

    return;
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

    PrintYearCalendar(year);
}





