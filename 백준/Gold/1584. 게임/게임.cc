#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int N, M;
int num[501][501] = {0};
int life[501][501] = {0};
int visited[501][501] = {0};
int direcx[4] = {0, 0, 1, -1};
int direcy[4] = {1, -1, 0, 0};
void bfs()
{
    int startx = 0;
    int starty = 0;

    queue<pair<int, int>> q;

    q.push({startx, starty});
    life[startx][starty] = 0;
    while (!q.empty())
    {

        int fx = q.front().first;
        int fy = q.front().second;

        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int dx = fx + direcx[i];
            int dy = fy + direcy[i];

            if (dx < 0 || dy < 0 || dx > 500 || dy > 500)
            {
                continue;
            }
            if (num[dx][dy] == 2)
            {
                continue;
            }

            if (num[dx][dy] == 0)
            {
                if (life[dx][dy] > life[fx][fy])
                {
                    life[dx][dy] = life[fx][fy];
                    q.push({dx, dy});
                }
            }
            else if (num[dx][dy] == 1)
            {
                if (life[dx][dy] > life[fx][fy] + 1)
                {
                    life[dx][dy] = life[fx][fy] + 1;
                    q.push({dx, dy});
                }
            }
        }
    }
}
int main()
{
    cin >> N;
    for (int i = 0; i <= 500; i++)
    {
        for (int j = 0; j <= 500; j++)
        {
            life[i][j] = 999999;
        }
    }
    for (int v = 0; v < N; v++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        for (int i = min(a, c); i <= max(a, c); i++)
        {
            for (int j = min(b, d); j <= max(b, d); j++)
            {
                num[i][j] = 1;
            }
        }
    }
    cin >> M;
    for (int v = 0; v < M; v++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        for (int i = min(a, c); i <= max(a, c); i++)
        {
            for (int j = min(b, d); j <= max(b, d); j++)
            {
                num[i][j] = 2;
            }
        }
    }
    bfs();
    if (life[500][500] == 999999)
    {
        cout << -1;
    }
    else
    {
        cout << life[500][500];
    }
}