#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int direcx[4] = {0, 0, 1, -1};
int direcy[4] = {1, -1, 0, 0};
int N, M;
int visited[301][301] = {0};
int num[301][301] = {0};
int num2[301][301] = {0};
int ans = 0;
int checkcount = 0;

void bfs(int x, int y)
{

    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = checkcount;

    while (!q.empty())
    {
        int fx = q.front().first;
        int fy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int dx = fx + direcx[i];
            int dy = fy + direcy[i];
            if (dx < 0 || dx >= N || dy < 0 || dy >= M)
            {
                continue;
            }
            else
            {
                if (visited[dx][dy] == 0 && num[dx][dy] > 0)
                {
                    visited[dx][dy] = checkcount;
                    q.push({dx, dy});
                }
            }
        }
    }
}

int check()
{

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (num[i][j] != 0 && visited[i][j] == 0)
            {
                checkcount++;
                // cout << checkcount;
                bfs(i, j);
            }
        }
    }

    if (checkcount >= 2)
    {
        return 1;
    }
    else
    {
        checkcount = 0;
        return 0;
    }
}

void melt(int sx, int sy)
{
    int ccount = 0;
    for (int i = 0; i < 4; i++)
    {
        int dx = sx + direcx[i];
        int dy = sy + direcy[i];
        if (dx < 0 || dx >= N || dy < 0 || dy >= M)
        {
            continue;
        }
        else
        {
            if (num[dx][dy] == 0)
            {
                ccount++;
            }
        }
    }
    num2[sx][sy] = num2[sx][sy] - ccount;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int a;
            cin >> a;
            num[i][j] = a;
            num2[i][j] = a;
        }
    }

    while (true)
    {
        int a = check();

        if (a == 1)
        {
            break;
        }
        int zcount = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (num[i][j] != 0)
                {
                    zcount = 1;
                    melt(i, j);
                }
            }
        }
        if (zcount == 0)
        {
            ans = 0;
            break;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (num[i][j] != num2[i][j])
                {
                    num[i][j] = num2[i][j];
                    if (num[i][j] < 0)
                    {
                        num[i][j] = 0;
                    }
                }
            }
        }

        // for (int i = 0; i < N; i++)
        // {
        //     for (int j = 0; j < M; j++)
        //     {
        //         cout << num[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        ans++;
    }
    cout << ans;
}