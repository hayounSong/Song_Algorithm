#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N, M;
int num[100][100] = {0};
int visited[100][100] = {0};
int mina = -1;

int direcx[4] = {0, 0, 1, -1};
int direcy[4] = {1, -1, 0, 0};
void bfs(int startx, int starty)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            visited[i][j] = 0;
        }
    }

    queue<pair<int, int>> q;

    q.push({startx, starty});
    visited[startx][starty] = 1;

    while (!q.empty())
    {

        int frontx = q.front().first;

        int fronty = q.front().second;
        // if (startx == 4 && starty == 1)
        // {
        //     cout << frontx << fronty << 's';
        // }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int dx = frontx + direcx[i];
            int dy = fronty + direcy[i];

            if (num[dx][dy] == 1 && dx > 0 && dx <= N && dy > 0 && dy <= M)
            {
                if (visited[dx][dy] == 0)
                {
                    visited[dx][dy] = visited[frontx][fronty] + 1;
                    if (visited[dx][dy] > mina)
                    {

                        mina = visited[dx][dy];
                        // if (mina == 3)
                        // {
                        // cout << visited[1][1] << visited[1][2]
                        // cout << startx << starty;
                        // }
                    }
                    q.push({dx, dy});
                }
            }
        }
    }
}
int main()
{
    cin >> N >> M;

    for (int i = 0; i <= N; i++)
    {
        string s;
        getline(cin, s);

        for (int j = 0; j < M; j++)
        {
            if (s[j] == 'L')
            {
                num[i][j + 1] = 1;
            }
            else
            {
                num[i][j + 1] = 2;
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {

        for (int j = 1; j <= M; j++)
        {
            if (num[i][j] == 1)
            {

                bfs(i, j);
            }
        }
    }
    if (mina == 0)
    {
        cout << 0;
    }
    else
    {
        cout << mina - 1;
    }
}