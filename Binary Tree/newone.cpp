#define n 100
#define N 200
#include <iostream>
#include <math.h>
// #include <string.h>
using namespace std;

class Stack_char;
class Stack;
class node;

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

    void pop()
    {
        if (top == -1)
        {
            cout << "No element to pop" << endl;
        }
        else
        {
            top = top - 1;
        }
        return;
    }

    char Top()
    {
        if (top == -1)
        {
            return 'z';
        }
        else
        {
            return arr[top];
        }
    }

    bool empty()
    {
        return top == -1;
    }
};

int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixToPostfix(string s)
{
    Stack_Char st;
    string res;

    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            res += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.Top() != '(')
            {
                res += st.Top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && prec(st.Top()) > prec(s[i]))
            {
                res += st.Top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        res += st.Top();
        st.pop();
    }
    return res;
}

// class node;
// class Stack;
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
        return;
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
         return;
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
                
                 currentNode = currentNode->left;
            }
            currentNode = sc.Top();
            sc.pop();
            currentNode = currentNode->right;
            cout << currentNode->data << " ";
            
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
    cout <<"Post fix expression of given input(infix expresion) == "<< s;

    //create tree

    node root;
    node *Root;
    Root = root.Expression_treee(s);
    //cout<<endl<<Root->data;
    cout << endl;
    // root.inOrder(Root);
    cout << "iterative" << endl;
    root.Inorder_iterative(Root);
    cout<<endl;
    // root.preorder_iterative(Root);
    root.postorder_iterative(Root);

    return 0;
}
