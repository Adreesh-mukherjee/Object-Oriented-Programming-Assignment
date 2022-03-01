#include <stdlib.h>
#include <string.h>
#include <stdio.h>


struct Student // DECLARING STRUCTURE OF NAME STUDENT
{
    int roll;
    char name[50];
    float sub1;
    float sub2;
    float sub3;
    float sub4;
    float sub5;
    struct Student *temp; // TEMPORARY POINTER 


} 
* head;

void insertData(int roll, char *name, float sub1, float sub2, float sub3, float sub4, float sub5) // FUNCTION FOR INSERTING DETAILS OF STUDENTS
{

    struct Student *student = (struct Student *)malloc(sizeof(struct Student)); //ALLOCATING MEMORY SPACE FOR STRUCT STUDENT
    student->roll = roll;
    strcpy(student->name, name);
    student->sub1 = sub1;
    student->sub2 = sub2;
    student->sub3 = sub3;
    student->sub4 = sub4;
    student->sub5 = sub5;
    student->temp = NULL;

    if (head == NULL)
    { //IF THE LIST IS EMPTY THEN HEAD WILL BE ASSIGNED TO POINT THE FIRST NODE

        head = student;
    }
    else
    {

        student->temp = head; 
        head = student;       // EXCHANGING TEMP WITH NEWLY ADDED DETAILS
    }
}


void searchData(int roll) //FUNCTION TO SEARCH FOR THE ENTERED ROLL NUMBER AND PRINT ITS DETAILS
{
    struct Student *t = head;
    while (t != NULL)
    {
        if (t->roll == roll)
        {
            printf("Roll Number: %d\n", t->roll);
            printf("Name: %s\n", t->name);
            printf("Subject1 marks: %f\n", t->sub1);
            printf("Subject2 marks: %f\n", t->sub2);
            printf("Subject3 marks: %f\n", t->sub3);
            printf("Subject4 marks: %f\n", t->sub4);
            printf("Subject5 marks: %f\n", t->sub5);
            return;
        }
        t = t->temp;
    }
    printf("Student with roll number %d is not found in Database\n", roll);
}


void updateData(int roll) // FUNCTION TO FIND A ROLL NUMBER AND UPDATE IT'S CORRESPONDING MARKS
{

    struct Student *t = head;
    while (t != NULL)
    {

        if (t->roll == roll)
        {
            printf("Record with roll number %d is present in the Database\n", roll);
            printf("Enter new name: ");
            scanf("%s", t->name);

            printf("Enter new Subject 1 marks: ");
            scanf("%f", &t->sub1);
            printf("Enter new Subject 2 marks: ");
            scanf("%f", &t->sub2);
            printf("Enter new Subject 3 marks: ");
            scanf("%f", &t->sub3);
            printf("Enter new Subject 4 marks: ");
            scanf("%f", &t->sub4);
            printf("Enter new Subject 5 marks: ");
            scanf("%f", &t->sub5);

            printf("Updation Successful!!!\n");
            return;
        }
        t = t->temp;
    }
    printf("Student with roll number %d is not found !!!\n", roll);
}


void deleteData(int roll) // FUNCTION TO DELETE A DESIRED RECORD
{
    struct Student *t1 = head;
    struct Student *t2 = head;
    while (t1 != NULL)
    {

        if (t1->roll == roll)
        {

            printf("Student with roll number %d is present in database\n", roll);

            if (t1 == t2)
            { //THIS CONDITION WILL EXECUTE IFF THE NODE WHICH IS TO BE DELETED IS THE FIRST NODE OF THE LIST

                head = head->temp; //NOW AS THE FIRST NODE IS DELETED THEN LIST WILL START FROM SECOND NODE SO WE SHIFT HEAD POINTER TO POINT FROM SECOND NODE
                free(t1);
            }
            else
            {

                t2->temp = t1->temp; //TEMP1 IS TO BE DELETED
                free(t1);            //TEMP2 IS THE NODE JUST BEFORE TEMP1
            }

            printf("Record Successfully Deleted\n");
            return;
        }
        t2 = t1;
        t1 = t1->temp; 
    }
    printf("Student with roll number %d is not found !!!\n", roll);
}


int main() // MAIN FUNCTION CALLING ALL THE OTHER FUNCTIONS
{
    head = NULL;
    int choice;
    char name[50];
    int roll;
    float sub1;
    float sub2;
    float sub3;
    float sub4;
    float sub5;
    FILE *ptr;
    printf("0.Exit \n1. Insert student details\n2. Search for student details\n3. Delete student details\n4. Update student details\n\n");
    do
    {
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        printf("--------------------------------------------------------------------------------------\n");
        switch (choice)
        {
        case 0:
            printf("RECORD HAS BEEN CLOSED");
            break;


        case 1:;
            ptr = fopen("Student Details1.txt", "w"); // OPENING THE TXT FILE IN WHICH RECORDS ARE STORED
            printf("Enter roll number: ");
            scanf("%d", &roll);
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter Subject1 marks: ");
            scanf("%f", &sub1);
            printf("Enter Subject2 marks: ");
            scanf("%f", &sub2);
            printf("Enter Subject3 marks: ");
            scanf("%f", &sub3);
            printf("Enter Subject4 marks: ");
            scanf("%f", &sub4);
            printf("Enter Subject5 marks: ");
            scanf("%f", &sub5);
            insertData(roll, name, sub1, sub2, sub3, sub4, sub5);

            struct Student *t = head;
            while (t != NULL)
            {
                fprintf(ptr, "Roll = %d, Name = %s, Sub 1 marks = %f,Sub 2 marks = %f,Sub 3 marks = %f,Sub 4 marks = %f,Sub 5 marks = %f \n", t->roll, t->name, t->sub1, t->sub2, t->sub3, t->sub4, t->sub5);
                t = t->temp;
            }
            fclose(ptr);
            break;


        case 2:
            printf("Enter roll number to search: ");
            scanf("%d", &roll);
            searchData(roll);
            break;


        case 3:;
            ptr = fopen("Student Details1.txt", "w"); 
            printf("Enter roll number to delete: ");
            scanf("%d", &roll);
            deleteData(roll);
             struct Student *f = head;
            while (f != NULL)
            {
                fprintf(ptr, "Roll = %d, Name = %s, Sub 1 marks = %f,Sub 2 marks = %f,Sub 3 marks = %f,Sub 4 marks = %f,Sub 5 marks = %f \n", f->roll, f->name, f->sub1, f->sub2, f->sub3, f->sub4, f->sub5);
                f = f->temp;
            }
            fclose(ptr);
            break;


        case 4:;
            ptr = fopen("Student Details1ṁ.txt", "w"); 
            printf("Enter roll number to update: ");
            scanf("%d", &roll);
            updateData(roll);
            struct Student *q = head;
            while (q != NULL)
            {
                fprintf(ptr, "Roll = %d, Name = %s, Sub 1 marks = %f,Sub 2 marks = %f,Sub 3 marks = %f,Sub 4 marks = %f,Sub 5 marks = %f \n", q->roll, q->name, q->sub1, q->sub2, q->sub3, q->sub4, q->sub5);
                q = q->temp;
            }
            fclose(ptr);
            break;

        default:
            printf("ENTER VALID CHOICE");
        }

    } while (choice != 0);
    return 0;
}
