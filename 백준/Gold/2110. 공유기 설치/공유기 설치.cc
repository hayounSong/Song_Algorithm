#include <iostream>
#include <vector>
#include <algorithm>
long long N, C;
using namespace std;
long long num[200001] = {0};

long long sumi(long long mid)
{

    long long last = num[0];
    long long ans = 1;
    for (long long i = 1; i < N; i++)
    {
        if (num[i] - last < mid)
        {
            continue;
        }
        else
        {
            ans++;
            last = num[i];
        }
    }
    return ans;
}

int main()
{
    cin >> N >> C;

    for (long long i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    sort(num, num + N);
    long long rm = num[N - 1] - num[0] + 1;

    long long low = 1;
    long long high = rm;
    long long ans = 0;
    while (low < high)
    {
        long long mid = (high + low) / 2;
        long long result = sumi(mid);
        // cout << mid << " " << result << "\n";
        if (result == C)
        {
            low = mid + 1;
            if (mid > ans)
            {
                ans = mid;
            }
            continue;
        }
        else if (result < C)
        {
            high = mid;
            continue;
        }
        else
        {
            if (mid > ans)
            {
                ans = mid;
            }
            low = mid + 1;
            continue;
        }
    }
    cout << ans;
}