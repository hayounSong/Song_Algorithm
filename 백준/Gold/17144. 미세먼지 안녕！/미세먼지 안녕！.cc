#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
int R, C, T;
int dust[51][51] = {0};
int secret[51][51] = {0};
int direcx[4] = {0, 0, 1, -1};
int direcy[4] = {1, -1, 0, 0};
pair<int, int> up;
pair<int, int> down;
void spread()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            secret[i][j] = dust[i][j];
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (dust[i][j] <= 0)
            {
                continue;
            }
            else
            {
                int coun = 0;
                for (int z = 0; z < 4; z++)
                {
                    int dx = i + direcx[z];
                    int dy = j + direcy[z];
                    if (dx < 0 || dy < 0 || dx >= R || dy >= C)
                    {
                        continue;
                    }
                    if (dust[dx][dy] == -1)
                    {
                        continue;
                    }
                    coun++;
                    secret[dx][dy] = (dust[i][j] / 5) + secret[dx][dy];
                }
                secret[i][j] = secret[i][j] - (dust[i][j] / 5) * coun;
            }
        }
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            dust[i][j] = secret[i][j];
        }
    }
}
void condi()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            secret[i][j] = dust[i][j];
        }
    }
    // up
    int sx = up.first;
    int sy = up.second;
    secret[sx][sy + 1] = 0;
    // 오른쪽
    for (int i = sy + 1; i < C - 1; i++)
    {
        secret[sx][i + 1] = dust[sx][i];
        sy = i;
    }
    sy = sy + 1;
    // 위
    for (int i = sx; i >= 1; i--)
    {
        secret[i - 1][sy] = dust[i][sy];
        sx = i;
    }
    // 왼쪽
    sx = sx - 1;
    for (int i = sy; i >= 1; i--)
    {
        secret[sx][i - 1] = dust[sx][i];
        sy = i;
    }
    sy = sy - 1;
    // 아래
    for (int i = sx; i <= up.first; i++)
    {
        secret[i + 1][sy] = dust[i][sy];
    }

    sx = down.first;
    sy = down.second;
    secret[sx][sy + 1] = 0;
    // 오른쪽
    for (int i = sy + 1; i < C - 1; i++)
    {
        secret[sx][i + 1] = dust[sx][i];
        sy = i;
    }
    sy = sy + 1;
    // 아래
    for (int i = sx; i < R - 1; i++)
    {
        secret[i + 1][sy] = dust[i][sy];
    }
    sx = R - 1;
    // 왼쪽
    for (int i = sy; i >= 1; i--)
    {
        secret[sx][i - 1] = dust[sx][i];
        sy = i;
    }
    sy = 0;

    for (int i = sx; i > down.first; i--)
    {
        secret[i - 1][sy] = dust[i][sy];
        sx = i;
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (dust[i][j] != -1)
            {
                dust[i][j] = secret[i][j];
            }
        }
    }
}

int main()
{
    cin >> R >> C >> T;
    int coun = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> dust[i][j];
            if (dust[i][j] == -1)
            {
                if (coun == 0)
                {
                    up = {i, j};
                    coun++;
                }
                else
                {
                    down = {i, j};
                }
            }
        }
    }
    for (int i = 0; i < T; i++)
    {
        spread();
        condi();
    }
    int ans = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            // cout << dust[i][j] << " ";
            if (dust[i][j] > 0)
            {
                ans = ans + dust[i][j];
            }
        }
        // cout << "\n";
    }
    cout << ans;
}
