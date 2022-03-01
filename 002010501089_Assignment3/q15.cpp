#include <iostream>
using namespace std;

class BALANCE
{

    double bal;
    int acc_num;
    int date[3];

public:
    void input()
    {
        cout << "Enter the initial balance and enter the current date in dd mm yyyy format :\n";
        cin >> bal >> date[0] >> date[1] >> date[2];
    }
    void account()
    {
        cout << "Enter the account number :\n";
        cin >> acc_num;
    }

    void update(double newBalance, int day, int month, int year)
    {
        bal = newBalance;
        date[0] = day;
        date[1] = month;
        date[2] = year;
    }
    double givebal()
    {
        return bal;
    }
    int giveinfo()
    {
        return acc_num;
    }
};
class TRANSACTION
{
    BALANCE sc;

    double bal1 = 0;
    int acc_num1 = 0;

    double final_bal = 0;
    int date1[3];

public:
    void intialize(double n, int a)
    {
        final_bal = n;
        acc_num1 = a;
    }
    void deposit()
    {

        cout << "Enter the amount to be deposited and enter the date of Transaction in dd mm yyyy :\n";
        cin >> bal1 >> date1[0] >> date1[1] >> date1[2];
        cout << "The new balance is : ";
        cout << bal1 + final_bal << endl;
        final_bal = final_bal + bal1;
        cout << "DATE OF Deposit IS : " << date1[0] << "/" << date1[1] << "/" << date1[2] << "\n";
    }
    void withdraw()
    {
        // cout<<final_bal<<endl;
        // cout<<acc_num1<<endl;
        cout << "Enter the amount to be withdrawn and enter the date of Transaction in dd mm yyyy fromat :\n";
        cin >> bal1 >> date1[0] >> date1[1] >> date1[2];
        if (bal1 > final_bal)
        {
            cout << "Insufficient balance, not able to process withdrawal !\n";
        }
        else
        {
            cout << "The new balance is : ";
            cout << final_bal - bal1 << endl;
            final_bal = final_bal - bal1;
            cout << "DATE OF Withdrawal IS : " << date1[0] << "/" << date1[1] << "/" << date1[2] << "\n";
        }
    }
    double newBalance()
    {
        return final_bal;
    }
    int day()
    {
        return date1[0];
    }
    int month()
    {
        return date1[1];
    }
    int year()
    {
        return date1[2];
    }
};

int main()
{
    BALANCE sc;
    TRANSACTION t;
    int choice;
    sc.input();
    sc.account();
    t.intialize(sc.givebal(), sc.giveinfo());
    do
    {
        cout << "Enter 1 to deposit\n";
        cout << "Enter 2 to withdraw\n";
        cout << "Enter 3 to exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            t.deposit();
            sc.update(t.newBalance(), t.day(), t.month(), t.year());
            break;
        case 2:
            t.withdraw();
            sc.update(t.newBalance(), t.day(), t.month(), t.year());
            break;
        case 3:
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 3);
    return 0;
}