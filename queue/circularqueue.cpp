#include <iostream>
#define n 50
using namespace std;
class Circular_Queue
{

    int *arr;
    int front;
    int back;

public:
    Circular_Queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void insert(int x)
    {
        if ((front == 0 && back == n - 1) || (back + 1 == front))
        {
            cout << "Queue Overflow" << endl;
        }
        else
        {
            if (back == -1)
            {
                front = 0, back = 0;
            }
            else if (back == n - 1)
            {
                back = 0;
            }
            else
            {
                back++;
            }
            arr[back] = x;
        }
    }

    int delta()
    {
        int val;
        if (front == -1)
        {
            cout << "Queue underflow" << endl;
            return -1;
        }
        else
        {
            val = arr[front];
            if (front == back)
            {
                front = -1, back = -1;
            }
            else if (front == n - 1)
            {
                front = 0;
            }
            else
            {
                front++;
            }
            return val;
        }
    }

    void display()
    {
        int i, j;
        if (front == -1 && back == -1)
        {
            cout << "underflow";
        }
        if (front > back)
        {
            for (i = front; i < n; i++)
            {
                cout << arr[i]<<" ";
            }
            for (j = 0; j <= back; j++)
            {
                cout << arr[j]<<" ";
            }
        }
        else
        {
            for (i = front; i <= back; i++)
            {
                cout << arr[i]<<" ";
            }
        }
        cout << endl;
    }
};

int main()
{
    Circular_Queue cq1;
    int choice;

    while (choice != 4)
    {
        cout << "--------------------------------------"<<endl;
        cout << "Press 1 : To insert an element" << endl;
        cout << "Press 2 : To delete an element" << endl;
        cout << "Press 3 : To display an element" << endl;
        cout << "Press 4 : exit" << endl;

        cout << "Enetr your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int element;
            cout << "Enter the element you want to insert: ";
            cin >> element;
            cq1.insert(element);
            break;
        }

        case 2:
        {
            cq1.delta();
            break;
        }

        case 3:
        {
            cq1.display();
            break;
        }

        case 4:
        {
            break;
        }
        }
    }
}
//OUTPUT
// PS C:\ADS> cd "c:\ADS\" ; if ($?) { g++ circularqueue.cpp -o circularqueue } ; if ($?) { .\circularqueue }
// --------------------------------------
// Press 1 : To insert an element        
// Press 2 : To delete an element        
// Press 3 : To display an element       
// Press 4 : exit
// Enetr your choice : 1
// Enter the element you want to insert: 4
// --------------------------------------
// Press 1 : To insert an element        
// Press 2 : To delete an element        
// Press 3 : To display an element       
// Press 4 : exit
// Enetr your choice : 1
// Enter the element you want to insert: 5
// --------------------------------------
// Press 1 : To insert an element        
// Press 2 : To delete an element        
// Press 3 : To display an element       
// Press 4 : exit
// Enetr your choice : 1
// Enter the element you want to insert: 6
// --------------------------------------
// Press 1 : To insert an element
// Press 2 : To delete an element
// Press 3 : To display an element
// Press 4 : exit
// Enetr your choice : 1
// Enter the element you want to insert: 7
// --------------------------------------
// Press 1 : To insert an element
// Press 2 : To delete an element
// Press 3 : To display an element
// Press 4 : exit
// Enetr your choice : 2
// --------------------------------------
// Press 1 : To insert an element
// Press 2 : To delete an element
// Press 3 : To display an element
// Press 4 : exit
// Enetr your choice : 3
// 5 6 7 
// --------------------------------------
// Press 1 : To insert an element
// Press 2 : To delete an element
// Press 3 : To display an element
// Press 4 : exit
// Enetr your choice : 4
// PS C:\ADS> 