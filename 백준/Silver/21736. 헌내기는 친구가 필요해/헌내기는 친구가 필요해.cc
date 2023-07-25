#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int N, M;
int num[601][601];
int visited[601][601];
int startx, starty;
int direcx[4] = {0, 0, 1, -1};
int direcy[4] = {1, -1, 0, 0};
int ans = 0;
void bfs()
{
    queue<pair<int, int>> q;
    q.push({startx, starty});
    visited[startx][starty] = 1;

    while (!q.empty())
    {
        int firstx = q.front().first;
        int firsty = q.front().second;
        if (num[firstx][firsty] == 1)
        {
            ans++;
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int dx = firstx + direcx[i];
            int dy = firsty + direcy[i];

            if (dx < 0 || dy < 0 || dx >= N || dy >= M || num[dx][dy] == -1)
            {
                continue;
            }
            else
            {
                if (visited[dx][dy] == 0)
                {
                    q.push({dx, dy});
                    visited[dx][dy] = 1;
                }
            }
        }
    }
}
int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {

            if (s[j] == 'O')
            {
                num[i][j] = 0;
            }
            if (s[j] == 'X')
            {
                num[i][j] = -1;
            }
            if (s[j] == 'I')
            {
                num[i][j] = 0;
                startx = i;
                starty = j;
            }
            if (s[j] == 'P')
            {
                // cout << s[j];
                num[i][j] = 1;
            }
        }
    }

    bfs();
    if (ans == 0)
    {
        cout << "TT";
    }
    else
    {
        cout << ans;
    }
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         cout << num[i][j];
    //     }
    // }
}