#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>




using namespace std;

const string ClientsFileName = "C:\\Programming Advices\\Course8 C++\\bank3\\Clients.txt";
const string UsersFileName = "C:\\Programming Advices\\Course8 C++\\bank3\\Users.txt";


void ShowMainMenu();
void ShowTransactionsMenu();
void ShowLoginScreen();
void ShowManageUsersMenu();

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

struct sUser {

    string UserName;
    string Password;
    short  Permissions;
    bool MarkForDelete = false;
};


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


sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
    sClient Client;
    vector<string> vClientData;
    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]); //cast string to double
    return Client;
}


string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{

    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}


bool ClientExistsByAccountNumber(string AccountNumber, string FileName) {

    fstream MyFile;

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open()) {

        string line;
        sClient Client;

        while (getline(MyFile, line)) {

            Client = ConvertLinetoRecord(line);

            if (Client.AccountNumber == AccountNumber) {

                MyFile.close();

                return true;

            }
        }

        MyFile.close();

    }

    return false;

}

sClient ReadNewClient() {

    sClient Client;

    cout << "Enter Account Number? ";
    getline(cin >> ws, Client.AccountNumber);

    while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName)) {

        cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
        getline(cin >> ws, Client.AccountNumber);

    }

    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;

}



vector <sClient> LoadCleintsDataFromFile(string FileName)
{
    vector <sClient> vClients;
    fstream MyFile;

    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {
        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            vClients.push_back(Client);
        }

        MyFile.close();
    }

    return vClients;

}


void PrintClientRecordLine(sClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}


void ShowAllClientsScreen()
{
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0) {

        cout << "\t\t\t\tNo Clients Available In the System!";

    }
    else {

        for (sClient &Client : vClients)
        {

            PrintClientRecordLine(Client);
            cout << endl;
        }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
}


void PrintClientCard(sClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "-----------------------------------";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code     : " << Client.PinCode;
    cout << "\nName         : " << Client.Name;
    cout << "\nPhone        : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    cout << "\n-----------------------------------\n";
}

bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClients, sClient& Client)
{
    for (sClient &C : vClients)
    {

        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }

    }
    return false;
}


sClient ChangeClientRecord(string AccountNumber)
{
    sClient Client;

    Client.AccountNumber = AccountNumber;

    cout << "\n\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;
}


bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{

    for (sClient& C : vClients)
    {

        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }

    }

    return false;
}


vector <sClient> SaveCleintsDataToFile(string FileName, vector <sClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {
        for (sClient &C : vClients)
        {

            if (C.MarkForDelete == false)
            {
                //we only write records that are not marked for delete.  
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }

        }

        MyFile.close();
    }

    return vClients;
}

void AddDataLineToFile(string FileName, string stDataLine) {

    fstream MyFile;

    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open()) {

        MyFile << stDataLine << endl;

        MyFile.close();
    }

}

void AddNewClient() {

    sClient Client;
    Client = ReadNewClient();
    AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));

}

void AddNewClients() {

    char AddMore = 'Y';

    do {

        cout << "\nAdding New Client:\n\n";

        AddNewClient();

        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');

}

bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClients) {

    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {

        PrintClientCard(Client);

        cout << "\n\nAre you sure you want delete this client? y/n ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {

            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);

            SaveCleintsDataToFile(ClientsFileName, vClients);

            vClients = LoadCleintsDataFromFile(ClientsFileName);

            cout << "\n\nClient Deleted Successfully.";
            return true;

        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }

}


bool UpdateClientByAccountNumber(string AccountNumber, vector <sClient>& vClients) {

    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {

        PrintClientCard(Client);

        cout << "\n\nAre you sure you want update this client? y/n ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {

            for (sClient& C : vClients) {

                if (C.AccountNumber == AccountNumber) {

                    C = ChangeClientRecord(AccountNumber);
                    break;
                }

            }

            SaveCleintsDataToFile(ClientsFileName, vClients);

            cout << "\n\nClient Updated Successfully.";
            return true;

        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }

}


string ReadClientAccountNumber()
{
    string AccountNumber = "";

    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;

}


void ShowDeleteClientScreen() {

    cout << "\n-----------------------------------\n";
    cout << "\tDelete Client Screen";
    cout << "\n-----------------------------------\n";

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vClients);
}


void ShowUpdateClientScreen() {

    cout << "\n-----------------------------------\n";
    cout << "\tUpdate Client Screen";
    cout << "\n-----------------------------------\n";

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClients);
}


void ShowAddNewClientsScreen() {

    cout << "\n-----------------------------------\n";
    cout << "\tAdd New Clients Screen";
    cout << "\n-----------------------------------\n";

    AddNewClients();
}

void ShowFindClientScreen() {

    cout << "\n-----------------------------------\n";
    cout << "\tFind Client Screen";
    cout << "\n-----------------------------------\n";

    sClient Client;
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();

    if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {

        PrintClientCard(Client);

    }
    else {
        cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";
    }

}


void ShowEndScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tProgram Ends :-)";
    cout << "\n-----------------------------------\n";
}

enum enMainMenueOptions
{
    eListClients = 1, eAddNewClient = 2,
    eDeleteClient = 3, eUpdateClient = 4,
    eFindClient = 5, eShowTransactionsMenu = 6, 
    eShowManageUsersScreen = 7 , eLogout = 8
};

enum enTransactionsOptions {
    eDeposit = 1,
    eWithdraw = 2,
    eShowTotalBalance = 3,
    eShowMainMenu = 4

};

enum enManageUsersMenuOptions
{
    eListUsers = 1, eAddNewUser = 2,
    eDeleteUser = 3, eUpdateUser = 4,
    eFindUser = 5, eGoBackToMainMenu = 6,
    
};

short ReadMainMenueOption()
{
    cout << "Choose what do you want to do? [1 to 8]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}

void GoBackToMainMenue() {

    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    ShowMainMenu();

}

void GoBackToTransactionsMenu() {

    cout << "\n\nDo you want to go back to Transactions Menu...\n";
    system("pause>0");
    ShowTransactionsMenu();

}

short ReadTransactionsMenuOption() {

    cout << "\n\nChoose what do you want to do? [1 to 4]? ";

    short Choice = 0;
    cin >> Choice;

    return Choice;
}



bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector <sClient>& vClients) {

    char Answer = 'n';

    cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
    cin >> Answer;

    if (Answer == 'Y' || Answer == 'y') {

        for (sClient& C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += Amount;
                SaveCleintsDataToFile(ClientsFileName, vClients);
                cout << "\n\nDone Succesfully . New Balance is : " << C.AccountBalance;
                return true;
            }

        }

        return false;

    }

}


void ShowDepositScreen() {

    system("cls");

    cout << "===========================================\n";
    cout << "\tDeposit Screen\n";
    cout << "===========================================\n";

    sClient Client;

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();

    while (!FindClientByAccountNumber(AccountNumber, vClients, Client)) {

        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = ReadClientAccountNumber();

    }

    PrintClientCard(Client);

    double Amount = 0;
    cout << "\nPlease enter deposit amount? ";
    cin >> Amount;


    DepositBalanceToClientByAccountNumber(AccountNumber, Amount, vClients);

}


void ShowWidthrawScreen() {

    system("cls");

    cout << "===========================================\n";
    cout << "\tWidthraw Screen\n";
    cout << "===========================================\n";

    sClient Client;

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();

    while (!FindClientByAccountNumber(AccountNumber, vClients, Client)) {

        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = ReadClientAccountNumber();

    }

    PrintClientCard(Client);

    double Amount = 0;
    cout << "\nPlease enter deposit amount? ";
    cin >> Amount;

    while (Amount > Client.AccountBalance) {
        cout << "\nAmount Exceeds the balance , you can withdraw up to : " << Client.AccountBalance;
        cout << "\n\nPlease enter another amount? ";
        cin >> Amount;
    }


    DepositBalanceToClientByAccountNumber(AccountNumber, Amount * -1, vClients);
}

void PrintClientRecordBalanceLine(sClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void ShowTotalBalances() {

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    double TotalBalances = 0;

    if (vClients.size() == 0) {

        cout << "\t\t\t\tNo Clients Available In the System!";

    }
    else {

        for (sClient &Client : vClients)
        {

            PrintClientRecordBalanceLine(Client);
            cout << endl;

            TotalBalances += Client.AccountBalance;
        }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "\t\t\t\t Total Balances = " << TotalBalances << endl;
    }

}



void ShowTotalBalanceScreen() {

    system("cls");

    ShowTotalBalances();


}

void PerformTransactionMenuOption(enTransactionsOptions TransactionsOptions) {

    switch (TransactionsOptions) {

    case enTransactionsOptions::eDeposit:
        ShowDepositScreen();
        GoBackToTransactionsMenu();
        break;

    case enTransactionsOptions::eWithdraw:
        ShowWidthrawScreen();
        GoBackToTransactionsMenu();
        break;

    case enTransactionsOptions::eShowTotalBalance:
        ShowTotalBalanceScreen();
        GoBackToTransactionsMenu();
        break;

    case enTransactionsOptions::eShowMainMenu:
        GoBackToMainMenue();
        break;

    }

}

void ShowTransactionsMenu() {

    system("cls");
    cout << "===========================================\n";
    cout << "\tTransactions Menu Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Deposit.\n";
    cout << "\t[2] Widthraw.\n";
    cout << "\t[3] Total Balances.\n";
    cout << "\t[4] Main Menu.\n";

    PerformTransactionMenuOption((enTransactionsOptions)ReadTransactionsMenuOption());
}





string ReadUsername() {

    string Username;

    cout << "\nEnter User Name? ";
    getline(cin >> ws, Username);

    return Username;

}


string ReadPassword() {

    string Password;

    cout << "\nEnter Password? ";
    getline(cin >> ws , Password);

    return Password;

}

bool GiveUserFullAccess(sUser &User) {

    
    char answer = 'y';

    cout << "\nDo you want to give full access for this user?y\\n?\n";
    cin >> answer;

    if (answer == 'y' || answer == 'Y') {
       User.Permissions = -1;
       return true;
    }
    
    return false;

}



short GiveUserPermissions() {

    char answer = 'y';
    short Permissions = 0;

    cout << "\nShow Client List?y/n?\n";
    cin >> answer;

    if (answer == 'y' || answer == 'Y') {
        Permissions = (Permissions | 1);
    }


    cout << "\nAdd New Client?y/n?\n";
    cin >> answer;

    if (answer == 'y' || answer == 'Y') {
        Permissions = (Permissions | 2);
    }


    cout << "\nDelete Client?y/n?\n";
    cin >> answer;

    if (answer == 'y' || answer == 'Y') {
        Permissions = (Permissions | 4);
    }

    cout << "\nUpdate Client?y/n?\n";
    cin >> answer;

    if (answer == 'y' || answer == 'Y') {
        Permissions = (Permissions | 8);
    }


    cout << "\nFind Client?y/n?\n";
    cin >> answer;

    if (answer == 'y' || answer == 'Y') {
        Permissions = (Permissions | 16);
    }


    cout << "\nTransactions?y/n?\n";
    cin >> answer;

    if (answer == 'y' || answer == 'Y') {
        Permissions = (Permissions | 32);
    }


    cout << "\nManage Users?y/n?\n";
    cin >> answer;

    if (answer == 'y' || answer == 'Y') {
        Permissions = (Permissions | 64);
    }

    return Permissions;
}



sUser ConvertLinetoUserRecord(string Line, string Seperator = "#//#")
{
    sUser User;
    vector<string> vUserData;
    vUserData = SplitString(Line, Seperator);

    User.UserName = vUserData[0];
    User.Password = vUserData[1];
    User.Permissions = stoi(vUserData[2]);

    return User;
}

string ConvertRecordToLine(sUser User, string Seperator = "#//#")
{

    string stUserRecord = "";
    stUserRecord += User.UserName + Seperator;
    stUserRecord += User.Password + Seperator;
    stUserRecord += to_string(User.Permissions);
 
    return stUserRecord;
}


vector <sUser> LoadUsersDataFromFile(string FileName)
{
    vector <sUser> vUsers;
    fstream MyFile;

    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {
        string Line;
        sUser User;

        while (getline(MyFile, Line))
        {
            User = ConvertLinetoUserRecord(Line);
            vUsers.push_back(User);
        }

        MyFile.close();
    }

    return vUsers;

}

vector <sUser> SaveUsersDataToFile(string FileName, vector <sUser> vUsers)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {
        for (sUser & U : vUsers)
        {

            if (U.MarkForDelete == false)
            {
                //we only write records that are not marked for delete.  
                DataLine = ConvertRecordToLine(U);
                MyFile << DataLine << endl;
            }

        }

        MyFile.close();
    }

    return vUsers;
}

bool UserExistsByUserName(string UserName, string FileName) {

    fstream MyFile;

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open()) {

        string line;
        sUser User;

        while (getline(MyFile, line)) {

            User = ConvertLinetoUserRecord(line);

            if (User.UserName == UserName) {

                MyFile.close();

                return true;

            }
        }

        MyFile.close();

    }

    return false;

}

bool FindUserByUserName(string UserName, vector <sUser> vUsers, sUser& User)
{
    for (sUser &U : vUsers)
    {

        if (U.UserName == UserName)
        {
            User = U;
            return true;
        }

    }
    return false;
}

void GoBackToManageUsersMenu() {

    cout << "\n\nPress any key to go back to Manage Users Menu...";
    system("pause>0");
    ShowManageUsersMenu();

}

short ReadManageUsersOption()
{
    cout << "Choose what do you want to do? [1 to 6]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}


void PrintUserRecordLine(sUser User)
{
    cout << "| " << setw(15) << left << User.UserName;
    cout << "| " << setw(40) << left << User.Password;
    cout << "| " << setw(15) << left << User.Permissions;

}

void PrintUserCard(sUser User)
{
    cout << "\nThe following are the client details:\n";
    cout << "-----------------------------------";
    cout << "\nUsername     : " << User.UserName;
    cout << "\nPassword     : " << User.Password;
    cout << "\nPermissions  : " << to_string(User.Permissions);
    cout << "\n-----------------------------------\n";
}


void ShowAllUsersScreen()
{
    vector <sUser> vUsers = LoadUsersDataFromFile(UsersFileName);

    cout << "\n\t\t\t\t\tUser List (" << vUsers.size() << ") User(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Username";
    cout << "| " << left << setw(40) << "Password";
    cout << "| " << left << setw(15) << "Permissions";

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vUsers.size() == 0) {

        cout << "\t\t\t\tNo Users Available In the System!";

    }
    else {

        for (sUser& User : vUsers)
        {

            PrintUserRecordLine(User);
            cout << endl;
        }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
}

void AddNewUser() {

    sUser User;
    vector <sUser> vUsers = LoadUsersDataFromFile(UsersFileName);
    char answer = 'y';

    while (answer == 'y' || answer == 'Y') {

        User.UserName = ReadUsername();
        User.Password = ReadPassword();

        while (UserExistsByUserName(User.UserName, UsersFileName)) {

            cout << "\nUser With Username [" << User.UserName << "] already exists\n";
            User.UserName = ReadUsername();
            User.Password = ReadPassword();

        }


        if (!GiveUserFullAccess(User)) {

            short Permissions = GiveUserPermissions();
            User.Permissions = Permissions;

        }

        vUsers.push_back(User);

        SaveUsersDataToFile(UsersFileName, vUsers);

        cout << "\nUser Added Successfully , do you want to add more users?y/n?\n";
        cin >> answer;
    }

}

void AddNewUserScreen() {

    system("cls");
    cout << "===========================================\n";
    cout << "\t\tAdd New User Screen\n";
    cout << "===========================================\n";

    AddNewUser();
  
}


void DeleteUser() {

    sUser User;
    vector <sUser> vUsers = LoadUsersDataFromFile(UsersFileName);

    User.UserName = ReadUsername();
    User.Password = ReadPassword();

    if (User.UserName == "Admin") {
        cout << "\nAdmin cannot be deleted";
        return;
    }

    if(!UserExistsByUserName(User.UserName, UsersFileName)) {

        cout << "\nUser With Username [" << User.UserName << "] is Not Found!\n";

    }

    FindUserByUserName(User.UserName, vUsers, User);

    PrintUserCard(User);

    char answer = 'y';

    cout << "\nAre you sure you want to delete this user? y/n? \n";
    cin >> answer;

    if (answer == 'y' || answer == 'Y') {

        for (sUser & U : vUsers) {

            if (U.UserName == User.UserName) {

                U.MarkForDelete = true;
                break;
            }

        }

    }


    SaveUsersDataToFile(UsersFileName, vUsers);

    cout << "\nUser deleted succesfully\n";

}

void DeleteUserScreen() {

    system("cls");
    cout << "===========================================\n";
    cout << "\t\tDelete User Screen\n";
    cout << "===========================================\n";

    DeleteUser();

}

void UpdateUser() {

    sUser User;
    vector <sUser> vUsers = LoadUsersDataFromFile(UsersFileName);

    User.UserName = ReadUsername();


    if (!UserExistsByUserName(User.UserName, UsersFileName)) {

        cout << "\nUser With Username [" << User.UserName << "] is Not Found!\n";

        return;

    }


    FindUserByUserName(User.UserName, vUsers, User);

    PrintUserCard(User);


    char answer = 'y';

    cout << "\nAre you sure you want to update this user? y/n? \n";
    cin >> answer;

    if (answer == 'y' || answer == 'Y') {

        for (sUser& U : vUsers) {

            if (U.UserName == User.UserName) {

                U.Password = ReadPassword();
               
                if (!GiveUserFullAccess(User)) {

                    short Permissions = GiveUserPermissions();
                    U.Permissions = Permissions;


                }
                else {
                    U.Permissions = -1;
                }


            }

        }

    }


    SaveUsersDataToFile(UsersFileName, vUsers);

    cout << "\nUser updated succesfully\n";



}

void UpdateUserScreen() {

    system("cls");
    cout << "===========================================\n";
    cout << "\t\tUpdate User Screen\n";
    cout << "===========================================\n";

    UpdateUser();
}

void FindClient() {

    sUser User;
    vector <sUser> vUsers = LoadUsersDataFromFile(UsersFileName);

    User.UserName = ReadUsername();


    if (!UserExistsByUserName(User.UserName, UsersFileName)) {

        cout << "\nUser With Username [" << User.UserName << "] is Not Found!\n";

        return;

    }

    FindUserByUserName(User.UserName, vUsers, User);

    PrintUserCard(User);


}

void FindClientScreen() {

    system("cls");
    cout << "===========================================\n";
    cout << "\t\tFind User Screen\n";
    cout << "===========================================\n";

    FindClient();
}


void PerfromManageUsersMenuOperation(enManageUsersMenuOptions ManageUsersMenuOption) {

    switch (ManageUsersMenuOption) {

    case enManageUsersMenuOptions::eListUsers:
        system("cls");
        ShowAllUsersScreen();
        GoBackToManageUsersMenu();
        break;

    case enManageUsersMenuOptions::eAddNewUser:
        system("cls");
        AddNewUserScreen();
        GoBackToManageUsersMenu();
        break;
     
    case enManageUsersMenuOptions::eDeleteUser:
        system("cls");
        DeleteUserScreen();
        GoBackToManageUsersMenu();
        break;

    case enManageUsersMenuOptions::eUpdateUser:
        system("cls");
        UpdateUserScreen();
        GoBackToManageUsersMenu();
        break;

    case enManageUsersMenuOptions::eFindUser:
        system("cls");
        FindClientScreen();
        GoBackToManageUsersMenu();
        break;

    case enManageUsersMenuOptions::eGoBackToMainMenu:
        ShowMainMenu();
        break;

    }

}



void ShowManageUsersMenu() {

    system("cls");
    cout << "===========================================\n";
    cout << "\t\tManage Users Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Show Users List.\n";
    cout << "\t[2] Add New User.\n";
    cout << "\t[3] Delete User.\n";
    cout << "\t[4] Update User.\n";
    cout << "\t[5] Find User.\n";
    cout << "\t[6] Main Menu.\n";
    cout << "===========================================\n";

    PerfromManageUsersMenuOperation((enManageUsersMenuOptions)ReadManageUsersOption());
}




void Login() {

    vector <sUser> vUsers;
    sUser User;
    sUser UserInput;

    vUsers = LoadUsersDataFromFile(UsersFileName);

    UserInput.UserName = ReadUsername();
    UserInput.Password = ReadPassword();

    while (!UserExistsByUserName(UserInput.UserName , UsersFileName)) {

        system("cls");
        cout << "===========================================\n";
        cout << "\t\tLogin Screen\n";
        cout << "===========================================\n";

        cout << "\nInvalid Username/Password!\n";

        UserInput.UserName = ReadUsername();
        UserInput.Password = ReadPassword();



    }

    FindUserByUserName(UserInput.UserName, vUsers, User);

    while (User.Password != UserInput.Password) {

        system("cls");
        cout << "===========================================\n";
        cout << "\t\tLogin Screen\n";
        cout << "===========================================\n";

        cout << "\nInvalid Username/Password!\n";

        UserInput.UserName = ReadUsername();
        UserInput.Password = ReadPassword();

    }

    ShowMainMenu();

}



void ShowLoginScreen() {

    system("cls");
    cout << "===========================================\n";
    cout << "\t\tLogin Screen\n";
    cout << "===========================================\n";

    Login();

}


void PerfromMainMenuOperation(enMainMenueOptions MainMenueOption) {

    switch (MainMenueOption) {

    case enMainMenueOptions::eListClients:
        system("cls");
        ShowAllClientsScreen();
        GoBackToMainMenue();
        break;


    case enMainMenueOptions::eAddNewClient:
        system("cls");
        ShowAddNewClientsScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eDeleteClient:
        system("cls");
        ShowDeleteClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eUpdateClient:
        system("cls");
        ShowUpdateClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eFindClient:
        system("cls");
        ShowFindClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eShowTransactionsMenu:
        system("cls");
        ShowTransactionsMenu();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eShowManageUsersScreen:
        system("cls");
        ShowManageUsersMenu();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eLogout:
        ShowLoginScreen();

        break;
    }

}

void ShowMainMenu() {

    system("cls");
    cout << "===========================================\n";
    cout << "\t\tMain Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Transactions.\n";
    cout << "\t[7] Manage Users.\n";
    cout << "\t[8] Logout.\n";
    cout << "===========================================\n";
    PerfromMainMenuOperation((enMainMenueOptions)ReadMainMenueOption());
}


int main()
{
    ShowLoginScreen();

}
