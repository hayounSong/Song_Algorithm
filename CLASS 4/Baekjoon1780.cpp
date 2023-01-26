#include <iostream>
#include <map>
using namespace std;

int num[2187][2187];
int three[8];
int mione = 0;
int zero = 0;
int plone = 0;

void paper(int startx, int starty, int N)
{
    if (N == 1)
    {
        if (num[startx][starty] == 0)
        {
            // cout << startx << " ";
            zero++;
        }
        else if (num[startx][starty] == 1)
        {
            plone++;
        }
        else
        {
            mione++;
        }
    }
    else
    {
        int start = num[startx][starty];
        for (int i = startx; i < startx + N; i++)
        {
            for (int j = starty; j < starty + N; j++)
            {
                if (num[i][j] != start)
                {

                    paper(startx, starty, N / 3);
                    paper(startx + N / 3, starty, N / 3);
                    paper(startx + 2 * N / 3, starty, N / 3);
                    paper(startx, starty + N / 3, N / 3);
                    paper(startx + N / 3, starty + N / 3, N / 3);
                    paper(startx + 2 * N / 3, starty + N / 3, N / 3);
                    paper(startx, starty + 2 * N / 3, N / 3);
                    paper(startx + N / 3, starty + 2 * N / 3, N / 3);
                    paper(startx + 2 * N / 3, starty + 2 * N / 3, N / 3);
                    return;
                }
            }
        }
        if (start == -1)
        {

            mione++;
        }
        else if (start == 0)
        {

            zero++;
        }
        else if (start == 1)
        {
            plone++;
        }
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
    paper(0, 0, N);
    cout << mione << "\n"
         << zero << "\n"
         << plone;
}