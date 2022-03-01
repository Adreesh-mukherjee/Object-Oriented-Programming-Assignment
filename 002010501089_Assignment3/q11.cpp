#include<iostream>
using namespace std;

class APPLICANT 
{
    int id=1;
    string name;
    int score;
    int count=0;
    APPLICANT *next;
    


    public:

            APPLICANT *start;

            void add() //FUNCTION TO ADD A NEW APPLICANT AND DETAILS
            {
               
                APPLICANT *app = new APPLICANT;

                cout<<"Enter name of applicant : ";
                cin>>name;
                cout<<"Enter score of applicant : ";
                cin>>score;

                app->name = name;
                app->score = score;
                app->id = id;
                app->next= NULL;

                id = id+1;

                if(start==NULL)
                {
                    start = app;
                }

                else 
                {  
                    app->next = start;
                    start = app;
                }

                count++;
            }


            void del() // FUNCTIO TO DELETE RECORD OF AN APPLICANT
            {
                int id;
                APPLICANT* temp1;
                APPLICANT* temp2;

                temp1=start;
                temp2=start;

                cout<<"\nEnter id of the applicant to be deleted: ";
                cin>>id;

                if(start==NULL)
                cout<<"LIST IS EMPTY";


                else
                {
                    while(temp1->next!=NULL)
                    {
                        if(temp1->id==id)
                        {
                            if(temp1==temp2)
                            {
                                start = start->next;
                                free(temp1);
                            }
                            else
                            {
                            temp2->next = temp1->next;
                            free(temp1);
                            }
                            cout<<"Applicant found and details deleted successfully"<<endl;
                            return;
                        }
                            
                        temp2=temp1;
                        temp1 = temp1->next;
     
                    }
                    cout<<"Applicant found "<<endl;
                     
                }
               
                count--;
            }


            void display() //FUNCTION TO DISPLAY RECORDS OF AN APPLICANT
            {
                APPLICANT* temp;

                temp = start;
                while(temp!=NULL)
                {
                    cout<<temp->id<<". Name : "<<temp->name<<"     marks : "<<temp->score<<endl;
                    temp = temp->next;
                }
            }

            void showcount() // FUNCTION TO SHOW THE NUMBER OF CURRENT APPLICANTS
            {
                cout<<"Number of applicants = "<<count;
            }
    


};

int main()
{
    int choice,flag=1;
    APPLICANT a;
    a.start=NULL;

while(flag==1)
{
cout<<"\nEnter 1 to add\nEnter 2 to delete\nEnter 3 to display\nEnter 4 to show number of applicants\nEnter 0 to exit  : ";
cin>>choice;

switch(choice)
{

    case 1 : a.add();break;
    case 2 : a.del();break;
    case 3 : a.display();break;
    case 4 : a.showcount();break;
    case 0 : flag=0;exit;break;
    default : cout<<"Wrong choice enter again ";


}

}   
    
return 0;

}
