#include<iostream>
#include"C:\ADS\Stack_Functions.cpp"
#include<stack>
#include<math.h>
using namespace std;

int prefixEvaluation(string s)
{ 
    Stack st;
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


int main()
{
    
    cout<<prefixEvaluation("-+7*45+20");
    return 0;
}