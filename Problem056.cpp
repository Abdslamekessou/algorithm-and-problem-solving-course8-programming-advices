
#include <iostream>

using namespace std;

/*
🧠 Program to compare two dates and determine if the first date is after the second date.

📅 The program reads two full dates (day, month, year) from the user and compares them.

🧩 Example:
   Input →
       Date1 : 1/1/2025
       Date2 : 1/1/2000

📤 Output →
       Yes, Date1 is After Date2
*/



struct sDate {

    short Day;
    short Month;
    short Year;

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



int main()
{
    cout << "Enter Date1 : ";
    sDate Date1 = ReadFullDate();
   
    cout << "\n\nEnter Date2 : ";
    sDate Date2 = ReadFullDate();

    if (IsDate1AfterDate2(Date1, Date2)) {
        cout << "\nYes , Date1 is After Date2";
    }
    else {
        cout << "\nNo , Date1 is NOT After Date2";
    }

    system("pause>0");

}


