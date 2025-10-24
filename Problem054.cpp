
#include <iostream>

using namespace std;

/*
🧠 Program to calculate the actual days of vacation.
📅 The program reads two dates (start and end) and calculates how many actual working days
   (Sunday to Thursday) are included in the vacation period, excluding weekends (Friday and Saturday).

🧩 Example:
   Input →
       Vacation Starts : 20/10/2025
       Vacation Ends   : 31/10/2025

📤 Output →
       Vacation From Mon , 20/10/2025
       Vacation To Fri , 31/10/2025
       Actual Vacation Days is : 9
*/



struct sDate {

    short Day;
    short Month;
    short Year;

};



short IsLeapYear(short year) {

    return  (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? true : false;

}




short NumberOfDaysInAMonth(short month, short year) {

    if (month < 1 || month > 12)
        return 0;


    int numberOfDays[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31  , 30 , 31 };

    return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : numberOfDays[month - 1];

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



bool IsDate1BeforeDate2(sDate Date1, sDate Date2) {

    return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);

}


int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false) {

    int Days = 0;

    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return IncludeEndDay ? ++Days : Days;
}




short DayOfWeekOrder(short day, short month, short year) {

    short a, y, m;

    a = (14 - month) / 12;

    y = year - a;

    m = month + 12 * a - 2;

    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

}



short DayOfWeekOrder(sDate Date) {

    return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);

}



string DayShortName(short DayOfWeekOrder) {

    string arrDaysNames[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

    return arrDaysNames[DayOfWeekOrder];
}




bool IsWeekEnd(sDate Date) {

    //Weekends are Fri and Sat

    short DayIndex = DayOfWeekOrder(Date);

    return (DayIndex == 5 || DayIndex == 6);

}



bool IsBusinessDay(sDate Date) {

    // Business days are Sun , Mon , Tue , Wed and Thur

    return !IsWeekEnd(Date);

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



short CalculatelVacationDays(sDate DateFrom, sDate DateTo) {

    short DaysCount = 0;

    while (IsDate1BeforeDate2(DateFrom, DateTo)) {

        if (IsBusinessDay(DateFrom))
            DaysCount++;


        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    return DaysCount;
}




int main()
{
    cout << "Vacation Starts : ";
    sDate DateFrom = ReadFullDate();

    cout << "\n\nVacation Ends : ";
    sDate DateTo = ReadFullDate();

    cout << "\n\nVacation From " << DayShortName(DayOfWeekOrder(DateFrom)) << " , " << DateFrom.Day 
        << "/" << DateFrom.Month << "/" << DateFrom.Year << endl;

    cout << "\nVacation To " << DayShortName(DayOfWeekOrder(DateTo)) << " , " << DateTo.Day << "/" 
        << DateTo.Month << "/" << DateTo.Year << endl;

    cout << "\nActual Vacation Days is : " << CalculatelVacationDays(DateFrom, DateTo);
    system("pause>0");
}


