# include <iostream>
# include <unordered_set>
# include <cstring>

using namespace std;

int main()
{
    string s1, s2;
    unordered_set<char> ss;
    cin >> s1;
    for (auto i : s1)
    {
        ss.insert(i);
        //     if (ss.find(i) == ss.end())
        //     {
        //         ss.insert(i);
        //         s2.append(1, i);
        //     }
    }

    cout << ss << endl;
    system("pause");
    return 0;
}