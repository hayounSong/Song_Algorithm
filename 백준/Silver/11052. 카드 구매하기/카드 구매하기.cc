#include <iostream>
#include <cmath>
using namespace std;

int N;
long long dp[1001][1001] = {0};
long long coin[1001] = {0};
int main()
{

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> coin[i];
    }
    for (int i = 0; i < N; i++)
    {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (j < i)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                int maxi = 0;

                long long cost = j / i;
                long long rest = j % i;

                for (int z = 0; z <= cost; z++)
                {
                    dp[i][j] = max(dp[i - 1][j - (z * i)] + coin[i] * z, dp[i][j]);
                }
            }
        }
    }

    cout << dp[N][N];
}