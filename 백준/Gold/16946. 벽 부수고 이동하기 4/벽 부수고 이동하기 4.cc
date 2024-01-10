#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int visited[1001][1001] = {0};
int num[1001][1001] = {0};

int direcx[4] = {0, 0, 1, -1};
int direcy[4] = {1, -1, 0, 0};
int maxicount[10000001] = {0};
int maxi = 0;
void bfs(int startx, int starty)
{
    visited[startx][starty] = 1;
    queue<pair<int, int>> q;

    maxi++;
    int ccount = 0;
    q.push({startx, starty});
    visited[startx][starty] = maxi;
    while (!q.empty())
    {
        int qx = q.front().first;
        int qy = q.front().second;
        ccount++;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int dx = qx + direcx[i];
            int dy = qy + direcy[i];
            if (dx < 0 || dx >= N || dy < 0 || dy >= M)
            {
                continue;
            }
            else if (visited[dx][dy] != 0 || num[dx][dy] != 0)
            {
                continue;
            }
            else
            {
                q.push({dx, dy});
                visited[dx][dy] = maxi;
            }
        }
    }
    maxicount[maxi] = ccount;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        char s[M + 1];
        cin >> s;
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = 0;
            num[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (num[i][j] == 0 && visited[i][j] == 0)
            {
                bfs(i, j);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int sum = 1;
            if (num[i][j] == 1)
            {
                vector<int> maxiv;
                for (int ii = 0; ii < 4; ii++)
                {
                    int dx = direcx[ii] + i;
                    int dy = direcy[ii] + j;
                    if (dx < 0 || dx >= N || dy < 0 || dy >= M)
                    {
                        continue;
                    }
                    else if (num[dx][dy] != 0)
                    {
                        continue;
                    }
                    else
                    {
                        auto it = find(maxiv.begin(), maxiv.end(), visited[dx][dy]);
                        if (it == maxiv.end())
                        {
                            maxiv.push_back(visited[dx][dy]);
                            sum = sum + maxicount[visited[dx][dy]];
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
                num[i][j] = sum % 10;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << num[i][j] % 10;
        }
        cout << "\n";
    }
}