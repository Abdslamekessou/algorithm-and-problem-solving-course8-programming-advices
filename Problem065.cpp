
#include <iostream>
#include <string>
#include <vector>

/* 📅 Program: Date Formatter
   💻 Input: string date in format dd/mm/yyyy
   🔄 Output: same date in multiple formats
   🧩 Example: 
   
   Please enter Date dd/mm/yy? 28/10/2025

    28/10/2025

    2025/28/10

    10/28/2025

    10-28-2025

    28-10-2025

    Day:28, Month:10, Year:2025
   
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



string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo) {

    short pos = S1.find(StringToReplace);
    
    while (pos != std::string::npos) {

        S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);         
        pos = S1.find(StringToReplace);//find next   

    } 
    return S1; 
}



string FormatDate(stDate Date , string DateFormat = "dd/mm/yyyy") {

    string FormatedDateString = "";

    FormatedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));

    FormatedDateString = ReplaceWordInString(FormatedDateString, "mm", to_string(Date.Month));

    FormatedDateString = ReplaceWordInString(FormatedDateString , "yyyy", to_string(Date.Year));

    return FormatedDateString;

}



string ReadStringDate() {

    string Date;

    cout << "\nPlease enter Date dd/mm/yy? ";
    getline(cin >> ws, Date);

    return Date;
}




int main()
{
    string DateString = ReadStringDate();

    stDate Date = StringToDate(DateString);

    cout <<"\n"  << FormatDate(Date , "dd/mm/yyyy") << "\n";

    cout << "\n" << FormatDate(Date, "yyyy/dd/mm") << "\n";

    cout << "\n" << FormatDate(Date, "mm/dd/yyyy") << "\n";

    cout << "\n" << FormatDate(Date, "mm-dd-yyyy") << "\n";

    cout << "\n" << FormatDate(Date, "dd-mm-yyyy") << "\n";

    cout << "\n" << FormatDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";
    

    system("pause>0");
}
