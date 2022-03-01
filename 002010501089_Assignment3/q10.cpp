#include<iostream>
#define max 10
using namespace std;

class stack
{


int top=-1;
int *ptr;

void display()
    {
        int i;
        cout<<"The stack is : ";
        for(i=top;i>=0;i--)
        {
            cout<<ptr[i]<<" ";
        }
    }

public: 

   int* initialise() //INITIALIZATION OF STACK CLASS 
   {
        ptr = (int*)malloc(max*sizeof(int));
       return ptr;
   } 

    void push(int data) // FUNCTION FOR PUSH, CHECK FOR OVERFLOW
    {
        if(top>=max-1)
        {
            cout<<"!!!!!!!!Stack OVERFLOW!!!!!!!!!";
        }  
        else
        {  
            top = top+1;
            ptr[top] = data; 
            display();
        }
    }

    void pop() //FUNCTION FOR POP, CHECK FOR UNDERFLOW
    {
        if(top==-1)
        {
            cout<<"!!!!!!!!Stack UNDERFLOW!!!!!!!!!!";
        }
        else
        {
           top = top - 1;
           display();
        }
    }

    

};



int main() // MAIN FUNCTION TO GENERATE STACK AND CHECK FOR OVERFLOW AND UNDERFLOW
{
    
    stack t;
    t.initialise();
    int flag = 1;
    int choice,data;
    cout<<"Enter your choice : ";
    
    while(flag==1)
    {
        cout<<"\n1.Push\n2.Pop\n3.Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1 :
                    cout<<"Enter Data :";
                    cin>>data;
                    t.push(data);
                    break;
            case 2 :
                    t.pop();
                    break;

            case 3:
                    flag = 0;
                    break;

            default :
                    cout<<"Wrong Choice Enter again";        


        }

    }


}
