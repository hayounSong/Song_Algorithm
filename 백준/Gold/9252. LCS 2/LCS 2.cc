#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    char a[1001];
    char b[1001];
    char ans[1001];
    int dp[1001][1001];
    int chec[1001][1001];
    cin >> a;
    cin >> b;
    int max1 = 0;
    int maxi = 0;
    int maxj = 0;
    for (int i = 1; i <= strlen(b); i++)
    {
        for (int j = 1; j <= strlen(a); j++)
        {
            if (a[j - 1] == b[i - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                chec[i][j] = chec[i][j] + 1;
                if (dp[i][j] > max1)
                {
                    maxi = i;
                    maxj = j;
                    max1 = dp[i][j];
                }
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int ac = max1;
    while (ac >= 1)
    {

        if (chec[maxi][maxj] > 0)
        {
            // cout << maxi << maxj << " ";
            ac--;
            maxi--;
            maxj--;
            ans[ac] = b[maxi];
        }
        else
        {
            int movi;
            int movj;
            if (dp[maxi - 1][maxj] > dp[maxi][maxj - 1])
            {
                movi = maxi - 1;
                movj = maxj;
            }
            else
            {
                movi = maxi;
                movj = maxj - 1;
            }

            maxi = movi;
            maxj = movj;
        }
    }
    cout << max1 << "\n";
    if (max1 > 0)
    {
        for (int i = 0; i < max1; i++)
        {
            cout << ans[i];
        }
    }
}