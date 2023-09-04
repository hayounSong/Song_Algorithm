#include <iostream>
using namespace std;

int direcx[4] = {-1, 1, 0, 0};
int direcy[4] = {0, 0, -1, 1};
int ans = 0;
int visited[1001][1001] = {0};

int num[1001][1001] = {0};
int N, M;

void dfs(int startx, int starty)
{
    visited[startx][starty] = 1;
    int a = num[startx][starty];
    int dx;
    int dy;

    dx = startx + direcx[a];
    dy = starty + direcy[a];

    if (visited[dx][dy] == 0)
    {
        // if (startx == 0 && starty == 0)
        // {
        //     cout << dx << " " << dy << "\n";
        // }
        dfs(dx, dy);
    }

    for (int i = 0; i < 4; i++)
    {
        dx = startx - direcx[i];
        dy = starty - direcy[i];
        if (dx < 0 || dx >= N || dy < 0 || dy >= M)
        {
            continue;
        }
        else
        {
            if (num[dx][dy] == i && visited[dx][dy] == 0)
            {
                dfs(dx, dy);
            }
        }
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        char a[M + 5];
        cin >> a;

        for (int j = 0; j < M; j++)
        {
            if (a[j] == 'U')
            {
                num[i][j] = 0;
            }
            else if (a[j] == 'D')
            {
                num[i][j] = 1;
            }
            else if (a[j] == 'L')
            {
                num[i][j] = 2;
            }
            else if (a[j] == 'R')
            {
                num[i][j] = 3;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (visited[i][j] == 0)
            {
                // cout << i << " " << j << "\n";
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans;
}