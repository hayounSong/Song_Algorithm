#include <iostream>
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{

    int n;

    cin >> n;

    int num[n];
    int dp[n];
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    int count = 0;
    int ans = 0;

    dp[0] = num[0];
    dp[1] = max(num[0], num[0] + num[1]);
    dp[2] = max(dp[0] + num[2], num[1] + num[2]);

    for (int i = 3; i < n; i++)
    {
        dp[i] = max(dp[i - 2] + num[i], dp[i - 3] + num[i - 1] + num[i]);
    }
    cout << dp[n - 1];
}