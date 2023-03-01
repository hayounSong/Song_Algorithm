#include <iostream>
using namespace std;

int N;
int M;
int num[1025][1025];
int dp[1025][1025];
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    cin >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> num[i][j];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        int count = 0;
        for (int j = 1; j <= N; j++)
        {
            count = count + num[i][j];
            dp[i][j] = count;
        }
    }

    for (int i = 0; i < M; i++)
    {
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        int ans = 0;

        for (int j = x1; j <= x2; j++)
        {
            ans = ans + dp[j][y2];

            ans = ans - dp[j][y1 - 1];
        }
        cout << ans << "\n";
    }
}