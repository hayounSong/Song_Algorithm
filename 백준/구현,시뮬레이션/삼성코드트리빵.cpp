#include <iostream>
#include <queue>
using namespace std;

int n, m;
int home[16][16];
int t = 0;
int complete = 0;
pair<int, int> want[900] = {{-1, -1}};
pair<int, int> start[900] = {{999, 999}};
int visited[300][16][16];
int direcx[4] = {-1, 0, 0, 1};
int direcy[4] = {0, -1, 1, 0};
pair<int, int> where[999] = {{-1, -1}};

void move(int i)
{
    int v = i;
    int sx = want[v].first;
    int sy = want[v].second;
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            visited[i][j][k] = 0;
        }
    }
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[v][sx][sy] = 1;
    while (!q.empty())
    {

        int fx = q.front().first;
        int fy = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int px = fx + direcx[i];
            int py = fy + direcy[i];

            if (px >= 0 && py >= 0 && px < n && py < n)
            {
                if (visited[v][px][py] == 0 && home[px][py] != -1)
                {
                    q.push({px, py});
                    visited[v][px][py] = visited[v][fx][fy] + 1;
                }
            }
        }
    }
}

void place()
{

    if (t > m)
    {

        return;
    }
    else
    {
        move(t);
        int mind = 99999;
        int minx, miny;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (home[i][j] == 1)
                {
                    if (visited[t][i][j] < mind && visited[t][i][j] != 0)
                    {
                        mind = visited[t][i][j];
                        minx = i;
                        miny = j;
                    }
                }
            }
        }
        home[minx][miny] = -1;
        start[t] = {minx, miny};
        where[t] = {minx, miny};
        // cout << t << " " << minx << " " << miny << "\n";
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> home[i][j];
        }
    }

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        want[i] = {a - 1, b - 1};
    }
    for (int i = 0; i <= m; i++)
    {
        where[i].first = 999;
        where[i].second = 999;
    }
    while (true)
    {
        t++;
        for (int i = 1; i <= m; i++)
        {

            if (where[i].first == 999 || (where[i].first == want[i].first && where[i].second == want[i].second))
            {

                continue;
            }

            move(i);
            int min = 9999;
            int mx, my;
            int px = where[i].first;
            int py = where[i].second;

            for (int j = 0; j < 4; j++)
            {
                int dx = px + direcx[j];
                int dy = py + direcy[j];

                if (dx >= 0 && dy >= 0 && dx < n && dy < n)
                {
                    if (visited[i][dx][dy] < min && home[dx][dy] != -1 && visited[i][dx][dy] != 0)
                    {

                        min = visited[i][dx][dy];
                        mx = dx;
                        my = dy;
                    }
                }
            }
            // cout << i << " " << mx << " " << my << " ";
            where[i] = {mx, my};
        }

        for (int i = 1; i <= m; i++)
        {
            if (where[i].first == want[i].first && where[i].second == want[i].second)
            {
                home[where[i].first][where[i].second] = -1;
            }
        }

        int isEnd = 1;
        for (int i = 1; i <= m; i++)
        {
            if (where[i].first != want[i].first || where[i].second != want[i].second)
            {
                isEnd = 0;
            }
        }
        if (isEnd == 1)
        {

            break;
        }

        place();
    }
    cout << t;
    // for (int i = 1; i <= m; i++)
    // {
    //     t++;
    //     place();
    // }
    // for (int i = 1; i <= m; i++)
    // {
    //     move(i);
    // }

    // int ans = 0;

    // for (int i = 1; i <= m; i++)
    // {
    //     if (i + visited[i][want[i].first][want[i].second] > ans)
    //     {
    //         ans = i + visited[i][want[i].first][want[i].second];
    //     }
    // }
    // cout << ans;
}
