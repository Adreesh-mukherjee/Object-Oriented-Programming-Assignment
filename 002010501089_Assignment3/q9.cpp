#include<iostream>
using namespace std;

class TIME
{
    unsigned int hour;
    unsigned int minute;
    unsigned int second;
    int arr[3];
    char ch;
    int min;

    public:
    
        void gettime24() //FUNCTION TO INPUT THE TIME IN 24HR FORMAT
        {
           
            cout<<"Enter time in HOUR : MIN : SECOND format :: ";
            cin>>hour>>minute>>second;

            if(hour>=24 || minute>=60 || second>=60)
            {
                cout<<"Invalid time format"<<endl;
                exit;
            }
            arr[0]=hour;
            arr[1]=minute;
            arr[2]=second;


        }
    

        void gettime12() //FUNCTION TO INPUT TIME IN 12 HR FORMAT
        {

            
            
            cout<<"Enter time in HOUR : MIN : SECOND format , Press A for AM , P for PM "<<endl<<"\t\t";
            cin>>hour>>minute>>second>>ch;

            if(hour>12 || minute>=60 || second>=60)
            {
                cout<<"Invalid time format"<<endl;
                exit;
            }

            if((ch=='P' || ch == 'p')&& hour!=12)
            {
                hour = hour + 12;

            }

            if((ch=='A' || ch=='a') && hour==12)
            {
                hour = 0;
            }
            arr[0]=hour;
            arr[1]=minute;
            arr[2]=second;

        }

        void displaytime24() //FUNTION TO DISPLAY TIME IN 24HR FORMAT
        {
            if(hour>=24 || minute>=60 || second>=60)
            {
            cout<<"Invalid time format"<<endl;
            exit;
            }
            cout<<"The time is : "<<endl;
            cout<<arr[0]<<" : "<<arr[1]<<" : "<<arr[2]<<endl;
        }

        void displaytime12() // FUNTION TO DISPLAY TIME IN 12HR FORMAT
        {
            string c;
            if((ch== 'P' || ch == 'p') || hour>12 )
            c = "PM";
            else
            c = "AM";

            if(hour>12)
            {
                hour = hour - 12 ;
                arr[0] = hour;
            } 

            if(hour=0)
            {
                hour = 12 ;
                arr[0] = hour;
            }

            cout<<arr[0]<<" : "<<arr[1]<<" : "<<arr[2]<<" "<<c<<endl;

        }

        void addmin()// FUNTION TO ADD DESIRED NUMBER OF MINUTES
        {
            int choice;
            string ap;

            cout<<"Enter how many minutes to add : ";
            cin>>min;
            
            cout<<"Current time : "<<arr[0]<<" : "<<arr[1]<<" : "<<arr[2]<<endl;

            minute = min + minute;


            hour = arr[0] + minute/60;
            minute = minute%60;



            arr[0] = hour;
            arr[1] = minute;
            arr[2] = second;

            cout<<"Pick choce in which time format you want to get the time : "<<endl;
            cout<<"1. 24 hour format\t2. 12 hour format"<<endl;
            cin>>choice;


            if(choice==1)
            {
                if(arr[0]>=24)
                arr[0] = arr[0] % 24;

                cout<<"Final Time after adding "<<min<<" minutes : "<<arr[0]<<" : "<<arr[1]<<" : "<<arr[2]<<endl;
            }
            if(choice==2)
            {

                if((arr[0]/12)%2==0)
                ap = "AM";
                else
                ap = "PM";
                
                if(arr[0]>12)
                {
                    if(arr[0]%12==0)
                    arr[0] = 12;

                    else
                    arr[0] = arr[0]%12;
                    
                }

                cout<<"Time after adding "<<min<<" minutes : "<<arr[0]<<" : "<<arr[1]<<" : "<<arr[2]<<" "<<ap<<endl;
                    
            }





            
        }

};


int main()
{
    int choice;
    TIME t;
  
    
    cout<<"\n\nPress 1 to enter time in 24hour format\tPress 2 to enter time in 12 hour format : ";
    cin>>choice;
    if(choice==1)
    t.gettime24();
    else if(choice==2)
    t.gettime12();
    else
    {
    cout<<"Wrong Choice";
    return 1;
    }


    choice=0;
    cout<<"\n\nPress 1 to display time in 24hour format\tPress 2 to display time in 12 hour format : ";
    cin>>choice;

    if(choice==1)
    t.displaytime24();
    else if(choice==2)
    t.displaytime12();
    else
    {
    cout<<"Wrong Choice";
    return 1;
    }
    choice=0;
    cout<<"Do you want to add minutes ? "<<"\n\tPress 1 for yes \t Press 2 for no :"<<endl;
    cin>>choice;
    if(choice==1)
    t.addmin();
    else
    return 1;

    
   

    return 0;

}