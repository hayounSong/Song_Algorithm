#include <iostream>
using namespace std;

int num[100001];
int ans[100001];
int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }

    ans[N - 1] = num[N - 1];

    for (int i = N - 2; i >= 0; i--)
    {
        if (ans[i + 1] > 0)
        {
            ans[i] = num[i] + ans[i + 1];
        }
        else
        {
            ans[i] = num[i];
        }
    }
    int max = -1000;
    for (int i = 0; i < N; i++)
    {
        if (ans[i] > max)
        {
            max = ans[i];
        }
    }
    cout << max;
}