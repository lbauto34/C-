#include<iostream>
#include<algorithm>
#include<stack>
#include<cstring>

using namespace std;

int main()
{
    string str;
    stack<int> num;
    stack<char> ops;

    //cin >> str;
    getline(cin, str);

    int i = 0;

    while (i < str.length())
    {

        if (str[i]==' ')
        {
            i++;
        }
        
        if (str[i]==' ')
        {
            cout << -1 << endl;
            break;
        }

        if (str[i] == '(' || str[i] == ')' || str[i] == '^' || str[i] == '+' || str[i] == '*')
        {
            ops.push(str[i]);
            if (ops.top() == ')')
            {
                ops.pop();
                char a = ops.top();
                ops.pop();
                if (a == '^')
                {
                    int s = num.top();
                    num.pop();
                    num.push(s + 1);
                }
                else if (a == '+')
                {
                    int x = num.top();
                    num.pop();
                    int y = num.top();
                    num.pop();
                    num.push(x + y);
                }
                else if (a == '*')
                {
                    int x = num.top();
                    num.pop();
                    int y = num.top();
                    num.pop();
                    num.push(x * y);
                }
                else
                {
                    cout << -1 << endl;
                    break;
                }

                char b = ops.top();
                ops.pop();
                if (b!='(')
                {
                    cout << -1 << endl;
                    break;
                }
            }

            if (ops.empty())
            {
                int res = num.top();
                cout << res << endl;
                break;
            }

            i++;
        }

        else if (str[i] >= '0' && str[i] <= '9')
        {
            int t = i;
            while (str[i] >= '0' && str[i] <= '9')
            {
                i++;
            }

            if (t < i)
            {
                num.push(stoi(str.substr(t, i - t)));
                
            }
        }

        else
        {
            cout << -1 << endl;
            break;
        }
    }

    system("pause");
    return 0;
} 
