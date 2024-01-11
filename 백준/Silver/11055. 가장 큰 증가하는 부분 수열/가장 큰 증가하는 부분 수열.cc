#include <iostream>
#include <cmath>
using namespace std;

int N;
int num[1001] = {0};
int dp[1001] = {0};
int main()
{
    cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    dp[N - 1] = num[N - 1];
    for (int i = N - 1; i >= 0; i--)
    {
        int maxi = 0;
        for (int j = i + 1; j < N; j++)
        {
            if (num[j] > num[i])
            {
                if (maxi < dp[j])
                {
                    maxi = dp[j];
                }
            }
        }
        dp[i] = maxi + num[i];
        if (dp[i] > ans)
        {
            ans = dp[i];
        }
    }
    cout << ans;
}