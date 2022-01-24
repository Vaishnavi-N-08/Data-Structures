#include <iostream>
#include "C:\ADS\Binary Tree\Character.cpp"
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Stack
{
public:
    int top;
    node *arr[20];

    Stack()
    {
        top = -1;
    }

    void push(node *a)
    {
        if (top == 20 - 1)
        {
            cout << "Stack overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = a;
        }
    }

    node *pop()
    {
        node *temp = arr[top];
        top--;
        return temp;
    }

    bool empty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    node *Top()
    {
        if (top == -1)
        {
            // cout << "No element to pop" << endl;
            return 0;
        }
        else
        {
            return arr[top];
        }
    }
};

void inorder(node *root)
{
    Stack sc;
    node *currentNode = root;
    while (currentNode != NULL || sc.empty() == false)
    {
       
        while (currentNode != NULL)
        {
           
            sc.push(currentNode);
            currentNode = currentNode->left;
        }
        
        currentNode = sc.Top();
        sc.pop();
        
        cout << currentNode->data << " ";
        
        currentNode = currentNode->right;
    }
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    inorder(root);
    return 0;
}
