
#include <iostream>
#include <string>
#include <vector>

/* 📅 Program: Convert date between string and structure formats.

   💡 Example :

    Please enter Date dd/mm/yy? 28/10/2025 

    Day : 28 
    Month : 10 
    Year : 2025 
    
    You Entred : 28/10/2025
   
   */

using namespace std;


struct stDate {

    short Day;
    short Month;
    short Year;

};


vector <string> SplitString(string Line, string Seperator) {

    vector <string> vString;
    string sWord;
    short pos = 0;

    while ((pos = Line.find(Seperator)) != string::npos) {

        sWord = Line.substr(0, pos);

        if (sWord != "") {

            vString.push_back(sWord);

        }

        Line.erase(0, pos + Seperator.length());

    }

    if (Line != "") {

        vString.push_back(Line);

    }

    return vString;

}


stDate StringToDate(string DateString) {

    stDate sDate;
    vector <string> vDate;

    vDate = SplitString(DateString, "/");
    
    sDate.Day = stoi(vDate[0]);
    sDate.Month = stoi(vDate[1]);
    sDate.Year = stoi(vDate[2]);

    return sDate;
}


string DateToString(stDate Date) {

    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);

}


string ReadStringDate() {

    string Date;

    cout << "\nPlease enter Date dd/mm/yy? ";
    getline(cin >> ws ,  Date);

    return Date;
}




int main()
{
    string DateString = ReadStringDate();

    stDate sDate = StringToDate(DateString);

    cout << "\nDay : " << sDate.Day << "\n";
    cout << "Month : " << sDate.Month << "\n";
    cout << "Year : " << sDate.Year << "\n\n";


    cout << "You Entred : " << DateToString(sDate) ;

    system("pause>0");
}


