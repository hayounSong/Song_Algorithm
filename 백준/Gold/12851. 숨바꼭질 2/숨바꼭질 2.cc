#include <iostream>
#include <queue>
using namespace std;

int N, K;
int dp[100001] = {0};
int how[100001] = {0};
int main()
{
    cin >> N >> K;

    queue<pair<int, int>> q;
    q.push({N, 0});
    int ans = 1;
    for (int i = 0; i < 100001; i++)
    {
        dp[i] = 999999;
    }
    dp[N] = 0;
    while (!q.empty())
    {

        int fw = q.front().first;
        int value = q.front().second;
        // cout << "fw: " << fw << " "
        //      << "value: " << value << "\n";

        q.pop();
        if (fw == K)
        {

            continue;
        }
        if (fw - 1 >= 0)
        {
            if (dp[fw - 1] >= value + 1)
            {
                if (fw - 1 == K)
                {
                    if (dp[fw - 1] > value + 1)
                    {
                        ans = 1;
                    }
                    else
                    {
                        // cout << fw << " ";
                        ans++;
                    }
                }
                dp[fw - 1] = value + 1;
                q.push({fw - 1, value + 1});
            }
        }
        if (fw + 1 <= 100000)
        {
            if (fw + 1 <= K)
            {
                if (dp[fw + 1] >= value + 1)
                {
                    if (fw + 1 == K)
                    {
                        if (dp[fw + 1] > value + 1)
                        {
                            ans = 1;
                        }
                        else
                        {
                            // cout << fw << " ";
                            ans++;
                        }
                    }
                    dp[fw + 1] = value + 1;
                    q.push({fw + 1, value + 1});
                }
            }
        }
        if (fw * 2 <= 100000 && fw != 0)
        {
            if (fw * 2 < 2 * K)
            {
                if (dp[fw * 2] >= value + 1)
                {
                    if (fw * 2 == K)
                    {
                        if (dp[fw * 2] > value + 1)
                        {
                            ans = 1;
                        }
                        else
                        {
                            // cout << fw << " ";
                            ans++;
                        }
                    }
                    dp[fw * 2] = value + 1;
                    q.push({fw * 2, value + 1});
                }
            }
        }
    }
    if (N == K)
    {
        cout << 0 << "\n"
             << 1;
    }
    else
    {
        cout << dp[K] << "\n";
        cout << ans;
    }
}