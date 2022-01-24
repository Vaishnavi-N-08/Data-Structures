#include <iostream>
#define n 100
#define N 200
#include <math.h>
#include<string.h>
using namespace std;

class Stack
{
public:
    int *arr;

    int top;


    Stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int x)
    {
    
        if (top == n - 1)
        {
            cout << "overflow" << endl;
        }
        top++;
        arr[top] = x;
        return;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "No element to pop" << endl;
            return;
        }

        top = top - 1;
    }

    int Top()
    {
        if (top == -1)
        {
            cout << "No element to pop" << endl;
            return -1;
        }
      
        return arr[top];
    }

    int Display()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << endl;
            }
        }
    }

    bool empty()
    {
        return top == -1;
    }

   
};


int main()
{
    Stack st;
    
    int choice;

    while (choice != 6)
    {
        cout << "****************************************" << endl;
        cout << "Press 1 : To push the element" << endl;
        cout << "Press 2 : To pop the element" << endl;
        cout << "Press 3 : To Display the element" << endl;
        cout << "Press 4 : To print topmost  the element" << endl;
         cout << "Press 5 : To Check stack is empty or not" << endl;
        cout << "Press 6 : Exit" << endl;
        cout << "****************************************" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int value;
            cout << "Enter the value you want to push : ";
            cin >> value;
            st.push(value);
            cout << endl;
            break;
        }
        case 2:
        {
            st.pop();
            cout << endl;
            break;
        }
        case 3:
        {
            st.Display();
            cout << endl;
            break;
        }
        case 4:
        {

            cout << "Topmost element in the stack is : " << st.Top() << endl;

            break;
        }
        case 5:
        {
             cout << "Exited Successfully"<< endl;
             break;
            
        }
        case 6:
        {
             cout << st.empty()<< endl;
             break;
            
        }


        default:
        {
            cout << "Enter a valid choice" << endl;
        }
    };
}

    return 0;
}

// OUTPUT

// PS C:\ADS> cd "c:\ADS\" ; if ($?) { g++ Stack_array.cpp -o Stack_array } ; if ($?) { .\Stack_array }
// ****************************************
// Press 1 : To push the element
// Press 2 : To pop the element
// Press 3 : To Display the element        
// Press 4 : To print topmost  the element 
// Press 5 : To Check stack is empty or not
// Press 6 : Exit
// ****************************************
// Enter your choice : 1
// Enter the value you want to push : 3

// ****************************************
// Press 1 : To push the element
// Press 2 : To pop the element
// Press 3 : To Display the element
// Press 4 : To print topmost  the element
// Press 5 : To Check stack is empty or not
// Press 6 : Exit
// ****************************************
// Enter your choice : 1
// Enter the value you want to push : 5

// ****************************************
// Press 1 : To push the element
// Press 2 : To pop the element
// Press 3 : To Display the element
// Press 4 : To print topmost  the element
// Press 5 : To Check stack is empty or not
// Press 6 : Exit
// ****************************************
// Enter your choice : 1
// Enter the value you want to push : 7

// ****************************************
// Press 1 : To push the element
// Press 2 : To pop the element
// Press 3 : To Display the element
// Press 4 : To print topmost  the element
// Press 5 : To Check stack is empty or not
// Press 6 : Exit
// ****************************************
// Enter your choice : 1
// Enter the value you want to push : 8

// ****************************************
// Press 1 : To push the element
// Press 2 : To pop the element
// Press 3 : To Display the element
// Press 4 : To print topmost  the element
// Press 5 : To Check stack is empty or not
// Press 6 : Exit
// ****************************************
// Enter your choice : 2

// ****************************************
// Press 1 : To push the element
// Press 2 : To pop the element
// Press 3 : To Display the element
// Press 4 : To print topmost  the element
// Press 5 : To Check stack is empty or not
// Press 6 : Exit
// ****************************************
// Enter your choice : 3
// 7
// 5
// 3

// ****************************************
// Press 1 : To push the element
// Press 2 : To pop the element
// Press 3 : To Display the element
// Press 4 : To print topmost  the element
// Press 5 : To Check stack is empty or not
// Press 6 : Exit
// ****************************************
// Enter your choice : 5
// Exited Successfully
// ****************************************
// Press 1 : To push the element
// Press 2 : To pop the element
// Press 3 : To Display the element
// Press 4 : To print topmost  the element
// Press 5 : To Check stack is empty or not
// Press 6 : Exit
// ****************************************
// Enter your choice : 6
// 0
// PS C:\ADS> 