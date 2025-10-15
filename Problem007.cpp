
#include <iostream>
using namespace std;


/*
🧠 Program to find the day of the week for a given date.
📘 Formula: Uses Zeller’s Congruence to calculate the day order (0–6).
📥 Input: Day, Month, and Year entered by the user.
📤 Output Example:
     Date         :  15/10/2024
     Day Order    :  2
     Day Name     :  Tue
*/



short DayOfWeekOrder(short day , short month , short year) {

    short a , y , m;

    a = (14 - month) / 12;

    y = year - a;

    m = month + 12 * a - 2;
    
     return (day + y + (y / 4) - (y / 100) + (y / 400) +  ( (31 * m) / 12) ) % 7;

}



string DayShortName(short DayOfWeekOrder) {

    string arrDaysNames[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

    return arrDaysNames[DayOfWeekOrder];
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

    cout << "\nPlease enter a day ? ";
    cin >> day;

    return day;
}




int main()
{
    short year = ReadYear();
    short month = ReadMonth();
    short day = ReadDay();

    cout << "\n\nDate         :  " << day << "/" << month << "/" << year << "\n";
    cout << "\nDay Order    :  " << DayOfWeekOrder(day , month , year) << "\n";
    cout << "\nDay Name     :  " << DayShortName(DayOfWeekOrder(day, month, year)) << "\n";

}





