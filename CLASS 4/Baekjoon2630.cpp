#include <iostream>
using namespace std;
#include <algorithm>

int Bcount = 0;
int Wcount = 0;

int count = 0;
int num[128][128];

void slice(int startx, int starty, int N)
{
    int first = num[startx][starty];

    if (first == 0)
    {
        for (int i = startx; i < startx + N; i++)
        {
            for (int j = starty; j < starty + N; j++)
            {
                if (num[i][j] == 1)
                {
                    slice(startx, starty, N / 2);
                    slice(startx + N / 2, starty, N / 2);
                    slice(startx, starty + N / 2, N / 2);
                    slice(startx + N / 2, starty + N / 2, N / 2);
                    return;
                }
            }
        }
        Wcount++;
    }
    else
    {
        for (int i = startx; i < startx + N; i++)
        {
            for (int j = starty; j < starty + N; j++)
            {
                if (num[i][j] == 0)
                {
                    slice(startx, starty, N / 2);
                    slice(startx + N / 2, starty, N / 2);
                    slice(startx, starty + N / 2, N / 2);
                    slice(startx + N / 2, starty + N / 2, N / 2);
                    return;
                }
            }
        }
        Bcount++;
    }
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> num[i][j];
        }
    }
    slice(0, 0, N);

    cout << Wcount << "\n";
    cout << Bcount;
}