
#include <iostream>

using namespace std;

/*
🧠 Program to compare two dates and determine if Date1 is before, equal to, or after Date2.

📅 The program reads two full dates (day, month, year) from the user
    and returns one of the following results:
       -1 → Date1 is before Date2
        0 → Date1 is equal to Date2
        1 → Date1 is after Date2

🧩 Example:
       Date1 = 10/3/2023
       Date2 = 25/3/2023
       ➜ Compare Result = -1  (Date1 is Before Date2)

*/




struct sDate {

    short Day;
    short Month;
    short Year;

};


enum enDateCompare {
     eBefore = - 1 ,
     eEqual = 0 ,
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

    if(IsDate1EqualsDate2(Date1, Date2))
        return enDateCompare::eEqual;


        return enDateCompare::eAfter;

}



int main()
{
    cout << "Enter Date1 : ";
    sDate Date1 = ReadFullDate();

    cout << "\n\nEnter Date2 : ";
    sDate Date2 = ReadFullDate();


    cout << "\nCompare Result = " << CompareDates(Date1, Date2);

    system("pause>0");

}


