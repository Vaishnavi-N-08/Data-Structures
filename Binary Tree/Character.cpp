#define n 100
#define N 200
#include<iostream>
#include <math.h>
#include<string.h>
using namespace std;

class Stack_Char
{
public:
    char *arr;

    int top;


    Stack_Char()
    {
        arr = new char[n];
        top = -1;
    }

    void push(char x)
    {
    
        if (top == n - 1)
        {
            cout << "overflow" << endl;
        }
        else
        {
              top++;
              arr[top] = x;
        }
      
        return;
    }

       char pop()
    {
        char temp;
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

    char Top()
    {
        if (top == -1)
        {
            // cout << "No element to pop" << endl;
            return '0';
        }
       else{
           return arr[top];
       }
        
    }

    // char Display()
    // {
    //     if (top == -1)
    //     {
    //         cout << "Stack is empty" << endl;
    //     }
    //     else
    //     {
    //         for (int i = top; i >= 0; i--)
    //         {
    //             cout << arr[i] << endl;
    //         }
    //     }
    // }

    bool empty()
    {
        return top == -1;
    }

   
};
