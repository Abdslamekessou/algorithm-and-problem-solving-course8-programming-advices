#include <iostream>
#include <string>


/*
🧠 Program to decrease a given date by different time units.
📅 The program subtracts days, weeks, months, years, decades, centuries, and millenniums from a given date.

🧩 Example:
   Input  → 31/12/2022
   Output →
      01 - Subtracting one day is : 30/12/2022
      02 - Subtracting 10 days is : 20/12/2022
      03 - Subtracting one week is : 13/12/2022
      04 - Subtracting 10 weeks is : 4/10/2022
      05 - Subtracting one month is : 4/9/2022
      06 - Subtracting 5 months is : 4/4/2022
      07 - Subtracting one year is : 4/4/2021
      08 - Subtracting 10 years is : 4/4/2011
      09 - Subtracting 10 years (faster) is : 4/4/2001
      10 - Subtracting one decade is : 4/4/1991
      11 - Subtracting 10 decades is : 4/4/1891
      12 - Subtracting 10 decades (faster) is : 4/4/1791
      13 - Subtracting one century is : 4/4/1691
      14 - Subtracting one millennium is : 4/4/691
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



sDate DecreaseDateByOneDay(sDate Date) {

    if (Date.Day == 1) {

        if (Date.Month == 1) {

            Date.Day = 31;
            Date.Month = 12;
            Date.Year--;
        }
        else {
            Date.Day = NumberOfDaysInAMonth(Date.Month - 1 , Date.Year);
            Date.Month--;
        }
    }
    else {
        Date.Day--;
    }

    return Date;

}



sDate DecreaseDateByXDays(sDate Date , short Days) {

    for (short i = 1; i <= Days; i++) {

        Date = DecreaseDateByOneDay(Date);

    }

    return Date;

}



sDate DecreaseDateByOneWeek(sDate Date) {

    for (short i = 1; i <= 7 ; i++) {

        Date = DecreaseDateByOneDay(Date);

    }

    return Date;

}



sDate DecreaseDateByXWeeks(sDate Date, short Weeks) {

    for (short i = 1; i <= Weeks; i++) {

        Date = DecreaseDateByOneWeek(Date);

    }

    return Date;

}



sDate DecreaseDateByOneMonth(sDate Date) {
    
    if (Date.Month == 1) {

        Date.Month = 12;
        Date.Year--;

    }
    else {

        Date.Month--;
    }

    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

    if (Date.Day > NumberOfDaysInCurrentMonth) {

        Date.Day = NumberOfDaysInCurrentMonth;

    }

    return Date;

}



sDate DecreaseDateByXMonths(sDate Date, short Months) {

    for (short i = 1; i <= Months ; i++) {

        Date = DecreaseDateByOneMonth(Date);

    }

    return Date;

}



sDate DecreaseDateByOneYear(sDate Date) {

    Date.Year--;

    return Date;

}



sDate DecreaseDateByXYears(sDate Date, short Years) {

    for (short i = 1; i <= Years; i++) {

        Date = DecreaseDateByOneYear(Date);

    }

    return Date;

}



sDate DecreaseDateByXYearsFaster(sDate Date, short Years) {

    Date.Year -= Years;

    return Date;

}



sDate DecreaseDateByOneDecade(sDate Date) {

    Date.Year -= 10;

    return Date;

}



sDate DecreaseDateByXDecades(sDate Date, short Decade) {

    for (short i = 1; i <= Decade * 10 ; i++) {

        Date = DecreaseDateByOneYear(Date);

    }

    return Date;

}



sDate DecreaseDateByXDecadesFaster(sDate Date, short Decade) {

    Date.Year -= Decade * 10;

    return Date;

}



sDate DecreaseDateByOneCentury(sDate Date) {

    Date.Year -= 100;

    return Date;

}



sDate DecreaseDateByOneMillinium(sDate Date) {

    Date.Year -= 1000;

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
    sDate Date = ReadFullDate();

    cout << "\n\nDate After : \n\n";

    Date = DecreaseDateByOneDay(Date);
    cout << "01 - Subtracting one day is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXDays(Date , 10);
    cout << "02 - Subtracting 10 days is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;


    Date = DecreaseDateByOneWeek(Date);
    cout << "03 - Subtracting one week is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXWeeks(Date , 10);
    cout << "04 - Subtracting 10 weeks is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneMonth(Date);
    cout << "05 - Subtracting one month is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXMonths(Date , 5);
    cout << "06 - Subtracting 5 months is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneYear(Date);
    cout << "07 - Subtracting one year is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXYears(Date , 10);
    cout << "08 - Subtracting 10 Years is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXYearsFaster(Date, 10);
    cout << "09 - Subtracting 10 Years (faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneDecade(Date);
    cout << "10 - Subtracting one Decade is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXDecades(Date , 10);
    cout << "11 - Subtracting 10 Decades is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXDecadesFaster(Date, 10);
    cout << "12 - Subtracting 10 Decades (faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneCentury(Date);
    cout << "13 - Subtracting One Century is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneMillinium(Date);
    cout << "14 - Subtracting One Millinium is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    system("pause>0");
}

