# include <iostream>
# include <cstring>

# define M 1010

using namespace std;

int go[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int map[M][M];
bool vid[M][M];

int flag;

int n, m, q, i, j, x1, x2, y1, y2;

void dfs(int x,int y,int turns,int direction)
{
    if (flag)
        return;
    if (x > n || x < 1 || y > m || y < 1 || vid[x][y])
        return;
    if (turns==2 && x!=x2 && y!=y2)
        return;
    if (turns>2)
        return;
    if (x==x2 && y==y2 && turns<=2)
    {
        cout << "Yes" << endl;
        flag = 1;
        return;
    }

    if(map[x][y]!=0)
    {
        if (x == x1 && y == y1)
            ;
        else
            return;
    }

    vid[x][y] = 1;
    int dx, dy;
    for (int i = 0; i < 4;i++)
    {
        dx = x + go[i][0];
        dy = y + go[i][1];
        if (i==direction)
            dfs(dx, dy, turns, i);
        else
            dfs(dx, dy, turns + 1, i);
    }

    vid[x][y] = 0;
    return;
}

int main()
{
    void dfs(int x, int y, int turns, int direction);
    while (cin >> n >> m)
    {
        memset(vid, 0, sizeof(vid));
        if (n == 0 && m == 0)
        {
            break;
        }

        for (int i = 1; i <= n;i++)
        {
            for (int j = 1; j <= m;j++)
            {
                cin >> map[i][j];
            }
        }

        cin >> q;
        while(q--)
        {
            cin >> x1 >> y1 >> x2 >> y2;
            if (x1 == x2 && y1 == y2)
            {
                cout << "NO" << endl;
                continue;
            }
            if (x1 > n || x1 < 1 || x2 > n || x2 < 1 || y1 > m || y1 < 1 || y2 > m || y2 < 1)
            {
                cout << "NO" << endl;
                continue;
            }

            if (map[x1][y1] != map[x2][y2] || map[x1][y1] == 0)
            {
                cout << "NO" << endl;
                continue;
            }

            flag = 0;

            for (int i = 0; i < 4;i++)
            {
                dfs(x1, y1, 0, i);
                if (flag==true)
                    break;
            }
            if (flag==0)
                cout << "NO" << endl;
        }
    }
    system("pause");
    return 0;
}
