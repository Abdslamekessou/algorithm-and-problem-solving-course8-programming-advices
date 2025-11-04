
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string ClientsFileName = "C:\\Programming Advices\\Course8 C++\\bank3Solution\\Clients.txt";

struct stClient {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

enum ATMMainMenueOption {
    e
};

stClient CurrentClient;

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord;


    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());
    }

    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;

}

stClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
    stClient Client;
    vector<string> vClientData;
    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]); //cast string to double
    return Client;
}

vector <stClient> LoadCleintsDataFromFile(string FileName)
{
    vector <stClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {
        string Line;
        stClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}


bool FindClientByAccountNumberAndPinCode(string AccountNumber , string PinCode , stClient &Client) {

     vector<stClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

     for (stClient &C : vClients ) {
         
         if (C.AccountNumber == AccountNumber && C.PinCode == PinCode) {

             Client = C;
             return true;
         }

     }

     return false;

}


bool LoadClient(string AccountNumber, string PinCode, stClient& Client) {

    if (FindClientByAccountNumberAndPinCode(AccountNumber , PinCode , Client)) {
           return true;
    }
    else {
        return false;
    }

}


short ReadATMMainMenueOption() {

    short choice = 0;

    cout << "\nchoose what do you want to do ? [1 to 5]? ";
    cin >> choice;

    return choice;

}



void ShowATMMainMenue() {

    system("cls");
    cout << "===========================================\n";
    cout << "\t\tATM Main Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Quick Withdraw.\n";
    cout << "\t[2] Normal Withdraw.\n";
    cout << "\t[3] Deposit.\n";
    cout << "\t[4] Check Balance.\n";
    cout << "\t[5] Logout.\n";
    cout << "===========================================\n";
}


void Login() {

    bool LoginFailed = false;

    do {
        system("cls");
        cout << "\n-----------------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n-----------------------------------\n";

        if (LoginFailed) {
            cout << "\nInvalid Account Number / Pin Code!\n";
        }

        string AccountNumber;
        cout<<"\nEnter Account Number? ";
        cin >> AccountNumber;


        string PinCode;
        cout << "\nEnter Pin Code? ";
        cin >> PinCode;

        LoginFailed = !LoadClient(AccountNumber , PinCode , CurrentClient);


    }while(LoginFailed);

    system("cls");
    cout << "ATM Menue";
}


int main()
{
    Login();
}

