#include<iostream>
using namespace std;
# define n 20


class Stack_Int
{
public:
    int *arr;

    int top;


    Stack_Int()
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

    int pop()
    {
        int temp;
        if (top == -1)
        {
            cout << "No element to pop" << endl;
            temp =-1;
           
        }
        else{
            temp = arr[top];
            top--;
        }
        return temp;
        
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

    void Display()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return;
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
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }  
};
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
            front=0;
        }
        return;
    }

    int dequeue() // dequeue == pop == delete an element
    {
        int temp;
        if (front == -1)
        {
            cout << "Queue empty" << endl;
            return -1;
        }
        else if (front == back)
        {
            temp = arr[front];
            front = -1;
            back = -1;
            cout << "Queue empty" << endl;
            return temp;
        }
        else
        {
            temp = arr[front];
            front++;
            return temp;
        }
    }
};
