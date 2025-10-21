#include <iostream>
#include <string>


/*
🧠 Program to calculate the difference in days between two dates (can be negative if Date1 > Date2).
📅 Example 1:
   Input → Date1 = 24/7/2004 , Date2 = 14/10/2025
📤 Output → Difference is : 7751 Day(s).
             Difference (Including End Day) is : 7752 Day(s).

📅 Example 2 (Date1 > Date2):
   Input → Date1 = 14/10/2025 , Date2 = 24/7/2004
📤 Output → Difference is : -7751 Day(s).
             Difference (Including End Day) is : -7752 Day(s).
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

void SwapDates(sDate& Date1, sDate& Date2) {

    sDate TempDate;

    TempDate.Day = Date1.Day;
    TempDate.Month = Date1.Month;
    TempDate.Year = Date1.Year;

    Date1.Day = Date2.Day;
    Date1.Month = Date2.Month;
    Date1.Year = Date2.Year;


    Date2.Day = TempDate.Day;
    Date2.Month = TempDate.Month;
    Date2.Year = TempDate.Year;

}


int GetDiffrenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false) {

    int Days = 0;
    short SwapFlagValue = 1;

    if (!IsDate1BeforeThanDate2(Date1, Date2)) {

        SwapDates(Date1, Date2);
        SwapFlagValue = -1;

    }

    while (IsDate1BeforeThanDate2(Date1, Date2)) {

        Days++;
        Date1 = IncreaseDateByOneDay(Date1);

    }

    return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;

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
    sDate Date1 = ReadFullDate();
    cout << "\n\n";
    sDate Date2 = ReadFullDate();


    cout << "\nDifference is : " << GetDiffrenceInDays(Date1, Date2, false) << " Days(s).\n";
    cout << "\nDifference (Including End Day) is : " << GetDiffrenceInDays(Date1, Date2, true) << " Days(s).\n";

    system("pause>0");
}
