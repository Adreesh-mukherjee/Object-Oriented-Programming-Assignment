#include <iostream>
using namespace std;

class Student
{

    Student *next;
    int roll;
    string name;
    string course;
    string date;
    int marks[5];
    int num = 0;

private:
    void getmarks()
    {
        cout << "Enter marks in 5 subjects :";
        for (int i = 0; i < 5; i++)
            cin >> marks[i];
    }

public:
    Student *start;

    void getdata()
    {
        Student *s = new Student;

        cout << "Enter roll : ";
        cin >> roll;
        cout << "Enter name : ";
        cin >> name;
        cout << "Enter Course: ";
        cin >> course;
        cout << "Enter date of admission :";
        cin >> date;
        getmarks();

        s->name = name;
        s->roll = roll;
        s->date = date;
        s->course = course;
        s->next = NULL;
        for (int i = 0; i < 5; i++)
            s->marks[i] = marks[i];

        if (start == NULL)
        {
            start = s;
        }

        else
        {
            s->next = start;
            start = s;
        }
        num++;
    }

    void marksheet()
    {
        int rn, flag = 0;
        cout << "\nEnter the roll number of the student : ";
        cin >> rn;
        Student *temp;
        temp = start;
        while (temp != NULL)
        {
            if (temp->roll == rn)
            {
                cout<< "Roll : " << temp->roll << "\nName : " << temp->name << "\nCourse : " << temp->course << "\nDate : " << temp->date << "\n Marks in Subject 1 : " << temp->marks[0] << "\n Marks in Subject 2 : " << temp->marks[1] << "\n Marks in Subject 3 : " << temp->marks[2] << "\n Marks in Subject 4 : " << temp->marks[3] << "\n Marks in Subject 5 : " << temp->marks[4] << endl;
                flag = 1;
            }

            temp = temp->next;
        }
        if (flag == 0)
            cout << "\nRecord not found !!";
    }

    int getnum()
    {
        return num;
    }
};

int main()
{

    int i, choice, rn, flag = 1;
    Student a;
    a.start = NULL;
    while (flag == 1)
    {
        cout << "\nEnter choice : \t 1.Add data \t 2.Display marksheet \t 3.Show how many students : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            a.getdata();
            break;
        case 2:
            a.marksheet();
            break;
        case 3:
            cout << "Number of students are :  " << a.getnum() << endl;
            break;
        default:
            flag = 0;
            exit(1);
            break;
        }
    }
    return 0;
}