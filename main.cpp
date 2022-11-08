#include <bits/stdc++.h>
#include <vector>
using namespace std;
//####################### if we have ids from 0 to 3 and i enter id 4 and chose to deposit it will be increased on balance of id 3
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
    BankAccount* owner_account;
    SavingsBankAccount* owner_account_s;
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
    Client* account_owner;
public:
    BankAccount();
    BankAccount(int b);
    int get_account_id();
    int get_balance();
    void set_account_id(int id);
    void set_balance(int amount);
    void withdraw(int amount);
    void deposit(int amount);
};
class SavingsBankAccount : BankAccount{
private:
    int MinimumBalance;
};
class BankingApplication{
public:
    int MenuSystem();
};
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
            "\n3- Withdraw Money\n4- Deposit Money\n5- Exit\n\n";
    getline(cin, option, '\n');
    while(option != "1" && option != "2" && option != "3" && option != "4" && option != "5"){
        cout << "INVALID OPTION..TRY AGAIN\n\n";
        cout << "______________Welcome to Banking Application______________\n";
        cout << "Please choose option from the following:\n1- Create a new account\n2- List Clients and Accounts"
                "\n3- Withdraw Money\n4- Deposit Money\n5- Exit\n\nYour choice is: ";
        getline(cin, option, '\n');
        cout << "\n\n";
    }
    if(option == "1"){
        string name, address, phone, account_type;
        int acc_id;
        Client c;
        BankAccount b, before_b;
        cout << "Please enter client's name: ";
        getline(cin, name, '\n');
        cout << "\nPlease enter client's address: ";
        getline(cin, address, '\n');
        cout << "\nPlease enter client's phone: ";
        getline(cin, phone, '\n');
        cout << "\n\nWhich type of account you want to create:\n1- Basic\n2- Saving\nType you need is: ";
        getline(cin, account_type, '\n');
        if(Accounts_list.empty()){
            acc_id = 0;
        }
        else{
            before_b = Accounts_list.back();
            int last_id = before_b.get_account_id();
            acc_id = last_id + 1;
        }
        cout << "\n\nYour ID is " << acc_id << '\n';
        b.set_account_id(acc_id);
        b.set_balance(0);
        c.set_n(name);
        c.set_add(address);
        c.set_p(phone);
        if(account_type == "1"){
            c.set_t("Basic");
        }
        else{
            c.set_t("Saving");
        }
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
        string id, amount;
        int index = -1;
        cout << "Please enter your ID: ";
        getline(cin, id, '\n');
        for (int i = 0; i < Accounts_list.size(); ++i) {
            if(Accounts_list[i].get_account_id() == stoi(id)){
                index = i;
            }
        }
        while(index == -1){
            getline(cin, id, '\n');
            cout << "Wrong ID..Try again\n\n";
            for (int i = 0; i < Accounts_list.size(); ++i) {
                if(Accounts_list[i].get_account_id() == stoi(id)){
                    index = i;
                }
            }
        }
        cout << "Please enter the amount you want to withdraw: ";
        getline(cin, amount, '\n');
        if(Accounts_list[index].get_balance() >= stoi(amount)){
            Accounts_list[index].set_balance(Accounts_list[index].get_balance() - stoi(amount));
            cout << "Withdraw has been done successfully, Your balance is currently " << Accounts_list[index].get_balance() << '\n';
        }
        else{
            cout << "Sorry, No enough balance\n\n";
        }
    }
    if(option == "4"){
        string id, amount;
        int index;
        cout << "Please enter your ID: ";
        getline(cin, id, '\n');
        for (int i = 0; i < Accounts_list.size(); ++i) {
            if(Accounts_list[i].get_account_id() == stoi(id)){
                index = i;
            }
        }
        while(index == -1){
            cout << "Wrong ID..Try again\n\n";
            getline(cin, id, '\n');
            for (int i = 0; i < Accounts_list.size(); ++i) {
                if(Accounts_list[i].get_account_id() == stoi(id)){
                    index = i;
                }
            }
        }
        cout << "Please enter the amount you want to deposit: ";
        getline(cin, amount, '\n');
        Accounts_list[index].set_balance(stoi(amount) + Accounts_list[index].get_balance());
        cout << "\n\nDeposit has been done successfully, Your balance is currently " << Accounts_list[index].get_balance() << '\n';
    }
    if(option == "5"){
        cout << "\n\nThanks for using our application\n\n";
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






int main() {
    cout << "______________Welcome to Banking Application______________\n";
    int option;
    BankingApplication app1;
    option = app1.MenuSystem();
    while(option != 5){
        option = app1.MenuSystem();
    }
}