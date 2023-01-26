#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int N, M;
int num[500][500];
int visited[500][500];
int direcx[4] = {1, 0, -1, 0};
int direcy[4] = {0, -1, 0, 1};

int sum(int startx, int starty, int counter)
{
    if (counter == 1)
    {
        return num[startx][starty];
    }
    else
    {
        int max = 0;
        for (int i = 0; i < 4; i++)
        {
            if (startx + direcx[i] >= 0 && startx + direcx[i] < N && starty + direcy[i] >= 0 && starty + direcy[i] < M)
            {
                int a = sum(startx + direcx[i], starty + direcy[i], counter - 1);
                if (max < a)
                {
                    max = a;
                }
            }
        }

        return max + num[startx][starty];
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
    int max = 0;
    int indx = 0;
    int indy = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int a = sum(i, j, 4);
            if (max < a)
            {
                indx = i;
                indy = j;
                max = a;
            }
        }
    }
    cout << indx << indy;
    cout << max;
}