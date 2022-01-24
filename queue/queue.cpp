#include <iostream>
#define n 20
using namespace std;

class queue
{
    int *arr;
    int front;
    int back;

public:
    queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }
    void enqueue(int x) // enqueue == push == insert an element
    {
        if (back == n - 1)
        {
            cout << "Overflow queue" << endl;
            return;
        }
        back++;
        arr[back] = x;
        if (front == -1)
        {
            front++;
        }
    }

    void dequeue() // dequeue == pop == delete an element
    {
        if (front == -1 || front > back)
        {
            cout << "No elements in queue" << endl;
        }
        front++;
    }

    int peek()
    {
        if (front == -1 || front > back)
        {
            cout << "No elements in queue" << endl;
            return -1;
        }
        return arr[front];
    }

    int Display()
    {
        int i;
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            for (i = front; i <= back; i++)
            {
                cout << arr[i] << " ";
            }
        }
    }

    bool empty()
    {
        if (front = -1 || front > back)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    queue q1;
    int choice;
    while (choice != 6)
    {
        cout << "_________________________________________________________" << endl;
        cout << "Press 1 : Insert the element in the queue" << endl;
        cout << "Press 2 : Delete the  element in the queue" << endl;
        cout << "Press 3 : Display the peek  element in the queue" << endl;
        cout << "Press 4 : Display all the element in the queue" << endl;
        cout << "Press 5 : To Check the queue is empty or not" << endl;
        cout << "Press 6 : Exit" << endl;
        cout << "_________________________________________________________" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            int val;
            cout << "Enter the element you want to insert : ";
            cin >> val;
            q1.enqueue(val);
            break;
        case 2:
            q1.dequeue();
            break;
        case 3:
            cout << q1.peek();
            cout << endl;
            break;
        case 4:
            q1.Display();
            cout << endl;
            break;
        case 5:
            cout << q1.empty();
            cout << endl;
            break;
        case 6:
            break;
        }
    };
}
// OUTPUT
//  PS C:\ADS> cd "c:\ADS\" ; if ($?) { g++ queue.cpp -o queue } ; if ($?) { .\queue }
//  _________________________________________________________
//  Press 1 : Insert the element in the queue
//  Press 2 : Delete the  element in the queue
//  Press 3 : Display the peek  element in the queue
//  Press 4 : Display all the element in the queue
//  Press 5 : To Check the queue is empty or not
//  Press 6 : Exit
//  _________________________________________________________
//  Enter your choice : 1

// Enter the element you want to insert : 4
// _________________________________________________________
// Press 1 : Insert the element in the queue
// Press 2 : Delete the  element in the queue
// Press 3 : Display the peek  element in the queue
// Press 4 : Display all the element in the queue
// Press 5 : To Check the queue is empty or not
// Press 6 : Exit
// _________________________________________________________
// Enter your choice : 1

// Enter the element you want to insert : 6
// _________________________________________________________
// Press 1 : Insert the element in the queue
// Press 2 : Delete the  element in the queue
// Press 3 : Display the peek  element in the queue
// Press 4 : Display all the element in the queue
// Press 5 : To Check the queue is empty or not
// Press 6 : Exit
// _________________________________________________________
// Enter your choice : 1

// Enter the element you want to insert : 9
// _________________________________________________________
// Press 1 : Insert the element in the queue
// Press 2 : Delete the  element in the queue
// Press 3 : Display the peek  element in the queue
// Press 4 : Display all the element in the queue
// Press 5 : To Check the queue is empty or not
// Press 6 : Exit
// _________________________________________________________
// Enter your choice : 1

// Enter the element you want to insert : 12
// _________________________________________________________
// Press 1 : Insert the element in the queue
// Press 2 : Delete the  element in the queue
// Press 3 : Display the peek  element in the queue
// Press 4 : Display all the element in the queue
// Press 5 : To Check the queue is empty or not
// Press 6 : Exit
// _________________________________________________________
// Enter your choice : 3

// 4
// _________________________________________________________
// Press 1 : Insert the element in the queue
// Press 2 : Delete the  element in the queue
// Press 3 : Display the peek  element in the queue
// Press 4 : Display all the element in the queue
// Press 5 : To Check the queue is empty or not
// Press 6 : Exit
// _________________________________________________________
// Enter your choice : 4

// 4 6 9 12
// _________________________________________________________
// Press 1 : Insert the element in the queue
// Press 2 : Delete the  element in the queue
// Press 3 : Display the peek  element in the queue
// Press 4 : Display all the element in the queue
// Press 5 : To Check the queue is empty or not
// Press 6 : Exit
// _________________________________________________________
// Enter your choice : 2

// _________________________________________________________
// Press 1 : Insert the element in the queue
// Press 2 : Delete the  element in the queue
// Press 3 : Display the peek  element in the queue
// Press 4 : Display all the element in the queue
// Press 5 : To Check the queue is empty or not
// Press 6 : Exit
// _________________________________________________________
// Enter your choice : 4

// 6 9 12
// _________________________________________________________
// Press 1 : Insert the element in the queue
// Press 2 : Delete the  element in the queue
// Press 3 : Display the peek  element in the queue
// Press 4 : Display all the element in the queue
// Press 5 : To Check the queue is empty or not
// Press 6 : Exit
// _________________________________________________________
// Enter your choice : 6

// PS C:\ADS>