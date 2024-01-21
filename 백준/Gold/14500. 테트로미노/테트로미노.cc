#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int direcx[4] = {0, 0, 1, -1};
int direcy[4] = {1, -1, 0, 0};
int N, M;
int num[501][501] = {0};
int maxi = 0;

void back(int sx, int sy, int cur, int value, int lx, int ly)
{
    if (cur >= 3)
    {
        if (maxi < value)
        {

            maxi = value;
        }
        return;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {

            int dx = sx + direcx[i];
            int dy = sy + direcy[i];

            if (dx < 0 || dy < 0 || dx >= N || dy >= M)
            {
                continue;
            }
            else if (dx == lx && dy == ly)
            {

                continue;
            }
            else
            {

                back(dx, dy, cur + 1, value + num[dx][dy], sx, sy);
            }
        }
    }
}

void check4(int sx, int sy)
{
    if (sy >= 1 && sx >= 1 && sx + 1 < N)
    {
        int cvalue = num[sx][sy] + num[sx - 1][sy] + num[sx][sy - 1] + num[sx + 1][sy];
        maxi = max(maxi, cvalue);
    }
    if (sy >= 1 && sx >= 1 && sy + 1 < M)
    {
        int cvalue = num[sx][sy] + num[sx][sy - 1] + num[sx - 1][sy] + num[sx][sy + 1];
        maxi = max(maxi, cvalue);
    }
    if (sx >= 1 && sx + 1 < N && sy + 1 < M)
    {
        int cvalue = num[sx][sy] + num[sx][sy + 1] + num[sx - 1][sy] + num[sx + 1][sy];
        maxi = max(maxi, cvalue);
    }
    if (sy >= 1 && sx + 1 < N && sy + 1 < M)
    {
        int cvalue = num[sx][sy] + num[sx][sy - 1] + num[sx + 1][sy] + num[sx][sy + 1];
        maxi = max(maxi, cvalue);
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
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            back(i, j, 0, num[i][j], 0, 0);
            check4(i, j);
        }
    }
    cout << maxi;
}