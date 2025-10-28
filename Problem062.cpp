
#include <iostream>

using namespace std;

/* 📅 Program: Validate if a given date is correct or not.
* 
   💡 Example: Input → 29/2/2024 ✅ Valid (Leap Year)
               Output → "Yes, Date is valid."

   💡 Example: Input → 31/4/2023 ❌ Invalid (April has 30 days)
               Output → "No, Date is NOT valid."
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

    return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : numberOfDays[month - 1]; // one line of condition

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



bool IsValidDate(sDate Date) {

    if (Date.Day < 1 || Date.Day > 31)
        return false;

    if (Date.Month < 1 || Date.Month > 12)
        return false;


    if (Date.Month == 2) {
       
        if (IsLeapYear(Date.Year)) {

            if (Date.Day > 29)
                return false;

        }
        else {

            if (Date.Day > 28)
                return false;

        }

    }

    int DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

    if (Date.Day > DaysInMonth)
        return false;
 

    return true;
    

}



int main()
{
    sDate Date = ReadFullDate();

    if (IsValidDate(Date)) {
        cout << "\nYes , Date is valide date.";
    }
    else {
        cout << "\nNo , Date is a NOT valide date.";
    }

    system("pause>0");
}

