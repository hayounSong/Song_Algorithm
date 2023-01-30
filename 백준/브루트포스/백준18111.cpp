#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

int N, M, B;
int main()
{
    cin >> N >> M >> B;

    int mine[N + 1][M + 1];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> mine[i][j];
        }
    }

    int mininde = 0;
    int min = 99999999;
    for (int h = 0; h <= 256; h++)
    {
        int down = 0;
        int up = 0;
        int inven = B;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (mine[i][j] > h)
                {
                    down = down + mine[i][j] - h;
                    inven = inven + mine[i][j] - h;
                }
                else if (mine[i][j] < h)
                {
                    up = up + h - mine[i][j];
                    inven = inven - (h - mine[i][j]);
                }
            }
        }

        if (inven < 0)
        {
            continue;
        }
        else if (down * 2 + up <= min)
        {
            if (down * 2 + up == min)
            {
                if (h > mininde)
                {
                    mininde = h;
                }
            }
            min = down * 2 + up;
            mininde = h;
        }
    }

    cout << min << " " << mininde;
}