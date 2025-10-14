
#include <iostream>
using namespace std;

/*
🌟 Program: Leap Year Checker using Ternary Operator
📘 Rule: (Divisible by 4 and not by 100) OR divisible by 400 → Leap Year.
📥 Input: User enters a year to check.
📤 Output: Prints if the year is leap or not.
✨ Example: 2020 → Leap year, 1900 → Not leap year.
*/


bool IsLeapYear(short year) {

    return  (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? true : false;

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

    if (IsLeapYear(year)) {
        cout << "\nYes , Year [" << year << "] is a leap year" << endl;
    }
    else {
        cout << "\nNo , Year [" << year << "] is not a leap year" << endl;
    }

}



