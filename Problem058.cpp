
#include <iostream>

using namespace std;


/*
🧠 Program to check if two given date periods overlap.
📅 Example:
   Period 1 → 1/1/2025 to 10/1/2025
   Period 2 → 5/1/2025 to 15/1/2025
📤 Output → Yes, Periods Overlap
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



bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2) {
    
    if (
        CompareDates(Period2.EndDate , Period1.StartDate) == enDateCompare::eBefore ||
        CompareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::eAfter
       ) {
        return false;
     }

    return true;
}



int main()
{
    stPeriod Period1;
    stPeriod Period2;


    cout << "Enter Period 1 :";
    Period1 = ReadPeriod();

    cout << "\n\nEnter Period 2 :";
    Period2 = ReadPeriod();

    if (IsOverlapPeriods(Period1, Period2)) {
        cout << "\nYes , Periods Overlap\n";
    }
    else {
        cout << "\nNo , Periods do not Overlap\n";
    }


    system("pause>0");

}



