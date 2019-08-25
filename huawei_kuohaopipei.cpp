/*
����ƥ��
����һ���ַ�������߿��ܰ�����()������[]������{}���������ţ����д��������ַ����е������Ƿ�ɶԳ��֣���Ƕ�׹�ϵ��ȷ��
�����true:�����ųɶԳ�����Ƕ�׹�ϵ��ȷ������ַ������������ַ���
false:��δ��ȷʹ�������ַ���
ʵ��ʱ�����迼�ǷǷ����롣
����������
����Ϊ��
�ַ���
���ӣ�(1+2)/(0.5+1)
���������
���Ϊ��
�ַ���
���ӣ�true
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

