#include <iostream>
using namespace std;
int dp[201] = {0};
int map[201] = {0};
int N;
int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> map[i];
    }
    int maxi = 0;
    for (int i = 0; i < N; i++)
    {
        dp[i] = 1;

        for (int j = 0; j < i; j++)
        {
            if (map[j] < map[i] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
        }
    }
    cout << N - maxi;
}