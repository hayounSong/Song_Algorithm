#include <iostream>
#include <vector>
#include <map>
using namespace std;
long long num[10001];
long long mid;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long K;
    long long N;

    cin >> K >> N;

    long long max = 0;
    for (int i = 0; i < K; i++)
    {

        cin >> num[i];

        if (num[i] > max)
        {
            max = num[i];
        }
    }
    long long low = 1;
    long long high = max;
    long long ans = 0;
    while (low <= high)
    {

        long long count = 0;
        mid = (low + high) / 2;

        for (int i = 0; i < K; i++)
        {
            count = count + num[i] / mid;
        }

        if (count >= N)
        {

            low = mid + 1;
            if (ans < mid)
            {
                ans = mid;
            }
        }
        if (count < N)
        {
            high = mid - 1;
        }
    }
    cout << ans;
}