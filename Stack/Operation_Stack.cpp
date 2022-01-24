#include<iostream>
#include <math.h>
#include"C:\ADS\Interger.cpp"
#include"C:\ADS\CharStack.cpp"
#include<string.h>
#include<algorithm>
using namespace std;

class operation
{
    public:

int prec(char c)
{
    if(c== '^')
    {
        return 5;
    }
    else if(c =='*' || c=='/')
    {
        return 4;
    }
    else if(c =='+' || c=='-')
    {
        return 2;
    }
    else{
        return -1;
    }
}

string infixtoprefix(string s)
{
      Stack_Char st;
      string res;
      reverse(s.begin(),s.end());
       for(int i=0;i<s.length();i++)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
        {
          res+=s[i];
        }
        else if(s[i]==')')
        {
            st.push(s[i]);
        }
        else if(s[i]=='(')
        {
           while(!st.empty() && st.Top() != ')')
           {
               res+=st.Top();
               st.pop();
           }
           if(!st.empty())
           {
               st.pop();
           }
        }
        else{
            while(!st.empty() && prec(st.Top())>prec(s[i]))
            {
                res+=st.Top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        res+=st.Top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    return res;

}
int prefixEvaluation(string s)
{ 
    Stack_Int st;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]>='0' && s[i]<='9')
        {
           st.push(s[i]-'0');
            
        }
         
        else{
        
            int op1 = st.Top();
            st.pop();
            int op2 = st.Top();
            st.pop();
              
            switch(s[i])
            {
                case '+':
                      st.push(op1 + op2);
                      break;
                 case '-':
                      st.push(op1 - op2);
                      break;
                 case '/':
                      st.push(op1 / op2);
                      break;
                 case '*':
                     st.push(op1 * op2);
                      break;
                 case '^':
                      st.push(pow(op1,op2));
                      break;
            }
        }
    }
   
    return st.Top();
}
string infixToPostfix(string s)
{
    Stack_Char st;
    string res;

    for(int i=0;i<s.length();i++)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
        {
          res+=s[i];
        }
        else if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
           while(!st.empty() && st.Top() != '(')
           {
               res+=st.Top();
               st.pop();
           }
           if(!st.empty())
           {
               st.pop();
           }
        }
        else{
            while(!st.empty() && prec(st.Top())>prec(s[i]))
            {
                res+=st.Top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        res+=st.Top();
        st.pop();
    }
    return res;
}

int postfixEvaluation(string s)
{ 
    Stack_Int st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
           st.push(s[i]-'0');
            
        }
         
        else{
        
            int op2 = st.Top();
            st.pop();
            int op1 = st.Top();
            st.pop();
              
            switch(s[i])
            {
                case '+':
                      st.push(op1 + op2);
                      break;
                 case '-':
                      st.push(op1 - op2);
                      break;
                 case '/':
                      st.push(op1 / op2);
                      break;
                 case '*':
                     st.push(op1 * op2);
                      break;
                 case '^':
                      st.push(pow(op1,op2));
                      break;
            }
        }
    }
   
    return st.Top();
}

};

int main(){
  
    operation op;
    string s1,s2,s3,s4;

    int choice;
    while(choice != 5)
    {   cout<<"*********************************************"<<endl;
        cout<<"What you want to do"<<endl;
        cout<<"Press 1 : Infix to postfix"<<endl;
        cout<<"press 2 : Infix to prefix"<<endl;
        cout<<"Press 3 : Postfix evaluation"<<endl;
        cout<<"Press 4 : Prefix evaluation"<<endl;
        cout<<"Press 5 : Exit"<<endl;
        cout<<"*********************************************"<<endl;

        cout<<"Enter Your choice :";
        cin>>choice; 
        cout<<endl;

        switch(choice)
        {
            case 1:
              {
                cout<<"Enter your Expression : ";
                cin>>s1;
                cout<<op.infixToPostfix(s1)<<endl;
                break;
              }
            case 2:
            {
                cout<<"Enter your Expression : ";
                cin>>s2;
                cout<<op.infixtoprefix(s2)<<endl;
                break;
            }
            case 3:
            {
                cout<<"Enter your Expression : ";
                cin>>s3;
                cout<<op.postfixEvaluation(s3)<<endl;
                break;
            }
            case 4:
            {
                cout<<"Enter your Expression : ";
                cin>>s4;
                cout<<op.prefixEvaluation(s4)<<endl;
                break;
            case 5:
            {
                cout<<"Exited successfully";
                break;
            }        
        }
    };
  
  
    
    }

}

//OUTPUT
// PS C:\ADS> cd "c:\ADS\" ; if ($?) { g++ Operation_Stack.cpp -o Operation_Stack } ; if ($?) { .\Operation_Stack }
// *********************************************
// What you want to do
// Press 1 : Infix to postfix
// press 2 : Infix to prefix
// Press 3 : Postfix evaluation
// Press 4 : Prefix evaluation
// Press 5 : Exit
// *********************************************
// Enter Your choice :1

// Enter your Expression : (a-b/c)*(a/k-l)
// abc/-ak/l-*
// *********************************************
// What you want to do
// Press 1 : Infix to postfix
// press 2 : Infix to prefix
// Press 3 : Postfix evaluation
// Press 4 : Prefix evaluation
// Press 5 : Exit
// *********************************************
// Enter Your choice :2

// Enter your Expression : (a-b/c)*(a/k-l)
// *-a/bc-/akl
// *********************************************
// What you want to do
// Press 1 : Infix to postfix
// press 2 : Infix to prefix
// Press 3 : Postfix evaluation
// Press 4 : Prefix evaluation
// Press 5 : Exit
// *********************************************
// Enter Your choice :3

// Enter your Expression : 46+2/5*7+
// 32
// *********************************************
// What you want to do
// Press 1 : Infix to postfix
// press 2 : Infix to prefix
// Press 3 : Postfix evaluation
// Press 4 : Prefix evaluation
// Press 5 : Exit
// *********************************************
// Enter Your choice :4

// Enter your Expression : -+7*45+20
// 25
// *********************************************
// What you want to do
// Press 1 : Infix to postfix
// press 2 : Infix to prefix
// Press 3 : Postfix evaluation
// Press 4 : Prefix evaluation
// Press 5 : Exit
// *********************************************
// Enter Your choice :5

// Exited successfully
// PS C:\ADS> 