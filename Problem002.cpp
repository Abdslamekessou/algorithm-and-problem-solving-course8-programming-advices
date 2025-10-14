
#include <iostream>
using namespace std;

/*  
🧠 Program to check if a given year is a leap year.  
📘 Rule: Divisible by 400, or by 4 but not by 100.  
📥 Input: A year entered by the user.  
📤 Output: Displays if the year is leap or not.  
✨ Example: 2024 → Leap year, 1900 → Not leap year.  
*/  


bool IsLeapYear(short year) {

    if (year % 400 == 0) {

        return true;

    }
    else if (year % 100 == 0) {

        return false;

    }
    else if (year % 4 == 0) {

        return true;

    }
    else {
        return false;
    }

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





