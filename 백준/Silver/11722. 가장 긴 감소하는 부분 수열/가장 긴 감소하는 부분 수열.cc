#include <iostream>
using namespace std;

int num[1001] = {0};
int dp[1001] = {0};
int N;
int main()
{

    cin >> N;
    int mini = 1;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    dp[N - 1] = 1;
    for (int i = N - 2; i >= 0; i--)
    {
        int maxi = 0;
        for (int j = i + 1; j < N; j++)
        {
            if (num[i] > num[j])
            {
                if (dp[j] > maxi)
                {
                    maxi = dp[j];
                }
            }
        }
        dp[i] = maxi + 1;
        if (dp[i] > mini)
        {
            mini = dp[i];
        }
    }
    cout << mini;
}