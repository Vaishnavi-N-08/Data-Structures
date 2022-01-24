#include <iostream>
#include "C:\ADS\infixTOPost.cpp"
using namespace std;
class node;
class Stack;
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

    bool empty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
};

class node
{
public:
    char data;
    node *left;
    node *right;

    node *Expression_treee(string postfix)
    {
        Stack node_st;
        for (int i = 0; i < postfix.size(); i++)
        {
            node *nev = getNode();
            nev->data = postfix[i];
            if (isalpha(postfix[i]))
            {
                node_st.push(nev);
            }
            else
            {
                nev->right = node_st.pop();
                nev->left = node_st.pop();
                node_st.push(nev);
            }
        }
        node *temp1 = node_st.pop();
        return temp1;
    }

    node *getNode()
    {
        node *nev = new node;
        nev->left = nev->right = NULL;
        return nev;
    }

    void inOrder(node *Root)
    {
        if (Root != NULL)
        {
            inOrder(Root->left);
            cout << Root->data;
            inOrder(Root->right);
        }
    }

    void Inorder_iterative(node *root)
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

    void preorder_iterative(node *root)
    {
        Stack sc;
        node *currentNode = root;
        while (currentNode != NULL || sc.empty() == false)
        {
            while (currentNode != NULL)
            {
                sc.push(currentNode);

                cout << currentNode->data << " ";
            }
            currentNode = sc.Top();
            sc.pop();
            currentNode = currentNode->left;
            currentNode = currentNode->right;
        }
    }

    void postorder_iterative(node *root)
    {
        Stack sc;
        node *currentNode = root;
        while (currentNode != NULL || sc.empty() == false)
        {
            while (currentNode != NULL)
            {
                sc.push(currentNode);
                cout << currentNode->data << " ";
            }
            currentNode = sc.Top();
            sc.pop();
            currentNode = currentNode->left;
            currentNode = currentNode->right;
        }
    }
};

int main()
{

    // infix to postfix

    string s;
    cout << "Enter operation: ";
    cin >> s;
    s = infixToPostfix(s);
    cout << s;

    //create tree

    node root;
    node *Root;
    Root = root.Expression_treee(s);
    //cout<<endl<<Root->data;
    cout << endl;
    root.inOrder(Root);
    cout << "iterative" << endl;
    root.Inorder_iterative(Root);
    root.preorder_iterative(Root);
    root.postorder_iterative(Root);

    return 0;
}
