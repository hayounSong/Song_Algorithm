#include <iostream>
using namespace std;

int num[2002];
int N;
int M;
int dp[2002][2002];
int check(int a, int b)
{
    return 1;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> num[i];
    }

    cin >> M;
    for (int i = 1; i <= N; i++)
    {
        dp[i][i] = 1;
    }

    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j <= N; j++)
        {
            if (j - i == 1)
            {
                if (num[i] == num[j])
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
            else
            {
                if (num[i] != num[j])
                {
                    dp[i][j] = 0;
                    continue;
                }
                else
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << dp[a][b] << "\n";
    }
}
