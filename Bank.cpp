#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<string>
using namespace std;
class Bank{
    private:
    map<long,Account> accounts;
    public:
    Bank();
    Account open_account(string fname, string lname, float balance);
    Account balance_inquiry(long accountNo);
    Account deposit(long accountNo, float amount);
    Account withdraw(long accountNo, float amount);
    void close_account(long accountNo);
    void show_accounts();
    ~Bank();
};

Bank::Bank(){
    
}