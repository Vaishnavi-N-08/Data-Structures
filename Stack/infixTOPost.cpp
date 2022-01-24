#include <iostream>
// #include"C:\ADS\Stack_char.cpp"
#include "C:\ADS\CharStack.cpp"




using namespace std;

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

// int main()
// {

//     cout << infixToPostfix("(A*B+C*D)");
//     cout << endl;
// }