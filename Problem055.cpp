
#include <iostream>

using namespace std;

/*
🧠 Program to calculate the actual return date after a vacation.
📅 The program reads the vacation start date and the number of vacation days,
   then calculates the real return date excluding weekends (Friday and Saturday).

🧩 Example:
   Input →
       Vacation Starts : 1/1/2022
       Vacation Days   : 23

📤 Output →
       Return Date : Wed , 2/2/2022
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


short ReadVacationDays() {

    short VacationDays;

    cout << "\nPlease enter vacation days ? ";
    cin >> VacationDays;

    return VacationDays;
}



sDate CalculatelVacationReturnDay(sDate DateFrom,short VacationDays) {

    short WeekendCounter = 0;

    while (IsWeekEnd(DateFrom)) {

        DateFrom = IncreaseDateByOneDay(DateFrom);

    }

    for (short i = 1; i <= VacationDays + WeekendCounter; i++)
    {
        if (IsWeekEnd(DateFrom)) {

            WeekendCounter++;

        }

        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    while (IsWeekEnd(DateFrom)) {

        DateFrom = IncreaseDateByOneDay(DateFrom);

    }

    return DateFrom;
}




int main()
{
    cout << "Vacation Starts : ";
    sDate DateFrom = ReadFullDate();

    short VacationDays = ReadVacationDays();

    DateFrom = CalculatelVacationReturnDay(DateFrom, VacationDays);

    cout << "\nReturn Date : " << DayShortName(DayOfWeekOrder(DateFrom)) << " , " << DateFrom.Day
        << "/" << DateFrom.Month << "/" << DateFrom.Year << endl; ;
    
}


