
#include <iostream>
using namespace std;


bool IsLeapYear(int year) {

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


int ReadYear() {

    int Year;

    cout << "\nEnter a Year to check? ";
    cin >> Year;

    return Year;
}


int main()
{
    int year = ReadYear();

    if (IsLeapYear(year)) {
        cout << "\nYes , Year [" << year << "] is a leap year" << endl;
    }
    else {
        cout << "\nNo , Year [" << year << "] is not a leap year" << endl;
    }

}


