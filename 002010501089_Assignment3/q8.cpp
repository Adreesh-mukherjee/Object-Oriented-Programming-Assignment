#include<iostream>
using namespace std;

struct Student 
{

    int roll;
    int score;
    void getdata()
    {
        cout<<"Enter Roll : ";
        cin>>roll;
        cout<<"Enter Score : ";
        cin>>score;
    }
    void showdata()
    {
        cout<<"Roll : "<<roll<<endl<<"Score : "<<score<<endl;
    }


};



Student modify_Score(Student s)
{
    int marks;
    cout<<"\nEnter new score : ";
    cin>>marks;
    s.score = marks;
    return s;
}

void showdataGlobal(Student s)
{
    cout<<"Roll : "<<s.roll<<endl<<"Score : "<<s.score<<endl;
}


int main()
{
    Student x,y;
    int score;
    x.getdata();
    x.showdata();
    x=modify_Score(x);
    showdataGlobal(x);
 

    return 0;
}