#include <iostream>
using namespace std;

class Item
{
    int code;
    string name;
    float rate;
    int quantity;
    Item *next;

public:
    Item *start = NULL;


    int check(int pc)
    {
        int flag = 0;
        Item *temp = start;
        while (temp != NULL)
        {
            if (temp->code == pc)
            {
                flag = 1;
            }
            temp = temp->next;
        }

        return flag;
    }


    void add() // FUNCTION TO ADD A NEW PRODUCT
    {
        Item *temp = new Item;
        cout << "Enter product code : ";
        cin >> code;
        if (check(code) == 1)
            cout << "Product code already exists, try another code.";
        else
        {
            cout << "Enter product name : ";
            cin >> name;
            cout << "Enter rate of the product : ";
            cin >> rate;
            cout << "Enter quantity of the product : ";
            cin >> quantity;

            temp->code = code;
            temp->name = name;
            temp->quantity = quantity;
            temp->rate = rate;
            temp->next = NULL;

            if (start == NULL)
            {
                start = temp;
            }
            else
            {
                temp->next = start;
                start = temp;
            }
        }
    }

    void changerate(int pc) // FUNCTION TO CHANGE THE RATE OF AN EXISTING PRODUCT
    {

        Item *temp = start;
        int flag = 0;
        while (temp != NULL)
        {
            if (temp->code == pc)
            {
                cout << "\nProduct Available";
                cout << "\nName : " << temp->name << "\tRate : " << temp->rate;
                cout << "\nEnter new rate : ";
                cin >> temp->rate;
                flag = 1;
            }

            temp = temp->next;
        }

        if (flag != 1)
            cout << "Invalid Product code";
    }

    void modqty(int pc) // FUNCTION TO CHANGE THE QUANTITY OF AN AVAILABLE ITEM
    {

        Item *temp = start;
        int flag = 0, choice, qty;
        while (temp != NULL)
        {
            if (temp->code == pc)
            {
                cout << "Product Found ";
                cout << "\nName : " << temp->name << "\tCurrent stock : " << temp->quantity;

                cout << "\nEnter choice: 1.Add new products \t 2.Remove Products : ";
                cin >> choice;
                if (choice == 1)
                {
                    cout << "Enter how many products to add : ";
                    cin >> qty;
                    temp->quantity = temp->quantity + qty;
                    cout << qty << " products added , Current stock : " << temp->quantity;
                }
                if (choice == 2)
                {
                    cout << "Enter how many products to remove : ";
                    cin >> qty;
                    if (qty > temp->quantity)
                    {
                        cout << "Insufficient products in stock : ";
                    }
                    else
                    {
                        temp->quantity = temp->quantity - qty;
                        cout << qty << " products removed , Current stock : " << temp->quantity;
                        if(temp->quantity==0)
                        {

                        }
                    }
                }

                flag = 1;
            }

            temp = temp->next;
        }

        if (flag != 1)
            cout << "Invalid Product code";
    }

    void checkall()
    {
        Item *temp = start;
        int flag = 0, choice, qty;
        while (temp != NULL)
        {
            cout<<"Item Code : "<<temp->code<<" Item Name : "<<temp->name<<" Item quantity : "<<temp->quantity<<endl;
            temp = temp->next;
        }

    }

    void query(int pc) // FUNCTION TO CHECK DETAILS OF AN ITEM
    {
        Item *temp = start;
        int flag = 0, choice, qty;
        while (temp != NULL)
        {
            if (temp->code == pc)
            {
                cout << "Product Found ";
                cout << "Name : " << temp->name << "Price : " << temp->rate << "Avaiable quantity : " << temp->quantity;
                flag = 1;
            }
            temp = temp->next;
        }

        if (flag != 1)
            cout << "Invalid Product code";
    }
};

int main() // MAIN FUNCTION TO IMPLEMENT ALL THE ACTIONS REQUIRED
{
    Item a;
    int choice,flag=1,pc;
    a.start=NULL;
    while(flag==1)
    {
    cout<<"\nEnter choice :\n1.Add new product\n2.Modify quantity\n3.Modify rate\n4.Display all products\n5.Search product\n6.Exit"<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1 : a.add();break;
        
        case 2 : cout<<"Enter product code : ";
                 cin>>pc;
                 a.modqty(pc);
                 break;

        case 3 : cout<<"Enter product code : ";
                 cin>>pc;
                 a.changerate(pc);
                 break;
        
        case 4 : a.checkall();
                 break;

        case 5 : cout<<"Enter product code : ";
                 cin>>pc;
                 a.query(pc);
                 break;

        default : exit(0);break;
    }
         
    }
    return 0;
}