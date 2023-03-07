#include <iostream>
using namespace std;
int H;
int W;
int block[501];
int main()
{
    cin >> H >> W;

    for (int i = 0; i < W; i++)
    {
        cin >> block[i];
    }
    int max = 0;
    int min = 9999;
    int mincount = 0;
    int ans = 0;

    for (int i = 0; i < W; i++)
    {
        int count = 0;
        int left = 0;
        int right = 0;

        for (int j = i; j >= 0; j--)
        {
            if (left < block[j])
            {
                left = block[j];
            }
        }
        for (int j = i; j < W; j++)
        {
            if (right < block[j])
            {
                right = block[j];
            }
        }
        int min;
        if (left > right)
        {
            min = right;
        }
        else
        {
            min = left;
        }

        count = min - block[i];
        if (count < 0)
        {
            continue;
        }
        else
        {
            ans = ans + count;
        }
    }
    cout << ans;
}