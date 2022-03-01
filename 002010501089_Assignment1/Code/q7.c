//7. Maintain a list to store roll, name and score of students. As and when required student record may be added or deleted. Also, the list has to be displayed. Design suitable functions for different operations.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct myStr //structure to assign roll, name score
{
    int roll;
    char name[50];
    float score;
    struct myStr *next;
} 
student;

void addEntry(student **head) //function to add entry in the list
{
    student *s;
    if ((*head) == NULL)
    {
        printf("List is empty\n");
        s = (student *)malloc(1 * sizeof(student));
        printf("Enter roll : ");
        scanf(" %d", &((s)->roll));
        printf("Enter name : ");
        scanf(" %s", (s)->name);
        printf("Enter score : ");
        scanf(" %f", &((s)->score));
        (*head) = s;
        s->next = NULL;
    }
    else
    {
        student *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        s = (student *)malloc(1 * sizeof(student));
        printf("Enter roll : ");
        scanf(" %d", &((s)->roll));
        printf("Enter name : ");
        scanf(" %s", (s)->name);
        printf("Enter score : ");
        scanf(" %f", &((s)->score));
        temp->next = s;
        s->next = NULL;
    }
}

void delEntry(student **head, int pos) //function to delete an entry in the list
{
    student *temp;
    temp = (*head);
    if ((*head) == NULL)
    {
        printf("No items in the list to be deleted\n");
        return;
    }
    else if ((*head)->next == NULL)
    {
        free((*head));
        (*head) = NULL;
    }
    else if (pos == -1)
    {
        while ((temp->next)->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    else
    {
        student *x;
        while ((pos != 0) && (temp->next != NULL))
        {
            x = temp;
            temp = temp->next;
            pos--;
        }
        if (pos)
        {
            printf("Error\n");
            return;
        }
        else
        {
            x->next = temp->next;
            free(temp);
        }
    }
    printf("Deleted Entry\n");
}

void printList(student *head) //function to print the desired list
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (head != NULL)
    {
        printf("Roll : %d\t", head->roll);
        printf("Name : %s\t", head->name);
        printf("Score : %f\n", head->score);
        head = head->next;
    }
}

int main(int argc, char **argv)
{
    int n, pos;
    char c = 'N';
    printf("1. Add an entry\n2. Delete an entry\n3. Display the List\n");
    student *head = NULL;
    do
    {
        printf("Enter your choice : ");
        scanf(" %d", &n);
        switch (n)
        {
        case 1:
            printf("Adding entries\n");
            addEntry(&head);
            break;
        case 2:
            printf("Enter position = ");
            scanf(" %d", &pos);
            delEntry(&head, pos);
            break;
        case 3:
            printf("List is as follows:\n");
            printList(head);
            break;

        default:
            printf("No entry found\n");
            break;
        }
        printf("To continue press y/Y: ");
        scanf(" %c", &c);
    } while (c == 'y' || c == 'Y');
    return 0;
}