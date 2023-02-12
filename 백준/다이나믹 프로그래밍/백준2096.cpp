#include <iostream>
#include <algorithm>
using namespace std;

int N;
int num[100001][3];
int ans[2][3] = {0};
int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> num[i][j];
        }
    }
    ans[1][0] = num[N - 1][0];
    ans[1][1] = num[N - 1][1];
    ans[1][2] = num[N - 1][2];
    // 최댓값

    for (int i = N - 2; i >= 0; i--)
    {

        for (int j = 0; j < 3; j++)
        {

            if (j == 0)
            {
                ans[0][j] = num[i][0] + max(ans[1][0], ans[1][1]);
            }
            else if (j == 1)
            {
                ans[0][j] = num[i][1] + max({ans[1][0], ans[1][1], ans[1][2]});
            }
            else if (j == 2)
            {
                ans[0][j] = num[i][2] + max(ans[1][1], ans[1][2]);
            }
        }
        ans[1][0] = ans[0][0];
        ans[1][1] = ans[0][1];
        ans[1][2] = ans[0][2];
    }
    ans[0][0] = ans[1][0];
    ans[0][1] = ans[1][1];
    ans[0][2] = ans[1][2];
    int max = 0;
    for (int i = 0; i < 3; i++)
    {
        if (ans[0][i] > max)
        {
            max = ans[0][i];
        }
    }

    ans[1][0] = num[N - 1][0];
    ans[1][1] = num[N - 1][1];
    ans[1][2] = num[N - 1][2];
    // 최댓값

    for (int i = N - 2; i >= 0; i--)
    {

        for (int j = 0; j < 3; j++)
        {

            if (j == 0)
            {
                ans[0][j] = num[i][0] + min(ans[1][0], ans[1][1]);
            }
            else if (j == 1)
            {
                ans[0][j] = num[i][1] + min({ans[1][0], ans[1][1], ans[1][2]});
            }
            else if (j == 2)
            {
                ans[0][j] = num[i][2] + min(ans[1][1], ans[1][2]);
            }
        }
        ans[1][0] = ans[0][0];
        ans[1][1] = ans[0][1];
        ans[1][2] = ans[0][2];
    }
    ans[0][0] = ans[1][0];
    ans[0][1] = ans[1][1];
    ans[0][2] = ans[1][2];
    int min = 999999;
    for (int i = 0; i < 3; i++)
    {
        if (ans[0][i] < min)
        {
            min = ans[0][i];
        }
    }
    cout << max << " " << min;
}