/*
括号匹配
给定一个字符串，里边可能包含“()”、“[]”、“{}”三种括号，请编写程序检查该字符串中的括号是否成对出现，且嵌套关系正确。
输出：true:若括号成对出现且嵌套关系正确，或该字符串中无括号字符；
false:若未正确使用括号字符。
实现时，无需考虑非法输入。
输入描述：
输入为：
字符串
例子：(1+2)/(0.5+1)
输出描述：
输出为：
字符串
例子：true
*/

# include <iostream>
# include <cstring>
# include <stack>

using namespace std;

int match(char &a, char &b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    else if (a == '[' && b == ']')
    {
        return 2;
    }
    else if (a == '{' && b == '}')
    {
        return 3;
    }
    return 0;
}

int main()
{
    string str;
    stack<char> ops;
    int tag = 0;

    cin >> str;

    for (int i = 0; i < str.length();i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            ops.push(str[i]);
        }

        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (ops.empty())
            {
                cout << "fault" << endl;
                system("pause");
                return 0;
            }

            char left = ops.top();
            ops.pop();
            int tmp = match(left, str[i]);

            if (tmp>=tag)
            {
                tag = tmp;
            }
            else
            {
                cout << "false" << endl;
                system("pause");
                return 0;
            }
        }

    }
    cout << "true" << endl;
    system("pause");
    return 0;
}

