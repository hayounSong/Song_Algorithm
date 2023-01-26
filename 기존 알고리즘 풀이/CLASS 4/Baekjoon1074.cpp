#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;

int ncount = 0;
int two[20];
int N, r, c;
void init()
{
    int num = 1;
    for (int i = 0; i < 16; i++)
    {
        two[i] = num;
        num = num * 2;
    }
}

void Zcount(int startx, int starty, int N)
{

    if (N == 0)
    {
        if (startx == c && starty == r)
        {
            cout << ncount;

            return;
        }
    }
    else
    {
        int a = two[N - 1];

        if (c < startx + a && r < starty + a)
        {
            Zcount(startx, starty, N - 1);
        }
        if (c >= startx + a && r < starty + a)
        {
            ncount = ncount + a * a;
            Zcount(startx + a, starty, N - 1);
        }
        if (c < startx + a && r >= starty + a)
        {

            ncount = ncount + 2 * a * a;
            Zcount(startx, starty + a, N - 1);
        }
        if (c >= startx + a && r >= starty + a)
        {
            ncount = ncount + 3 * a * a;
            Zcount(startx + a, starty + a, N - 1);
        }
    }
}
int main()
{
    init();

    cin >> N >> r >> c;

    Zcount(0, 0, N);
}