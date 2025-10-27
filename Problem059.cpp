
#include <iostream>

using namespace std;



/*
🧠 Program to calculate the number of days in a given period (between two dates).
📅 Example:
   Input → Start Date = 1/1/2025 , End Date = 10/1/2025
📤 Output →
   Period Length is : 9 Day(s)
   Period Length (Including End Date) is : 10 Day(s)
*/


struct sDate {

    short Day;
    short Month;
    short Year;

};


struct stPeriod {
    sDate StartDate;
    sDate EndDate;
};



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



stPeriod ReadPeriod() {

    stPeriod Period;

    cout << "\nEnter  Start Date : \n";
    Period.StartDate = ReadFullDate();


    cout << "\n\nEnter End Date : ";
    Period.EndDate = ReadFullDate();

    return Period;
}


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




bool IsDate1BeforeThanDate2(sDate Date1, sDate Date2) {

    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);

}




bool IsDate1EqualsDate2(sDate Date1, sDate Date2) {

    return (Date1.Year == Date2.Year ? (Date1.Month == Date2.Month ? (Date1.Day == Date2.Day ? true : false) : false) : false);
}




bool IsDate1AfterDate2(sDate Date1, sDate Date2) {

    return (!IsDate1BeforeThanDate2(Date1, Date2) && !IsDate1EqualsDate2(Date1, Date2));

}

int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false) { 

    int Days = 0;

    while (IsDate1BeforeThanDate2(Date1, Date2)) 
    { 
      Days++; 

      Date1 = IncreaseDateByOneDay(Date1); 

    } 
    
    return IncludeEndDay ? ++Days : Days; 
}


int PeriodLengthInDays(stPeriod Period , bool IncludeEndDay = false) {
    
    return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
}



int main()
{
    stPeriod Period;


    cout << "Enter Period :";
    Period = ReadPeriod();

    cout <<"\nPeriod Length is : " << PeriodLengthInDays(Period) << endl;
    cout <<"\nPeriod Length (Including End Date) is :" << PeriodLengthInDays(Period, true);


    system("pause>0");

}




