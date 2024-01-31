#include <iostream>
using namespace std;

int dpm[1001] = {0};
int num[1001] = {0};
int dpn[1001] = {0};
int N;
int ans = 0;
int main()
{
    cin >> N;
    dpm[0] = 1;
    dpn[N - 1] = 1;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    for (int i = 1; i < N; i++)
    {
        dpm[i] = 1;

        for (int j = i - 1; j >= 0; j--)
        {
            if (num[i] > num[j])
            {
                dpm[i] = max(dpm[i], dpm[j] + 1);
            }
        }
    }
    for (int i = N - 1; i >= 0; i--)
    {
        dpn[i] = 1;
        for (int j = i + 1; j < N; j++)
        {
            if (num[i] > num[j])
            {
                dpn[i] = max(dpn[i], dpn[j] + 1);
            }
        }
        ans = max(ans, dpm[i] + dpn[i] - 1);
    }
    cout << ans;
}