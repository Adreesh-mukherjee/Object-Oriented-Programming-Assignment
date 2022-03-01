#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

public:
    node(int val)
    {
        data = val;
        next = NULL;
    }
    void set_val(int val)
    {
        data = val;
        next = NULL;
    }
    void get_val()
    {
        cout << data << endl;
    }
};

class linked_list
{
    node *head;

public:
    linked_list()
    {
        head = NULL;
    }
    void Insert_at_tail(int val) // function for inserting a node at the tail of a linked list
    {
        node *n = new node(val);
        if (head == NULL)
        {
            head = n;
            return;
        }

        node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = n;
    }

    void deletion(int val) // function for deleting a node by its value
    {
        node *p, *n;
        p = head;
        // for deleting the head node
        if (head == NULL)
        {
            return;
        }
        if (p->data == val)
        {
            n = p;
            head = n->next;
            n->next = NULL;
            delete n;
            return;
        }
        while (p->next != NULL)
        {
            if (p->next->data == val)
            {
                n = p->next;
                p->next = n->next;
                n->next = NULL;
                delete n;
            }
            else
            {
                p = p->next;
            }
        }
    }
    void insert_at_head(int val) // inserting at the head
    {
        node *n = new node(val);
        n->next = head;
        head = n;
    }

    bool search_node(int key) // serching for a key in the linked list
    {
        node *n = head;
        while (n != NULL)
        {
            if (n->data == key)
            {
                return true;
            }
            else
            {
                n = n->next;
            }
        }
        return false;
    }

    void Display() // display the linked list
    {
        node *p = head;
        while (p != NULL)
        {
            cout << p->data << "->";
            p = p->next;
        }
        cout << "NULL" << endl;
    }
};

int main() // main function to implement all the activities on linked list
{
    linked_list l;
    cout << "\n---------------------------------------------------------\n";

    cout << "1. enter a node at the tail\n";

    cout << "2. enter the node at the head\n";

    cout << "3. search for a node\n";

    cout << "4. delete a node\n";

    cout << "5. display the list\n";

    cout << "6. Exit!\n\n";

    int val;
    {
        do
        {

            cout << "Enter your choice : ";
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "enter the value " << endl;

                cin >> val;
                l.Insert_at_tail(val);
                break;
            case 2:
                cout << "enter the value " << endl;

                cin >> val;
                l.insert_at_head(val);
                break;
            case 3:
                cout << "enter the value " << endl;

                cin >> val;
                cout << l.search_node(val) << endl;
                break;
            case 4:
                cout << "enter the value " << endl;

                cin >> val;
                l.deletion(val);
                break;

            case 5:
                l.Display();
                break;
            case 6:
                cout << "\nLogged out.\n";
                exit(0);
            default:
                cout << "\nPlease enter a valid choice.\n";
                break;
            }
        } while (1);
    }
    return 0;
}