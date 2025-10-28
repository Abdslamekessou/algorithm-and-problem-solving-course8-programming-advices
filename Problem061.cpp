
#include <iostream>

using namespace std;


/* 📅 Program: Calculate overlap days between two date periods.

   💡 Example:
      Period1 = 1/1/2025 → 10/1/2025
      Period2 = 5/1/2025 → 31/12/2025
      Output → Overlap Days = 6 

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



enum enDateCompare {
    eBefore = -1,
    eEqual = 0,
    eAfter = 1
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





enDateCompare CompareDates(sDate Date1, sDate Date2) {

    if (IsDate1BeforeThanDate2(Date1, Date2))
        return enDateCompare::eBefore;

    if (IsDate1EqualsDate2(Date1, Date2))
        return enDateCompare::eEqual;


    return enDateCompare::eAfter;

}




bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2) {

    if (
        CompareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::eBefore ||
        CompareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::eAfter
        ) {
        return false;
    }

    return true;
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




int PeriodLengthInDays(stPeriod Period, bool IncludeEndDate = false) { 

    return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDate); 

}



bool isDateInPeriod(sDate Date, stPeriod Period) { 

    return !(

        CompareDates(Date, Period.StartDate) == enDateCompare::eBefore 
        || 
        CompareDates(Date, Period.EndDate) == enDateCompare::eAfter
    );

}



int CountOverlapDays(stPeriod Period1, stPeriod Period2) {

    int OverLapDays = 0;

    int PeriodLength1 = GetDifferenceInDays(Period1.StartDate, Period1.EndDate , true);
    int PeriodLength2 = GetDifferenceInDays(Period2.StartDate, Period2.EndDate, true);

    if (!IsOverlapPeriods(Period1, Period2))
        return 0;
    
    if (PeriodLength1 < PeriodLength2) {

        while (IsDate1BeforeThanDate2(Period1.StartDate , Period1.EndDate)) {

            if (isDateInPeriod(Period1.StartDate, Period2))
                OverLapDays++;

            Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);

        }

    }
    else {

        while (IsDate1BeforeThanDate2(Period2.StartDate, Period2.EndDate)) {

            if (isDateInPeriod(Period2.StartDate, Period1))
                OverLapDays++;

            Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);

        }

    }

    return OverLapDays;
}



int main()
{
    stPeriod Period1;
    stPeriod Period2;
    

    cout << "Enter Period 1 :";
    Period1 = ReadPeriod();

    cout << "\n\nEnter Period 2 :";
    Period2 = ReadPeriod();

    cout <<"\n\nOverlap Days Count Is : " << CountOverlapDays(Period1, Period2);

    system("pause>0");

}
