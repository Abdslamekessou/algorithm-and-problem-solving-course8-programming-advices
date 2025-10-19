#include <iostream>
#include <vector>
#include <string>

/*
🧠 Program to check if Date1 is before Date2 using one line of condition.
📅 Example:
   Date1 = 10/5/2023
   Date2 = 12/7/2023
📤 Output → Yes, Date1 is less than Date2
*/

using namespace std;


struct sDate {

    short Day;
    short Month;
    short Year;

};


bool IsDate1BeforeThanDate2(sDate Date1 , sDate Date2 ) {

    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);

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
    cout << "\nDate 1 : " ;
    sDate Date1 = ReadFullDate();

    cout << "\n\nDate 2 : ";
    sDate Date2 = ReadFullDate();
    
    if (IsDate1BeforeThanDate2(Date1 , Date2)) {
        cout << "\nYes , Date1 is less than Date2";
    }
    else {
        cout << "\nNo , Date1 is less than Date2";
    }

    system("pause>0");
}

