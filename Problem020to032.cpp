#include <iostream>
#include <string>

/*
🧠 Program to increase a given date by different time units (days, weeks, months, years, decades, centuries, and millenniums).
It demonstrates how to handle date increments accurately, including leap years and month-end transitions.

📅 Example:
   Input → Date = 31/12/2022

📤 Output →
01 - Adding one day is : 1/1/2023
02 - Adding 10 days is : 11/1/2023
03 - Adding one week is : 18/1/2023
04 - Adding 10 weeks is : 29/3/2023
05 - Adding one month is : 29/4/2023
06 - Adding 5 months is : 29/9/2023
07 - Adding one year is : 29/9/2024
08 - Adding 10 years is : 29/9/2034
09 - Adding 10 years (faster) is : 29/9/2044
10 - Adding One Decade is : 29/9/2054
11 - Adding 10 Decades is : 29/9/2154
12 - Adding 10 Decades (faster) is : 29/9/2254
13 - Adding One Century is : 29/9/2354
14 - Adding One Millennium is : 29/9/3354
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



sDate IncreaseDateByXDays(sDate Date , short days) {

    for (short i = 1; i <= days; i++) {

        Date = IncreaseDateByOneDay(Date);

    }

    return Date;

}



sDate IncreaseDateByOneWeek(sDate& Date) {

    for (short i = 1; i <= 7 ; i++) {

        Date = IncreaseDateByOneDay(Date);

    }

    return Date;
}




sDate IncreaseDateByXWeeks(sDate Date, int weeks) {

    for (short i = 0; i < weeks; i++) {

        IncreaseDateByOneWeek(Date);

    }

    return Date;
}



sDate IncreaseDateByOneMonth(sDate Date) {

    if (Date.Month == 12) {

        Date.Month = 1;
        Date.Year++;

    }
    else {
        Date.Month++;
    }

    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

    if (Date.Day > NumberOfDaysInCurrentMonth) {

        Date.Day = NumberOfDaysInCurrentMonth;

    }

    return Date;
}



sDate IncreaseDateByXMonths(sDate Date, short months) {

    for (short i = 0; i < months ; i++) {

        Date = IncreaseDateByOneMonth(Date);

    }

    return Date;

}

sDate IncreaseDateByOneYear(sDate Date) {

    Date.Year++;
    return Date;

}



sDate IncreaseDateByXYears(sDate& Date , short years) {

    for (short i = 0; i < years; i++) {

        Date = IncreaseDateByOneYear(Date);

    }

    return Date;

}



sDate IncreaseDateByXYearsFaster(sDate Date , short years) {

    Date.Year += years;

    return Date;
}



sDate IncreaseDateByOneDecade(sDate Date) {

    Date.Year += 10;

    return Date;
}




sDate IncreaseDateByXDecades(sDate Date, short decade) {

    for (short i = 0; i < decade * 10; i++) {

        Date = IncreaseDateByOneYear(Date);

    }

    return Date;
}



sDate IncreaseDateByXDecadesFaster(sDate& Date , short decade) {

    Date.Year += decade * 10;

    return Date;
}



sDate IncreaseDateByOneCentury(sDate Date) {

    Date.Year += 100;

    return Date;
}



sDate IncreaseDateByOneMillennium(sDate Date) {

    Date.Year += 1000;

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

    Date = IncreaseDateByOneDay(Date);
    cout << "01 - Adding one day is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXDays(Date, 10);
    cout << "02 - Adding 10 days is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneWeek(Date);
    cout << "03 - Adding one week is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXWeeks(Date, 10);
    cout << "04 - Adding 10 weeks is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    
    Date = IncreaseDateByOneMonth(Date);
    cout << "05 - Adding one month is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXMonths(Date , 5);
    cout << "06 - Adding 5 months is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneYear(Date);
    cout << "07 - Adding one year is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXYears(Date , 10);
    cout << "08 - Adding 10 years is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXYearsFaster(Date , 10);
    cout << "09 - Adding 10 years (faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneDecade(Date);
    cout << "10 - Adding One Decade is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;


    Date = IncreaseDateByXDecades(Date , 10);
    cout << "11 - Adding 10 Decades is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXDecadesFaster(Date, 10);
    cout << "12 - Adding 10 Decades (faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneCentury(Date );
    cout << "13 - Adding One Century is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneMillennium(Date);
    cout << "14 - Adding One Millennium is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    system("pause>0");
}
