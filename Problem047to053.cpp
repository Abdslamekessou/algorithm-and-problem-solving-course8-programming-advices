
#include <iostream>

using namespace std;

/*
🧠 Program to analyze a given date and display detailed information.
📅 The program checks if the date is weekend, end of week, or business day,
   and also calculates how many days remain until the end of the week, month, and year.

🧩 Example:
   Input  → 24/10/2025

📤 Output →

    Today is Fri , 24/10/2025

    Is it End of Week?
    No it's not end of week.

    Is it Weekend?
    Yes it is a week end.

    Is it Business Day?
    No it is NOT a business day.

    Days until end of week : 1 Day(s).
    Days until end of month : 8 Day(s).
    Days until end of year : 69 Day(s).
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


bool IsDate1BeforeDate2(sDate Date1, sDate Date2) { 

    return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false); 

}


int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false){ 
    
   int Days = 0;

   while (IsDate1BeforeDate2(Date1, Date2)) 
   { 
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



short DayOfWeekOrder(short day, short month, short year) {

    short a, y, m;

    a = (14 - month) / 12;

    y = year - a;

    m = month + 12 * a - 2;

    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

}


short DayOfWeekOrder(sDate Date) {

    return DayOfWeekOrder(Date.Day , Date.Month , Date.Year);

}



string DayShortName(short DayOfWeekOrder) {

    string arrDaysNames[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

    return arrDaysNames[DayOfWeekOrder];
}



bool IsEndOfWeek(sDate Date) {

    return   DayOfWeekOrder(Date) == 6;

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


short DaysUtilEndOfWeek(sDate Date) {
    
    return 6 - DayOfWeekOrder(Date);

}


short DaysUtilEndOfMonth(sDate Date) {

    sDate EndOfMonthDate;

    EndOfMonthDate.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
    EndOfMonthDate.Month = Date.Month;
    EndOfMonthDate.Year = Date.Year;

    return GetDifferenceInDays(Date, EndOfMonthDate, true);

}


short DaysUtilEndOfYear(sDate Date) {

    sDate EndOfYearDate;

    EndOfYearDate.Day = 31 ;
    EndOfYearDate.Month = 12;
    EndOfYearDate.Year = Date.Year;

    return GetDifferenceInDays(Date, EndOfYearDate, true);
}



int main()
{
    sDate Date = GetSystemDay();
    

    cout << "\nToday is " << DayShortName(DayOfWeekOrder(Date)) << " , " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    cout << "\nIs it End of Week?" ;

    if (IsEndOfWeek(Date)) {
        cout << "\nYes it is Saturday , it's end of week.\n";
    } 
    else {
        cout << "\nNo it's not end of week.\n";
    }


    cout << "\nIs it Weekend?" ;

    if (IsWeekEnd(Date)) {
        cout << "\nYes it is a week end.\n";
    }
    else {
        cout << "\nNo Today is "<< DayShortName(DayOfWeekOrder(Date)) << " , Not a week end.\n";

    }


    cout << "\nIs it Business Day?";

    if (IsBusinessDay(Date)) {
        cout << "\nYes it is a business day.\n";
    }
    else {
        cout << "\nNo it is NOT a business day.\n";

    }

    cout << "\nDays until end of week : " << DaysUtilEndOfWeek(Date) << " Day(s).";
    cout << "\nDays until end of month : " << DaysUtilEndOfMonth(Date) << " Day(s).";
    cout << "\nDays until end of year : " << DaysUtilEndOfYear(Date) << " Day(s).";

}


