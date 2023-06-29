#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    char a[1001];
    char b[1001];
    int dp[1001][1001];

    cin >> a;
    cin >> b;
    int max1 = 0;
    for (int i = 1; i <= strlen(b); i++)
    {
        for (int j = 1; j <= strlen(a); j++)
        {
            if (a[j - 1] == b[i - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > max1)
                {
                    max1 = dp[i][j];
                }
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << max1;
}