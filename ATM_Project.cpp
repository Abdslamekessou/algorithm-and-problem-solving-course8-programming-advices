
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

/*
🏦 ATM System (C++)
A console-based banking system using file storage.

🔹 Features:
1️- Login with Account Number & PIN
2️- Withdraw (Quick / Normal) 💸
3️- Deposit & Check Balance 💰
4️- Data saved in Clients.txt 📂

*/


using namespace std;

const string ClientsFileName = "C:\\Programming Advices\\Course8 C++\\bank3Solution\\Clients.txt";

struct stClient {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

enum enATMMainMenueOption {
    eQuickWithdraw = 1 , eNormalWithdraw = 2 ,
    eDeposit = 3 , eCheckBalance = 4 , eLogout = 5
};

enum enQuickWithdrawMenueOption {
    eWithdraw20 = 1 , eWithdraw50 , eWithdraw100 , eWithdraw200 , eWithdraw400 , 
    eWithdraw600 , eWithdraw800 , eWithdraw1000 , eExit
};

void ShowATMMainMenue();
void GoBackToATMMainMenue();
void Login();
double CheckBalance(stClient Client);


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

string ConvertRecordToLine(stClient Client, string Seperator = "#//#")
{

    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
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

vector <stClient> SaveCleintsDataToFile(string FileName, vector <stClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {
        for (stClient C : vClients)
        {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
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


short ReadQuickWithdrawOption() {

    short choice = 0;

    cout << "\nchoose what to withdraw from [1] to [8]? ";
    cin >> choice;

    return choice;

}

bool IsEnoughMoney(double Amount , double Balance) {
    
    if (Amount <= Balance) {
        return true;
    }
    else {
        cout << "\nThe Amount exceeds your balance , make another choice\n\n";
        return false;
    }

}

void QuickWithdraw(double Amount) {

    vector<stClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    cout << "\nYour Balance is " << CurrentClient.AccountBalance << endl;

    char answer = 'Y';
    cout << "\n\nAre you sure you want to perfrom this transaction ? y/n? \n";
    cin >> answer;

    if (answer == 'Y' || answer == 'y') {

        if (IsEnoughMoney(Amount, CurrentClient.AccountBalance)) {

            
            for (stClient& C : vClients) {

                if (C.AccountNumber == CurrentClient.AccountNumber) {

                    C.AccountBalance -= Amount;
                    CurrentClient.AccountBalance = C.AccountBalance;
                    cout << "\n\nDone Sucessfully . New balance : " << C.AccountBalance << "\n\n";


                    SaveCleintsDataToFile(ClientsFileName, vClients);
                    vClients = LoadCleintsDataFromFile(ClientsFileName);

                    break;

                }

            }



        }
            


    }

}


void PerfromQuickWithdrawMenueOperation(enQuickWithdrawMenueOption QuickWithdrawMenueOption) {
     
    switch (QuickWithdrawMenueOption) {

      case enQuickWithdrawMenueOption::eWithdraw20 :
             QuickWithdraw(20);
             GoBackToATMMainMenue();
             break;

      case enQuickWithdrawMenueOption::eWithdraw50:
          QuickWithdraw(50);
          GoBackToATMMainMenue();
          break;

      case enQuickWithdrawMenueOption::eWithdraw100:
          QuickWithdraw(100);
          GoBackToATMMainMenue();
          break;

      case enQuickWithdrawMenueOption::eWithdraw200:
          QuickWithdraw(200);
          GoBackToATMMainMenue();
          break;
     
      case enQuickWithdrawMenueOption::eWithdraw400:
          QuickWithdraw(400);
          GoBackToATMMainMenue();
          break;

      case enQuickWithdrawMenueOption::eWithdraw600:
          QuickWithdraw(600);
          GoBackToATMMainMenue();
          break;

      case enQuickWithdrawMenueOption::eWithdraw800:
          QuickWithdraw(800);
          GoBackToATMMainMenue();
          break;

      case enQuickWithdrawMenueOption::eWithdraw1000:
          QuickWithdraw(1000);
          GoBackToATMMainMenue();
          break;

      case enQuickWithdrawMenueOption::eExit:
          GoBackToATMMainMenue();
          break;
     }

}


void ShowQuickWithdrawScreen() {

    system("cls");
    cout << "===========================================\n";
    cout << "\t\tQuick Withdraw Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] 20\t\t [2] 50\n";
    cout << "\t[3] 100\t\t [4] 200\n";
    cout << "\t[5] 400\t\t [6] 600\n";
    cout << "\t[7] 800\t\t [8] 1000\n";
    cout << "\t[9] Exit\n";
    cout << "===========================================\n";

    PerfromQuickWithdrawMenueOperation((enQuickWithdrawMenueOption) ReadQuickWithdrawOption());

}


double ReadAmountMultipleOf5() {
     
    double amount;

    cout << "\n\nEnter amount multiple of 5's ? ";
    cin >> amount;

    while ((int)amount % 5 != 0) {

        cout << "\n\nEnter amount multiple of 5's ? ";
        cin >> amount;

    }

    return amount;
}

void NormalWithdraw() {

    double amount = ReadAmountMultipleOf5();

    vector <stClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    cout << "\nYour Balance is " << CurrentClient.AccountBalance << endl;

    char answer = 'Y';
    cout << "\n\nAre you sure you want to perfrom this transaction ? y/n? \n";
    cin >> answer;

    if (answer == 'Y' || answer == 'y') {

      for (stClient &C : vClients) {

          if (C.AccountNumber == CurrentClient.AccountNumber) {

              if (IsEnoughMoney(amount, CurrentClient.AccountBalance)) {

                  C.AccountBalance -= amount;
                  CurrentClient.AccountBalance = C.AccountBalance;
                  cout << "\n\nDone Sucessfully . New balance : " << C.AccountBalance << "\n\n";

                  SaveCleintsDataToFile(ClientsFileName, vClients);
                  /*vClients = LoadCleintsDataFromFile(ClientsFileName);*/

                  break;
              }
         }

      }
      
     
    }

     
}


void ShowNormalWithdrawScreen() {

    system("cls");
    cout << "===========================================\n";
    cout << "\t\tQuick Withdraw Screen\n";
    cout << "===========================================\n";

    NormalWithdraw();

}


double ReadDepositAmount() {

    double amount = 0;

    cout << "\n\nEnter Positive Deposit Amount ? ";
    cin >> amount;

    return amount;

}


void Deposit() {

    double amount = ReadDepositAmount();

    vector <stClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    cout << "\nYour Balance is " << CurrentClient.AccountBalance << endl;

    char answer = 'Y';
    cout << "\n\nAre you sure you want to perfrom this transaction ? y/n? \n";
    cin >> answer;

    if (answer == 'Y' || answer == 'y') {

        for (stClient& C : vClients) {

            if (C.AccountNumber == CurrentClient.AccountNumber){

                    C.AccountBalance += amount;
                    CurrentClient.AccountBalance = C.AccountBalance;
                    cout << "\n\nDone Sucessfully . New balance : " << C.AccountBalance << "\n\n";

                    SaveCleintsDataToFile(ClientsFileName, vClients);
                    /*vClients = LoadCleintsDataFromFile(ClientsFileName);*/

                    break;
                }
            }

        }


    }


void ShowDepositScreen() {

    system("cls");
    cout << "===========================================\n";
    cout << "\t\tDeposit Screen\n";
    cout << "===========================================\n";

    Deposit();

}

double CheckBalance(stClient Client) {

     vector <stClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

     for (stClient& C : vClients) {

         if (C.AccountNumber == Client.AccountNumber) {

              return C.AccountBalance;

         }

     }

}

void ShowCheckBalanceScreen() {
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tCheck Balance Screen\n";
    cout << "===========================================\n";

    cout << "\nYour Balance is : " << CheckBalance(CurrentClient) <<"\n\n";
}


void GoBackToATMMainMenue() {

   cout << "\n\nPress any key to go back to main menue...";

   system("pause>0");

   ShowATMMainMenue();

}

short ReadATMMainMenueOption() {

    short choice = 0;

    cout << "\nchoose what do you want to do ? [1 to 5]? ";
    cin >> choice;

    return choice;

}


void PerfromATMMainMenueOperation(enATMMainMenueOption ATMMainMenueOption) {

    switch (ATMMainMenueOption) {
       
       case enATMMainMenueOption::eQuickWithdraw:
           ShowQuickWithdrawScreen();
           GoBackToATMMainMenue();
           break;

       case enATMMainMenueOption::eNormalWithdraw:
           ShowNormalWithdrawScreen();
           GoBackToATMMainMenue();
           break;

       case enATMMainMenueOption::eDeposit:
           ShowDepositScreen();
           GoBackToATMMainMenue();
           break;

       case enATMMainMenueOption::eCheckBalance:
           ShowCheckBalanceScreen();
           GoBackToATMMainMenue();
           break;

       case enATMMainMenueOption::eLogout:
           Login();
           break;

    }

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

    PerfromATMMainMenueOperation((enATMMainMenueOption)ReadATMMainMenueOption());
}


void Login() {

    bool LoginFailed = false;
    string AccountNumber , PinCode;

    do {
        system("cls");
        cout << "\n-----------------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n-----------------------------------\n";

        if (LoginFailed) {
            cout << "\nInvalid Account Number / Pin Code!\n";
        }

        
        cout<<"\nEnter Account Number? ";
        cin >> AccountNumber;


        
        cout << "\nEnter Pin Code? ";
        cin >> PinCode;

        LoginFailed = !LoadClient(AccountNumber , PinCode , CurrentClient);


    }while(LoginFailed);

    ShowATMMainMenue();
    
}


int main()
{
    Login();
}

