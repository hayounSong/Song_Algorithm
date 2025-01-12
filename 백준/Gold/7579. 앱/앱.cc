#include <iostream>
using namespace std;
int N, M;
long dp[10001][101] = {0};
long memory[101] = {0};
long cost[101] = {0};
int check[10001][101] = {0};
int main()
{
    cin >> N >> M;
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> memory[i];
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> cost[i];
        sum = sum + cost[i];
    }

    for (int i = 0; i <= sum; i++)
    {
        dp[i][0] = 0;
        for (int j = 1; j <= N; j++)
        {
            if (i >= cost[j])
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - cost[j]][j - 1] + memory[j]);
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
            }
            if (dp[i][j] >= M)
            {
                cout << i;
                return 0;
            }
        }
    }
}