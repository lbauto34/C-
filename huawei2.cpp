//ÌâÄ¿¼û£º
//https://blog.csdn.net/Jeff_Winger/article/details/81778329

# include <iostream>

using namespace std;

int main()
{
    int arr, lea;
    int b[9]{0};
    while(true)
    {
        cin >> arr;
        if (cin.get() == ',')
        {
            cin >> lea;
        }

        if (arr == -1 && lea == -1)
        {
            break;
        }

        for (int i = (arr-11); i < (lea-11);i++)
        {
            b[i] = b[i] + 1;
        }
    }

    for (int i = 1; i < 9;i++)
    {
        cout << "[" << i + 11 << "," << i + 12 << ")"<< ":" << b[i] << endl;
    }
    system("pause");
    return 0;
}