#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, L, R;

int people[101][101];
int visited[101][101] = {0};
int ans = 0;
int pass = 1;
int direcx[4] = {0, -1, 0, 1};
int direcy[4] = {1, 0, -1, 0};

void bfs(int x, int y)
{
    int sum = 0;
    queue<pair<int, int>> record;
    queue<pair<int, int>> q;

    record.push({x, y});
    q.push({x, y});
    visited[x][y] = 1;
    sum = sum + people[x][y];
    while (!q.empty())
    {
        int fx = q.front().first;
        int fy = q.front().second;
        visited[fx][fy] = 1;
        q.pop();
        for (int v = 0; v < 4; v++)
        {
            int px = fx + direcx[v];
            int py = fy + direcy[v];

            if (px < 0 || px >= N || py < 0 || py >= N)
            {
                continue;
            }
            else
            {

                if (visited[px][py] == 1)
                {
                    continue;
                }
                else
                {

                    int min = abs(people[fx][fy] - people[px][py]);

                    if (min >= L && min <= R)
                    {

                        visited[px][py] = 1;

                        q.push({px, py});
                        record.push({px, py});

                        sum = sum + people[px][py];
                    }
                }
            }
        }
    }
    if (record.size() > 1)
    {
        sum = sum / record.size();
        int count = record.size();
        for (int i = 0; i < count; i++)
        {
            int px = record.front().first;
            int py = record.front().second;

            people[px][py] = sum;
            record.pop();
            pass = 1;
        }
    }
}

int main()
{
    cin >> N >> L >> R;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {

            cin >> people[i][j];
        }
    }

    while (true)
    {
        pass = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (visited[i][j] == 0)
                {

                    bfs(i, j);
                }
            }
        }

        if (pass == 1)
        {

            ans++;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    visited[i][j] = 0;
                }
            }
            continue;
        }
        else if (pass == 0)
        {
            break;
        }
    }

    cout << ans;
}