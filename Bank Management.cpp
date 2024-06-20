#include<iostream>
#include<string>
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
