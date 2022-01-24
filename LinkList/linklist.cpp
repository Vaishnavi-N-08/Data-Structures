#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertTail(Node *&head, int val)
{
    Node *n = new Node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
}

void insertAtAnyPos(Node *&head, int pos, int value)
{
    //Allocate node to new element
    Node *newNode = new Node(value);
    //check position >0
    if (pos < 1)
    {
        cout << "Position should be >=1" << endl;
    }
    else if (head == NULL)
    {
        head = newNode;
        return;
    }
    else if (pos == 1)
    {
        //if the position is 1, make next of the
        //new node as head and new node as head
        newNode->next = head;
        head = newNode;
        return;
    }
    else
    {
        Node *temp = head;
        for (int i = 1; i <= pos; i++)
        {
            if (temp != NULL)
            {
                temp = temp->next;
            }
        }
        if (temp != NULL)
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else
        {
            cout << "Position is invalid element is inserted at tail" << endl;
            insertTail(head, value);
        }
    }
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";

        temp = temp->next;
    }

    cout << endl;
}

void Delete(Node *&head, int val)
{
    Node *temp = head;
    if (temp->data == val)
    {
        head = head->next;

        return;
    }

    while (temp->next->next != NULL)
    {
        if (temp->next->data == val)
        {
            temp->next = temp->next->next;
            return;
        }

        temp = temp->next;
    }
    if (temp->next->data == val)
    {
        temp->next = temp->next->next;
        return;
    }
    cout << "Element was not there" << endl;
    return;
}

int main()
{
    Node *head = NULL;
    int choice;
    int a, b, ele, pos;
    while (choice != 5)
    {
        cout << "**************************************" << endl;
        cout << "Press 1 : Insert" << endl;
        cout << "Press 2 : Delete" << endl;
        cout << "Press 3 : Display" << endl;
        cout << "Press 4 : Insert At Any position" << endl;
        cout << "Press 5 : Exit" << endl;
        cout << "**************************************" << endl;
        cout << "Enter Your Choice :" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element you want to insert : " << endl;
            cin >> a;
            insertTail(head, a);
            break;
        case 2:
            cout << "Enter the element you want to delete : " << endl;
            cin >> b;
            Delete(head, b);
            break;
        case 3:
            display(head);
            break;
        case 4:
            cout << "Enter the element you want to insert : " << endl;
            cin >> ele;
            cout << "Enter the position of element you want to insert : " << endl;
            cin >> pos;
            insertAtAnyPos(head, pos, ele);
            //   display(head);
            break;
        case 5:
            break;
        }
    }

    return 0;
}

//OUTPUT
// **************************************
// Press 1 : Insert
// Press 2 : Delete
// Press 3 : Display
// Press 4 : Insert At Any position
// Press 5 : Exit
// **************************************
// Enter Your Choice :
// 1
// Enter the element you want to insert :
// 3
// **************************************
// Press 1 : Insert
// Press 2 : Delete
// Press 3 : Display
// Press 4 : Insert At Any position
// Press 5 : Exit
// **************************************
// Enter Your Choice :
// 1
// Enter the element you want to insert :
// 6
// **************************************
// Press 1 : Insert
// Press 2 : Delete
// Press 3 : Display
// Press 4 : Insert At Any position
// Press 5 : Exit
// **************************************
// Enter Your Choice :
// 1
// Enter the element you want to insert :
// 9
// **************************************
// Press 1 : Insert
// Press 2 : Delete
// Press 3 : Display
// Press 4 : Insert At Any position
// Press 5 : Exit
// **************************************
// Enter Your Choice :
// 1
// Enter the element you want to insert :
// 10
// **************************************
// Press 1 : Insert
// Press 2 : Delete
// Press 3 : Display
// Press 4 : Insert At Any position
// Press 5 : Exit
// **************************************
// Enter Your Choice :
// 1
// Enter the element you want to insert :
// 5
// **************************************
// Press 1 : Insert
// Press 2 : Delete
// Press 3 : Display
// Press 4 : Insert At Any position
// Press 5 : Exit
// **************************************
// Enter Your Choice :
// 1
// Enter the element you want to insert :
// 7
// **************************************
// Press 1 : Insert
// Press 2 : Delete
// Press 3 : Display
// Press 4 : Insert At Any position
// Press 5 : Exit
// **************************************
// Enter Your Choice :
// 2
// Enter the element you want to delete :
// 7
// Element was not there
// **************************************
// Press 1 : Insert
// Press 2 : Delete
// Press 3 : Display
// Press 4 : Insert At Any position
// Press 5 : Exit
// **************************************
// Enter Your Choice :
// 3
// 3 6 9 10 5 7
// **************************************
// Press 1 : Insert
// Press 2 : Delete
// Press 3 : Display
// Press 4 : Insert At Any position
// Press 5 : Exit
// **************************************
// Enter Your Choice :
// 4
// Enter the element you want to insert :
// 7
// Enter the position of element you want to insert :
// 3
// 3 6 7 9 10 5 7