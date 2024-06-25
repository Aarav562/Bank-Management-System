#include<iostream>
#include<string>
#include<fstream>
using namespace std;
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

Account::Account(string fname,string lname,float bal){
    first_name = fname;
    last_name = lname;
    balance = bal;
}
ofstream & operator <<(ofstream &ofs,Account &a){
    ofs<<a.accountNo<<endl;
    ofs<<a.first_name<<endl;
    ofs<<a.last_name<<endl;
    ofs<<a.balance;
    return ofs;
}
ostream & operator<<(ostream &os,Account &a)
{
    os<<"First Name:"<<a.getFirstName()<<endl;
    os<<"Last Name:"<<a.getLastName()<<endl;
    os<<"Account Number:"<<a.getAccNo()<<endl;
    os<<"Balance:"<<a.getBalance()<<endl;
    return os;
}
ifstream & operator>>(ifstream &ifs,Account &a)
{
    ifs>>a.accountNo;
    ifs>>a.first_name;
    ifs>>a.last_name;
    ifs>>a.balance;
    return ifs; 
}

