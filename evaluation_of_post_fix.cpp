#include<bits/stdc++.h>
using namespace std;
int power(int base, int exp)
{
    if(exp == 1)
    {
        return base;
    }
    else
    {
        return base * power(base, exp-1);
    }
}
int main()
{
    string str;
    int len, i=0, num, first, second, value;
    stack<int> stk;
    printf("Give the postfix expression\n");
    cin >> str;
    len = str.length();
    //printf("length = %d\n", len);
    str.append(") ");
    while(str[i] != ')')
    {
        if (isdigit(str[i]))
        {
          num = str[i] - '0';
          stk.push(num);
        }
        else if(str[i] == '+')
        {
            first = stk.top();
            stk.pop();
            second = stk.top();
            stk.pop();
            second = second+first;
            stk.push(second);
        }

        else if(str[i] == '-')
        {
            first = stk.top();
            stk.pop();
            second = stk.top();
            stk.pop();
            second = second-first;
            stk.push(second);
        }

        else if(str[i] == '*')
        {
            first = stk.top();
            stk.pop();
            second = stk.top();
            stk.pop();
            second = second*first;
            stk.push(second);
        }

        else if(str[i] == '/')
        {
            first = stk.top();
            stk.pop();
            second = stk.top();
            stk.pop();
            second = second/first;
            stk.push(second);
        }
        else if(str[i] == '^')
        {
            first = stk.top();
            stk.pop();
            second = stk.top();
            stk.pop();
            second = power(second, first);
            stk.push(second);
        }
        i++;
    }

    value = stk.top();
    printf("value = %d\n", value);


}
