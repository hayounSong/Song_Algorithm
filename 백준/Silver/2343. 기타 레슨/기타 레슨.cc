#include <iostream>
#include <algorithm>
using namespace std;

long N, M;
long num[100001] = {0};

long how(long mid)
{
    long last = mid;
    long ans = 1;

    for (int i = 0; i < N; i++)
    {

        if (last - num[i] < 0)
        {
            ans++;
            last = mid;
        }
        last = last - num[i];
    }

    // cout << mid << " ";

    return ans;
}

int main()
{
    cin >> N >> M;
    long high = 0;
    long maxi = 0;
    for (long i = 0; i < N; i++)
    {
        cin >> num[i];
        high = high + num[i];
        if (num[i] > maxi)
        {
            maxi = num[i];
        }
    }
    long low = maxi;
    long ans = 987654321;
    if (M == 1)
    {
        ans = high;
        cout << ans;
        return 0;
    }
    while (low < high)
    {

        long mid = (low + high) / 2;

        long result = how(mid);

        if (result < M)
        {
            if (ans > mid)
            {
                ans = mid;
            }
            high = mid;
        }
        if (result > M)
        {
            low = mid + 1;
        }
        if (result == M)
        {
            if (ans > mid)
            {
                ans = mid;
            }
            high = mid;
        }
    }
    cout << ans;
}