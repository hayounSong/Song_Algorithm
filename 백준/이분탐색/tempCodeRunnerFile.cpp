#include <iostream>
#include <algorithm>
using namespace std;
unsigned long long N, M;
int main()
{

    cin >> N >> M;
    unsigned long long count = 0;
    long long tree[N + 1];
    unsigned long long min = 1000000000;
    unsigned long long max = 0;
    for (long long i = 0; i < N; i++)
    {
        cin >> tree[i];
        if (tree[i] < min)
        {
            min = tree[i];
        }
        if (tree[i] > max)
        {
            max = tree[i];
        }
    }
    long long low = 0;
    long long high = max;
    long long mid = (min + max) / 2;
    sort(tree, tree + N);
    mid = (low + high) / 2;
    long long ans = 0;
    while (low <= high)
    {

        count = 0;
        mid = (low + high) / 2;
        for (long long i = 0; i < N; i++)
        {
            if (tree[i] - mid <= 0)
            {
                continue;
            }
            count = count + tree[i] - mid;
        }

        if (count >= M)
        {

            if (mid > ans)
            {
                ans = mid;
            }
            low = mid + 1;
        }
        if (count < M)
        {

            high = mid - 1;
        }
    }
    cout << ans;
}