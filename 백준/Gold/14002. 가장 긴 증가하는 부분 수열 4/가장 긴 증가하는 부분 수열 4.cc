#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N;
int num[1001] = {0};
int dp[1001] = {0};
vector<int> v[1001];
int main()
{
    cin >> N;
    int ans = 0;
    int answhere = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    dp[N - 1] = 1;
    for (int i = N - 1; i >= 0; i--)
    {
        int maxi = 0;
        int where = -1;

        for (int j = i + 1; j < N; j++)
        {
            if (num[j] > num[i])
            {
                if (maxi < dp[j])
                {
                    maxi = dp[j];
                    where = j;
                }
            }
        }
        v[i].push_back(i);
        if (where != -1)
        {
            for (int j = 0; j < v[where].size(); j++)
            {
                v[i].push_back(v[where][j]);
            }
        }
        dp[i] = 1 + maxi;
        if (ans < dp[i])
        {
            answhere = i;
            ans = dp[i];
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < v[answhere].size(); i++)
    {
        cout << num[v[answhere][i]] << " ";
    }
}