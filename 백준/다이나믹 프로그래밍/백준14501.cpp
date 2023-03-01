#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair<int, int> work[16];
int ans[16];
int main()
{

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int a, b;
        cin >> a >> b;
        work[i] = {a, b};
    }

    if (work[N].first == 1)
    {
        ans[N] = work[N].second;
    }
    for (int i = N - 1; i >= 1; i--)
    {
        int count = 0;
        count = i + work[i].first;
        int money = 0;
        int countmax = 0;

        if (count <= N + 1)
        {
            money = money + work[i].second;

            for (int j = count; j <= N; j++)
            {
                if (ans[j] > countmax)
                {
                    countmax = ans[j];
                }
            }
        }
        ans[i] = money + countmax;
    }
    int maxans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (ans[i] > maxans)
        {
            maxans = ans[i];
        }
    }
    cout << maxans;
}