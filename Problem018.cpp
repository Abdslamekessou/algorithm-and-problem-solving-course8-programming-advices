#include <iostream>
#include <string>
#include <ctime>

/*
🧠 Program to calculate your exact age in days from your birth date to today.
📅 Example:
   Input → Date of Birth = 24/7/2004
📤 Output → Your Age is : 7758 Day(s).
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


short NumberOfDaysInAMonth(short month, short year) {

    if (month < 1 || month > 12)
        return 0;


    int numberOfDays[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31  , 30 , 31 };

    return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : numberOfDays[month - 1]; // one line of condition

}


bool IsLastDayInMonth(sDate Date) {

    return NumberOfDaysInAMonth(Date.Month, Date.Year) == Date.Day;

}



bool IsLastMonthInYear(short Month) {

    return Month == 12;

}


sDate IncreaseDateByOneDay(sDate Date) {

    if (IsLastDayInMonth(Date)) {

        if (IsLastMonthInYear(Date.Month)) {

            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        }
        else {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else {
        Date.Day++;
    }

    return Date;

}


bool IsDate1BeforeThanDate2(sDate Date1, sDate Date2) {

    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);

}


int GetDiffrenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false) {

    int Days = 0;

    while (IsDate1BeforeThanDate2(Date1, Date2)) {

        Days++;
        Date1 = IncreaseDateByOneDay(Date1);

    }

    return IncludeEndDay ? ++Days : Days;

}



sDate GetSystemDay() {

    time_t now = time(0);
    tm local;
    localtime_s(&local, &now);
    sDate Date;

    Date.Day = local.tm_mday;
    Date.Month = local.tm_mon + 1;
    Date.Year = local.tm_year + 1900;

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



int main()
{
    cout << "\nPlease Enter Your Date Of Birth : \n";
    sDate Date1 = ReadFullDate();
    sDate Date2 = GetSystemDay();

    cout << "\n\nYour Age is : " << GetDiffrenceInDays(Date1 , Date2) << " Day(s).";

    system("pause>0");
}
