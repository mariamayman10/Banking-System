#include <bits/stdc++.h>
#include <vector>
using namespace std;
//#######################
class  BankAccount;
class Client;
class SavingsBankAccount;
class BankingApplication;
//#######################
static vector<Client> Client_list;
static vector<BankAccount> Accounts_list;
//#######################
class Client{
private:
    string Name;
    string Address;
    string Phone_Number;
    string Type;
    BankAccount* owner;
public:
    void set_n(string n);
    void set_add(string a);
    void set_p(string ph);
    void set_t(string t);
    string get_n();
    string get_add();
    string get_p();
    string get_t();
};
class BankAccount{
private:
    int account_ID;
    int Balance;
public:
    BankAccount();
    BankAccount(int b);
    int get_account_id();
    int get_balance();
    void set_account_id(int id);
    void set_balance(int amount);
    virtual void withdraw(int amount);
    virtual void deposit(int amount);
};
class BankingApplication{
public:
    int MenuSystem();
};
//##########################################
class SavingsBankAccount : BankAccount{
private:
    int MinimumBalance = 1000;
    string accounts;
public:
    void withdraw(int amount , int ind);
    void deposit(int amount , int ind);

};
bool isNumber(string num)
{
    for (char i : num)
    {
        if (!isdigit(i))
        {
            return false;
        }
    }
    return true;
}
bool is_alpha(string name){
    for (char i : name)
    {
        if (!isalpha(i))
        {
            return false;
        }
    }
    return true;
}
//##########################################
void Client :: set_n(string n) {
    Name = n;
}
void Client :: set_add(string a) {
    Address = a;
}
void Client :: set_p(string ph) {
    Phone_Number = ph;
}
void Client :: set_t(string t) {
    Type = t;
}
string Client :: get_n() {
    return Name;
}
string Client :: get_add() {
    return Address;
}
string Client :: get_p()
{
    return Phone_Number;
}
string Client :: get_t() {
    return Type;
}
//##########################################
int BankingApplication :: MenuSystem(){
    string option;
    cout << "Please choose option from the following:\n1- Create a new account\n2- List Clients and Accounts"
            "\n3- Withdraw Money\n4- Deposit Money\n5- Exit\n\nYour choice is: ";
    getline(cin, option, '\n');
    while(option != "1" && option != "2" && option != "3" && option != "4" && option != "5"){
        cout << "INVALID OPTION..TRY AGAIN\n\n";
        cout << "______________Welcome to Banking Application______________\n";
        cout << "Please choose option from the following:\n1- Create a new account\n2- List Clients and Accounts"
                "\n3- Withdraw Money\n4- Deposit Money\n5- Exit\n\nYour choice is: ";
        getline(cin, option, '\n');
    }
    cout << "\n\n";
    string name, address, phone, account_type;
    int acc_id;
    Client c;
    BankAccount b, before_b;
    if(option == "1"){
        cout << "Please enter client's name: ";
        getline(cin, name, '\n');
        while(!is_alpha(name)){
            cout << "Enter Valid Name!\nPlease enter client's name: "<< endl;
            getline(cin, name, '\n');
        }
        cout << "\nPlease enter client's address: ";
        getline(cin, address, '\n');
        bool run = true;
        cout << "\nPlease enter client's phone: ";
        getline(cin, phone, '\n');
        while (!isNumber(phone) || phone.length() != 11)
        {
            cout << "Enter Valid Number!\nPlease enter client's phone: "<< endl;
            getline(cin, phone, '\n');
        }
        while(true){
            cout << "\n\nWhich type of account you want to create:\n1- Basic\n2- Saving\nType you need is: ";
            getline(cin, account_type, '\n');
            if (account_type == "1")
            {
                c.set_t("Basic");
                break;
            }
            else if (account_type == "2")
            {
                c.set_t("Saving");
                break;
            }
            else
            {
                cout << "Wrong Option, Please Try again" << endl;
            }
        }
        if(Accounts_list.empty()){
            acc_id = 0;
        }
        else{
            before_b = Accounts_list.back();
            int last_id = before_b.get_account_id();
            acc_id = last_id + 1;
        }
        cout << "\n\n###############\nYour ID is " << acc_id << "\n###############\n\n";
        b.set_account_id(acc_id);
        if(account_type == "1"){
            b.set_balance(0);
        }
        else{
            b.set_balance(1000);
        }
        c.set_n(name);
        c.set_add(address);
        c.set_p(phone);
        Accounts_list.push_back(b);
        Client_list.push_back(c);
    }
    if(option == "2"){
        cout << "Name" << setw(21) << "Phone" << setw(22) << "Address" << setw(22)
             << "Client ID" << setw(15) << "Type" << setw(23) << "Balance" << '\n';
        for (int i = 0; i < Accounts_list.size(); ++i) {
            string n = Client_list[i].get_n();
            string a = Client_list[i].get_add();
            string p = Client_list[i].get_p();
            string t = Client_list[i].get_t();
            string bal = to_string(Accounts_list[i].get_balance());
            string id = to_string(Accounts_list[i].get_account_id());
            cout << n << setw(20 - n.length() + p.length()) << p << setw(20 - p.length() + a.length())
                 << a << setw(20 - a.length() + id.length()) << id << setw(20 - id.length() + t.length())
                 << t << setw(20 - t.length() + bal.length()) << bal << '\n';
        }
        cout << "\n\n\n";
    }
    if(option == "3"){
        if (Client_list.empty())
        {
            cout << "Add Clients First!" << endl;
        }
        else{
            string id, amount;
            int index = -1;
            cout << "Please enter your ID: ";
            getline(cin, id, '\n');
            while (!isNumber(id))
            {
                cout << "Enter Valid ID!\nPlease enter your ID: " << endl;
                getline(cin, id, '\n');
            }
            for (int i = 0; i < Accounts_list.size(); ++i) {
                if(Accounts_list[i].get_account_id() == stoi(id)){
                    index = i;
                }
            }
            while(index == -1){
                getline(cin, id, '\n');
                cout << "ID doesn't exist..Try again\n\n";
                cout << "Please enter your ID: ";
                for (int i = 0; i < Accounts_list.size(); ++i) {
                    if(Accounts_list[i].get_account_id() == stoi(id)){
                        index = i;
                    }
                }
            }
            cout << "\n\n";
            cout << "\nPlease enter the amount you want to withdraw: ";
            getline(cin, amount, '\n');
            while (!isNumber(amount))
            {
                cout << "Enter Valid Amount!\nPlease enter the amount you want to withdraw: " << endl;
                getline(cin, amount, '\n');
            }
            if(Client_list[index].get_t() == "Basic") {
                if (Accounts_list[index].get_balance() >= stoi(amount)) {
                    Accounts_list[index].set_balance(Accounts_list[index].get_balance() - stoi(amount));
                    cout << "\n\nWithdraw has been done successfully, Your balance is currently "
                         << Accounts_list[index].get_balance() << "\n\n";
                }
                else {
                    cout << "\nSorry, No enough balance\n\n";
                }
            }
            else if(Client_list[index].get_t() == "Saving"){
                SavingsBankAccount acc;
                acc.withdraw(stoi(amount) , index);
                cout << "Withdraw has been done successfully, Your balance is currently "
                     << Accounts_list[index].get_balance() << '\n';
            }
        }
    }
    if(option == "4"){
        if (Client_list.empty())
        {
            cout << "Add Clients First!" << endl;
        }
        else{
            string id, amount;
            int index = -1;
            cout << "Please enter your ID: ";
            getline(cin, id, '\n');
            while (!isNumber(id))
            {
                cout << "Enter Valid ID!" << endl;
                getline(cin, id, '\n');
            }
            for (int i = 0; i < Accounts_list.size(); ++i) {
                if(Accounts_list[i].get_account_id() == stoi(id)){
                    index = i;
                }
            }
            while(index == -1){
                cout << "ID doesn't exist..Try again\n\n";
                cout << "Please enter your ID: ";
                getline(cin, id, '\n');
                for (int i = 0; i < Accounts_list.size(); ++i) {
                    if(Accounts_list[i].get_account_id() == stoi(id)){
                        index = i;
                    }
                }
            }
            cout << "\nPlease enter the amount you want to deposit: ";
            getline(cin, amount, '\n');
            while (!isNumber(amount))
            {
                cout << "Enter Valid Amount!\nPlease enter the amount you want to deposit: " << endl;
                getline(cin, amount, '\n');
            }
            if(Client_list[index].get_t() == "Basic") {
                Accounts_list[index].set_balance(stoi(amount) + Accounts_list[index].get_balance());
                cout << "\n\nDeposit has been done successfully, Your balance is currently "
                     << Accounts_list[index].get_balance() << "\n\n";
            }
            else if(Client_list[index].get_t() == "Saving"){
                SavingsBankAccount acc;
                acc.deposit(stoi(amount) , index);
                cout << "\n\nDeposit has been done successfully, Your balance is currently "
                     << Accounts_list[index].get_balance() << '\n';
            }
        }
    }
    if(option == "5"){
        cout << "\n\n_____________Thanks for using our application_____________\n\n";
    }
    return stoi(option);
}
//###########################################
BankAccount :: BankAccount(){
    account_ID = 0;
    Balance = 0;
}
BankAccount::BankAccount(int b) {
    Balance = b;
}
int BankAccount::get_account_id() {
    return account_ID;
}
int BankAccount::get_balance() {
    return Balance;
}
void BankAccount::set_account_id(int id){
    account_ID = id;
}
void BankAccount ::set_balance(int amount) {
    Balance = amount;
}
void BankAccount::withdraw(int amount) {
    if(Balance >= amount){
        Balance -= amount;
    }
    else{
        cout << "\nSorry, No enough balance\n";
    }
}
void BankAccount::deposit(int amount) {
    Balance += amount;
}
//###########################################
void SavingsBankAccount:: withdraw(int amount , int ind){
    if(Accounts_list[ind].get_balance() - amount < 1000){
        cout << "Sorry, you can't withdraw " << amount << ",As your account is saving account " << endl;
    }else
    {
        BankAccount::withdraw(amount);
        Accounts_list[ind].set_balance(Accounts_list[ind].get_balance() - amount);
        set_balance(Accounts_list[ind].get_balance());
    }
}
void SavingsBankAccount:: deposit(int amount , int ind) {
    if(amount >= 100){
        Accounts_list[ind].set_balance(Accounts_list[ind].get_balance() + amount);
        BankAccount::deposit(Accounts_list[ind].get_balance());

    }else{
        cout << "Sorry, you can't deposit " << amount << ",As your account is saving account " << endl;
    }
}


int main() {
    cout << "______________Welcome to Banking Application______________\n";
    int option;
    BankingApplication app1;
    option = app1.MenuSystem();
    while(option != 5){
        option = app1.MenuSystem();
    }
}
