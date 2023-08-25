#include <iostream>
#include <algorithm>
using namespace std;

int coin[101] = {0};
int value[100001] = {-1};

int main()
{
    int N, K;

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> coin[i];
        value[coin[i]] = 1;
    }
    sort(coin, coin + N);
    for (int i = 1; i <= K; i++)
    {
        if (value[i] != 0)
        {
            continue;
        }
        else
        {
            value[i] = -1;
        }
    }
    for (int i = 1; i <= K; i++)
    {
        int min = 999999;
        if (value[i] != -1)
        {
            continue;
        }
        for (int j = 0; j < N; j++)
        {
            if (i - coin[j] <= 0)
            {
                continue;
            }
            else if (value[i - coin[j]] == -1)
            {
                continue;
            }
            else
            {
                if (value[i - coin[j]] + 1 < min)
                {

                    min = value[i - coin[j]] + 1;
                }
            }
        }
        if (min == 999999)
        {
            value[i] = -1;
        }
        else
        {
            value[i] = min;
        }
    }
    cout << value[K];
}