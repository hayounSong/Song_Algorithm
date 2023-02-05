#include <iostream>
#include <queue>
using namespace std;

int N, M, H;
int fruit[101][101][101]; // H M N
int visited[101][101][101];
int direci[6] = {0, 0, 0, 0, -1, 1};
int direcj[6] = {0, -1, 0, 1, 0, 0};
int direcy[6] = {1, 0, -1, 0, 0, 0};
queue<pair<pair<int, int>, int>> q;
void bfs()
{

    while (!q.empty())
    {

        int fronti = q.front().first.first;
        int frontj = q.front().first.second;
        int fronty = q.front().second;
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int pi = fronti + direci[i];
            int pj = frontj + direcj[i];
            int py = fronty + direcy[i];
            if (pi >= 0 && pi < H && pj >= 0 && pj < M && py >= 0 && py < N)
            {
                if (fruit[pi][pj][py] == 0)
                {
                    fruit[pi][pj][py] = fruit[fronti][frontj][fronty] + 1;
                    q.push({{pi, pj}, py});
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> H;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int y = 0; y < N; y++)
            {
                cin >> fruit[i][j][y];
            }
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int y = 0; y < N; y++)
            {
                if (fruit[i][j][y] == 1)
                {
                    q.push({{i, j}, y});
                }
            }
        }
    }
    int d = 0;
    bfs();
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int y = 0; y < N; y++)
            {
                if (fruit[i][j][y] == 0)
                {
                    cout << -1;
                    return 0;
                }
                else
                {
                    if (fruit[i][j][y] > d)
                    {
                        d = fruit[i][j][y];
                    }
                }
            }
        }
    }
    cout << d - 1;
}