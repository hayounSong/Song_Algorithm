#include <iostream>
#include <queue>
using namespace std;

int num[1005][1005] = {0};
int N, M;
int direcx[4] = {0, 0, 1, -1};
int direcy[4] = {1, -1, 0, 0};
long visited[3][1005][1005] = {0};
void bfs()
{
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {1, 1}});
    // q.push({1, {1, 1}});
    visited[0][1][1] = 1;
    // visited[1][1][1] = 1;

    while (!q.empty())
    {

        int frontx = q.front().second.first;
        int fronty = q.front().second.second;
        int fcrash = q.front().first;
        q.pop();
        if (fcrash == 0)
        {

            for (int i = 0; i < 4; i++)
            {
                int dx = frontx + direcx[i];
                int dy = fronty + direcy[i];

                if (num[dx][dy] == 2 && visited[1][dx][dy] == 0)
                {

                    visited[1][dx][dy] = visited[0][frontx][fronty] + 1;
                    q.push({1, {dx, dy}});
                }
                else if (num[dx][dy] == 1 && visited[0][dx][dy] == 0)
                {
                    visited[0][dx][dy] = visited[0][frontx][fronty] + 1;
                    q.push({0, {dx, dy}});
                }
            }
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                int dx = frontx + direcx[i];
                int dy = fronty + direcy[i];
                if (num[dx][dy] == 1 && visited[1][dx][dy] == 0)
                {
                    visited[1][dx][dy] = visited[1][frontx][fronty] + 1;
                    q.push({fcrash, {dx, dy}});
                }
            }
        }
    }
}
int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        char s[9000];
        cin >> s;
        for (int j = 0; j <= M; j++)
        {
            if (s[j] == '0')
            {
                num[i][j + 1] = 1;
            }
            else
            {
                num[i][j + 1] = 2;
            }
        }
    }
    bfs();

    if (visited[1][N][M] <= 0)
    {
        visited[1][N][M] = 987654321;
    }
    if (visited[0][N][M] <= 0)
    {
        visited[0][N][M] = 987654321;
    }

    int ans = min(visited[1][N][M], visited[0][N][M]);
    if (ans >= 987654321)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}