#include <iostream>
#include <vector>
#include <string>

/*
🧠 Program to add a specific number of days to a given date.
📅 Example: Date = 19/10/2025, Days to add = 2500
📤 Output → Date after adding [2500] days is : 23/8/2032 ✅
*/

using namespace std;

short IsLeapYear(short year) {

    return  (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? true : false;

}


short NumberOfDaysInAYear(short year) {

    return IsLeapYear(year) ? 366 : 365;

}


short NumberOfDaysInAMonth(short year, short month) {

    if (month < 1 || month > 12)
        return 0;


    int numberOfDays[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31  , 30 , 31 };

    return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : numberOfDays[month - 1]; // one line of condition

}


short NumberOfDaysFromTheBeginningOfTheYear(short day, short month, short year) {

    short TotalDays = 0;


    for (short j = 1; j <= month - 1; j++) {

        TotalDays += NumberOfDaysInAMonth(year, j);
    }

    TotalDays += day;

    return TotalDays;

}


struct sDate {

    short Day;
    short Month;
    short Year;

};



sDate DateAddDays(short Days , sDate Date) {
    
    short RemainingDays = Days + NumberOfDaysFromTheBeginningOfTheYear(Date.Day, Date.Month, Date.Year);
    short MonthDays = 0;

    Date.Month = 1;

    while (true) {

        MonthDays = NumberOfDaysInAMonth(Date.Year, Date.Month);

        if (RemainingDays > MonthDays) {

            RemainingDays -= MonthDays;
            Date.Month++;

            if (Date.Month > 12) {

                Date.Month = 1;
                Date.Year++;

            }
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }

    }

    return Date;
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



short ReadDaysToAdd() {

    short days;

    cout << "\nHow many days to add ? ";
    cin >> days;

    return days;
}



int main()
{
    sDate Date = ReadFullDate();
    short Days = ReadDaysToAdd();

    Date = DateAddDays(Days , Date);
   
    cout << "\nDate after adding [" << Days << "] days is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

}
