
#include <iostream>

using namespace std;


/*
🧠 Program to check if a given date falls within a specific period.
📅 Example:
   Input →
      Period: Start = 1/1/2025 , End = 31/1/2025
      Date = 15/1/2025
📤 Output →
      Yes , Date is within Period
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


bool IsDateInPeriod(sDate Date, stPeriod Period) {

    return !(CompareDates(Date, Period.StartDate) == enDateCompare::eBefore 
        
             ||

             CompareDates(Date, Period.EndDate) == enDateCompare::eAfter
        );
}



int main()
{
    stPeriod Period;
    cout << "Enter Period :";
    Period = ReadPeriod();

    sDate Date;
    cout << "\nEnter Date :";
    Date = ReadFullDate();

    if (IsDateInPeriod(Date, Period)) {
        cout << "\nYes , Date is within Period";
    }
    else {
        cout << "\nNo , Date is NOT within Period";
    }


    system("pause>0");

}








