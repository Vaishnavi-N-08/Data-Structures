#include<iostream>
#include"C:\ADS\Stack_Functions.cpp"
#include<stack>
#include<math.h>
using namespace std;

int postfixEvaluation(string s)
{ 
    Stack st;
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


int main()
{
    
    cout<<postfixEvaluation("46+2/5*7+");
    return 0;
}