#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int num[9][9] = {0};
int visited[9][9] = {0};
vector<pair<int, int>> zero;
int maxi = 0;
int how = 0;
int direcx[4] = {0, 0, 1, -1};
int direcy[4] = {1, -1, 0, 0};
void bfs(int sx, int sy)
{
    visited[sx][sy] = 1;
    queue<pair<int, int>> q;

    q.push({sx, sy});

    while (!q.empty())
    {
        int fx = q.front().first;
        int fy = q.front().second;

        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int dx = fx + direcx[i];
            int dy = fy + direcy[i];
            if (dx < 0 || dy < 0 || dx >= N || dy >= M)
            {
                continue;
            }
            else
            {
                if (num[dx][dy] == 0 && visited[dx][dy] == 0)
                {
                    q.push({dx, dy});
                    visited[dx][dy] = 1;
                }
            }
        }
    }
}

void simul(int o, int t, int th)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    num[zero[o].first][zero[o].second] = 1;
    num[zero[t].first][zero[t].second] = 1;
    num[zero[th].first][zero[th].second] = 1;
    how = 0;
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
            if (num[i][j] == 2)
            {
                bfs(i, j);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (num[i][j] == 0 && visited[i][j] == 0)
            {
                ans++;
            }
        }
    }
    if (ans > maxi)
    {
        maxi = ans;
    }
    num[zero[o].first][zero[o].second] = 0;
    num[zero[t].first][zero[t].second] = 0;
    num[zero[th].first][zero[th].second] = 0;
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> num[i][j];
            if (num[i][j] == 0)
            {
                zero.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < zero.size(); i++)
    {
        for (int j = 0; j < zero.size(); j++)
        {
            if (i == j)
            {
                continue;
            }
            for (int z = 0; z < zero.size(); z++)
            {
                if (z == i || z == j)
                {
                    continue;
                }
                else
                {
                    simul(i, j, z);
                }
            }
        }
    }
    cout << maxi;
}