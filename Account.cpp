#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include<vector>
using namespace std;
class InsufficientFunds{};

class Account{
    long accountNo;
    string first_name;
    string last_name;
    float balance;
    static long next_accountNo;
    public:
    Account(){}
    Account(string fname, string lname, float bal);
    long getAccNo(){return accountNo;}
    string getFirstName(){return first_name;}
    string getLastName(){return last_name;}
    float getBalance(){return balance;}

    void deposit(float amount);
    void withdraw(float amount);
    static void setLastAccNo(long accountNo);
    static long getLastAccNo();
    friend ofstream & operator<<(ofstream &ofs,Account &a);
    friend ifstream & operator>>(ofstream &ifs,Account &a);
    friend ostream & operator<<(ostream &os,Account &a);
};
long Account::next_accountNo = 0;

Account::Account(string fname,string lname,float bal){
    next_accountNo++;
    accountNo = next_accountNo;
    first_name = fname;
    last_name = lname;
    balance = bal;
}

void Account::deposit(float amount){
    balance+=amount;
}

void Account::withdraw(float amount){
    if(balance-amount<500)
        throw InsufficientFunds;
    balance-=amount;
}

void Account::setLastAccNo(long accountNo){
    next_accountNo = accountNo;
}
long Account::getLastAccNo(){
    return next_accountNo;
}

ofstream & operator <<(ofstream &ofs,Account &a){
    ofs<<a.accountNo<<endl;
    ofs<<a.first_name<<endl;
    ofs<<a.last_name<<endl;
    ofs<<a.balance;
    return ofs;
}
ifstream &operator>>(ofstream &ifs, Account &a){
    ifs>>a.accountNo;
    ifs>>a.first_name;
    ifs>>a.last_name;
    ifs>>a.balance;
    return ifs;     
}
ostream &operator<<(ostream &os, Account &a)
{
    os<<"First Name:"<<a.getFirstName()<<endl;
    os<<"Last Name:"<<a.getLastName()<<endl;
    os<<"Account Number:"<<a.getAccNo()<<endl;
    os<<"Balance:"<<a.getBalance()<<endl;
    return os;
}

