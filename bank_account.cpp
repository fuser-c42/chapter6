#include <iostream>

using namespace std;

class BankAccount
{
    public:

        BankAccount(int dollars, int cents, double rate);//constructor

        BankAccount(int dollars, double rate);//constructor

        BankAccount();//constructor

        void set(int dollars, int cents, double rate);

        void set(int dollars, double rate);

        void update();

        double get_balance();

        double get_rate();

        void output(ostream& outs);
    
    private:
        double balance;
        double interest_rate;
        double fraction(double percent);
};

int main()
{
    BankAccount account1(100, 2, 3), account2;
    cout << "Account1 initialized as follows:\n";
    account1.output(cout);
    cout << "Account2 initialized as follows:\n";
    account2.output(cout);

    account1 = BankAccount(999, 99, 5.5);
    cout << "Account1 reset to the following:\n";
    account1.output(cout);
    return 0;
}

BankAccount::BankAccount(int dollars, int cents, double rate)
{
    balance = dollars + 0.01*cents;
    interest_rate = rate;
}

BankAccount::BankAccount(int dollars, double rate)
{
    balance = dollars;
    interest_rate = rate;
}

BankAccount::BankAccount()
{
    balance = 0;
    interest_rate = 0.0;
}

void BankAccount::set(int dollars, int cents, double rate)
{
    balance = dollars + 0.01*cents;
    interest_rate = rate;
}

void BankAccount::set(int dollars, double rate)
{
    balance = dollars;
    interest_rate = rate;
}

void BankAccount::update()
{
    balance = balance + fraction(interest_rate) * balance;
}

double BankAccount::fraction(double percent)
{
    return (percent/100.0);
}

double BankAccount::get_balance()
{
    return balance;
}

double BankAccount::get_rate()
{
    return interest_rate;
}

void BankAccount::output(ostream& outs)
{
    outs.setf(ios::fixed);
    outs.setf(ios::showpoint);
    outs.precision(2);
    outs << "Account Balance $" << balance << endl;
    outs <<"Interest rate " << interest_rate << "%" << endl;
}