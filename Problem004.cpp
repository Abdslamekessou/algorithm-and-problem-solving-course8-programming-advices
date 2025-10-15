
#include <iostream>
using namespace std;

/*
🌟 Program: Year Time Calculator
🧠 Goal: Calculate days, hours, minutes, and seconds in a given year.
📘 Rule: Leap year → 366 days, otherwise → 365 days.
📥 Input: Enter a Year to check?
📤 Output:
     Number of     Days in Year [2024] is 366
     Number of    Hours in Year [2024] is 8784
     Number of  Minutes in Year [2024] is 527040
     Number of Secondes in Year [2024] is 31622400
*/



short IsLeapYear(short year) {

    return  (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? true : false;

}


short NumberOfDaysInAYear(short year) {
    
    return IsLeapYear(year) ? 366 : 365;

}


short NumberOfHoursInAYear(short year) {

    return NumberOfDaysInAYear(year) * 24;

}


int NumberOfMinutesInAYear(short year) {

    return NumberOfHoursInAYear(year) * 60;

}


int NumberOfSecondesInAYear(int year) {

    return NumberOfMinutesInAYear(year) * 60;

}



short ReadYear() {

    short Year;

    cout << "\nEnter a Year to check? ";
    cin >> Year;

    return Year;
}



int main()
{
    short year = ReadYear();

    cout << "\nNumber of     Days in Year [" << year << "] is " << NumberOfDaysInAYear(year) << endl;
    cout << "\nNumber of    Hours in Year [" << year << "] is " << NumberOfHoursInAYear(year) << endl;
    cout << "\nNumber of  Minutes in Year [" << year << "] is " << NumberOfMinutesInAYear(year) << endl;
    cout << "\nNumber of Secondes in Year [" << year << "] is " << NumberOfSecondesInAYear(year) << endl;


}





