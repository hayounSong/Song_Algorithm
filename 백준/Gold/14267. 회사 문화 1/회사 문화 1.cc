#include <iostream>
using namespace std;

int dp[100001] = {0};
int parent[100001] = {0};
int num[100001] = {0};
int N, M;
int main()
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        parent[i] = a;
    }
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        num[a] = num[a] + b;
    }
    for (int i = 1; i <= N; i++)
    {
        if (i == 1)
        {
            dp[i] = num[i];
            cout << num[i] << " ";
        }
        else
        {
            dp[i] = dp[parent[i]] + num[i];
            cout << dp[parent[i]] + num[i] << " ";
        }
    }
}