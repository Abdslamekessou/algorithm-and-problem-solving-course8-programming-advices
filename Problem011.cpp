#include <iostream>
#include <vector>
#include <string>


/*
🧠 Program to convert between a specific date and its day order in a year.
📅 It first finds how many days have passed since the beginning of the year for a given date,
   then converts that order number back into a full date (day/month/year).
📤 Example:
     Input → Day = 16, Month = 10, Year = 2024
     Output → Number of days from beginning of year = 290
               Date for [290] is: 16/10/2024
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


sDate GetDateFromDayOrderInYear(short DayOrderInYear , short Year) {

    sDate Date;
    short RemainingDays;
    short MonthDays = 0;

    RemainingDays = DayOrderInYear;
    Date.Year = Year;
    Date.Month = 1;

    while (true) { 

        MonthDays = NumberOfDaysInAMonth(Year, Date.Month);

        if (RemainingDays > MonthDays) {

            RemainingDays -= MonthDays;
            Date.Month++;

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



int main()
{

    short day = ReadDay();
    short month = ReadMonth();
    short year = ReadYear();
    short DayOrderInYear = NumberOfDaysFromTheBeginningOfTheYear(day, month, year);

    cout << "\n\nThe Number Of Days from beginning of the year is : " << DayOrderInYear << "\n\n";
    
    sDate Date;
    Date = GetDateFromDayOrderInYear(DayOrderInYear, year);

    cout << "Date for [" << DayOrderInYear << "] is: " << Date.Day << "/" << Date.Month
        << "/" << Date.Year << "\n";

}
