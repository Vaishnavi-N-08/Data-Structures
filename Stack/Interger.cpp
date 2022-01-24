#include <iostream>
#define n 100
#define N 200
#include <math.h>
#include<string.h>
using namespace std;

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
