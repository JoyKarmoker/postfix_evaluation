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

    int j;
    vector <string> str;
    char  tmp[100000];
    int len, num, first, second, value;
    stack<int> stk;
    printf("Enter Q to terminate.\n");
    printf("Give the postfix expression with space after operator and operand\n");
    for( j=0 ;; j++)
    {
        scanf("%s", tmp);
        if(strcmp(tmp, "Q") == 0 || strcmp(tmp, "q") == 0)
        {
            break;
        }
        str.push_back(tmp);
    }
    //printf("here\n");
    str.push_back(")");
    len = str.size();
    j = 0;
    while(str[j]!= ")")
    {
        if (isdigit(str[j][0]))
        {
            stringstream geek(str[j]);
            geek >> num;
            //num = atoi(str[j]);
            stk.push(num);
        }
        else if(str[j] == "+")
        {
            first = stk.top();
            stk.pop();
            second = stk.top();
            stk.pop();
            second = second+first;
            stk.push(second);
        }

        else if(str[j] == "-")
        {
            first = stk.top();
            stk.pop();
            second = stk.top();
            stk.pop();
            second = second-first;
            stk.push(second);
        }

        else if(str[j] == "*")
        {
            first = stk.top();
            stk.pop();
            second = stk.top();
            stk.pop();
            second = second*first;
            stk.push(second);
        }

        else if(str[j] == "/")
        {
            first = stk.top();
            stk.pop();
            second = stk.top();
            stk.pop();
            second = second/first;
            stk.push(second);
        }
        else if(str[j] == "^")
        {
            first = stk.top();
            stk.pop();
            second = stk.top();
            stk.pop();
            second = power(second, first);
            stk.push(second);
        }
        j++;
    }

    value = stk.top();
    printf("value = %d\n", value);


}

