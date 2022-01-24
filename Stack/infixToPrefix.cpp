#include<iostream>
// #include"C:\ADS\Stack_char.cpp"
#include"C:\ADS\Character.cpp"
#include<algorithm>
#include<math.h>
using namespace std;


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


int main()
{
   cout<<infixtoprefix("A + B * C");
   
}