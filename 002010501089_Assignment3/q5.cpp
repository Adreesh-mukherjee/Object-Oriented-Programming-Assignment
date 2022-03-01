#include<iostream>
using namespace std;

float Tax(int income,int rate=10) //FUNCTION TO CALULATE AND RETURN THE TOTAL TAX APPLICATBLE ON INCOME
{
    return (income*rate)/100;
}

int main()
{
    
    int income,rate,c;

    cout<<"\n\nEnter the income : ";
    cin>>income;

    cout<<"\nPress 1 to enter desired Tax Rate\nPress 2 for 10% tax rate"<<endl;
    cin>>c;
    
    
        switch(c)
        {
        case 1: // TAX RATE GIVEN
            cout<<"Enter the desired tax rate : ";
            cin>>rate;
            cout<<"Net Payable income tax amount is : "<<Tax(income,rate)<<endl;
            break;

        case 2: //TAX RATE NOT GIVEN, TAKEN AS 10%

            cout<<"Net Payable income tax amount is : "<<Tax(income)<<endl;
            break;

        default:    
            cout<<"Error input" <<endl;
            break;
        }



    return 0;
}