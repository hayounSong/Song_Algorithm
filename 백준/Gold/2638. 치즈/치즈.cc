#include <iostream>
#include <queue>
using namespace std;

int N, M;
int num[101][101] = {0};
int imsi[101][101] = {0};
int visited[101][101] = {0};
int direcx[4] = {0, 0, 1, -1};
int direcy[4] = {1, -1, 0, 0};

void gakb(int sx, int sy)
{

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
            else if (visited[dx][dy] != 0)
            {
                continue;
            }
            else if (num[dx][dy] == 0)
            {
                q.push({dx, dy});
                visited[dx][dy] = 1;
            }
        }
    }
}

void bfs(int sx, int sy)
{
    int ccount = 0;

    for (int i = 0; i < 4; i++)
    {
        int dx = sx + direcx[i];
        int dy = sy + direcy[i];
        if (dx < 0 || dy < 0 || dx >= N || dy >= M)
        {
            continue;
        }
        if (num[dx][dy] == 0 && visited[dx][dy] != 0)
        {
            ccount++;
        }
    }
    if (ccount >= 2)
    {
        imsi[sx][sy] = 0;
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> num[i][j];
        }
    }
    int ttime = 0;
    while (true)
    {
        int chec = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                imsi[i][j] = num[i][j];
                visited[i][j] = 0;
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (visited[i][0] == 0)
            {
                gakb(i, 0);
            }
            if (visited[i][M - 1] == 0)
            {
                gakb(i, M - 1);
            }
        }
        for (int i = 0; i < M; i++)
        {
            if (visited[0][i] == 0)
            {
                gakb(0, i);
            }
            if (visited[N - 1][0] == 0)
            {
                gakb(N - 1, i);
            }
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (num[i][j] == 1)
                {
                    chec = 1;
                    bfs(i, j);
                }
            }
        }
        if (chec == 1)
        {
            ttime++;
            for (int i = 0; i < N; i++)
            {
                // cout << endl;
                for (int j = 0; j < M; j++)
                {
                    num[i][j] = imsi[i][j];
                    // cout << num[i][j] << " ";
                }
            }
        }
        else
        {
            cout << ttime;
            break;
        }
    }
}