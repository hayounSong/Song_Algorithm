#include <iostream>
using namespace std;

int R, C;
int T;
int dusk[51][51];
int direcx[4] = {0, 1, 0, -1};
int direcy[4] = {1, 0, -1, 0};
int firs;
int seco;
void clean()
{
    int sero = dusk[firs][C - 1];
    for (int i = C - 1; i > 1; i--)
    {
        dusk[firs][i] = dusk[firs][i - 1];
    }
    dusk[firs][1] = 0;
    int garo = dusk[0][C - 1];

    for (int i = 0; i < firs - 1; i++)
    {

        dusk[i][C - 1] = dusk[i + 1][C - 1];
    }
    dusk[firs - 1][C - 1] = sero;

    sero = dusk[0][0];
    for (int i = 0; i < C - 2; i++)
    {
        dusk[0][i] = dusk[0][i + 1];
    }
    dusk[0][C - 2] = garo;

    for (int i = firs - 1; i >= 2; i--)
    {
        dusk[0][i] = dusk[0][i - 1];
    }
    dusk[0][1] = sero;
    // d
    sero = dusk[seco][C - 1];
    for (int i = C - 1; i > 1; i--)
    {
        dusk[seco][i] = dusk[seco][i - 1];
    }
    dusk[seco][1] = 0;
    garo = dusk[R - 1][C - 1];
    for (int i = R - 1; i >= seco + 2; i--)
    {
        dusk[i][C - 1] = dusk[i - 1][C - 1];
    }
    dusk[seco + 1][C - 1] = sero;
    sero = dusk[R - 1][0];
    for (int i = 0; i <= C - 2; i++)
    {
        dusk[R - 1][i] = dusk[R - 1][i + 1];
    }
    dusk[R - 1][C - 2] = garo;
    for (int i = seco + 2; i <= R - 1; i++)
    {
        dusk[i - 1][0] = dusk[i][0];
    }
    dusk[R - 2][0] = sero;
}
void hwak()
{
    int test[51][51] = {0};
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (dusk[i][j] > 0)
            {
                int count = 0;

                for (int q = 0; q < 4; q++)
                {
                    int px = i + direcx[q];
                    int py = j + direcy[q];

                    if (px >= 0 && py >= 0 && px < R && py < C)
                    {

                        if (dusk[px][py] != -1)
                        {
                            count++;
                        }
                    }
                }
                // if (i == 0 && j == 1)
                // {
                //     cout << count << "s";
                //     ;
                // }
                test[i][j] = test[i][j] + dusk[i][j] - (dusk[i][j] / 5) * count;
                for (int q = 0; q < 4; q++)
                {
                    int px = i + direcx[q];
                    int py = j + direcy[q];

                    if (px >= 0 && py >= 0 && px < R && py < C)
                    {
                        if (dusk[px][py] != -1)
                        {

                            test[px][py] = test[px][py] + dusk[i][j] / 5;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (dusk[i][j] != -1)
            {
                dusk[i][j] = test[i][j];
            }
        }
    }
}

int main()
{
    cin >> R >> C >> T;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> dusk[i][j];
            if (dusk[i][j] == -1)
            {
                if (firs == 0)
                {
                    firs = i;
                }
                else
                {
                    seco = i;
                }
            }
        }
    }

    for (int i = 0; i < T; i++)
    {
        hwak();
        clean();
    }
    cout << endl;
    int count = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (dusk[i][j] != -1)
            {
                count = count + dusk[i][j];
            }
        }
    }
    // cout << count;
}