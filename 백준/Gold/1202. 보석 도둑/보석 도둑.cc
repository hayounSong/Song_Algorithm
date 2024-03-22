#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

long N, K;
pair<long, long> jul[300001];
long bac[300001];
long visited[300001] = {0};
priority_queue<long> pq;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;

    for (long i = 0; i < N; i++)
    {
        long a, b;
        cin >> a >> b;
        jul[i] = {a, b};
    }
    for (long i = 0; i < K; i++)
    {
        long c;
        cin >> c;
        bac[i] = c;
    }
    sort(jul, jul + N);
    sort(bac, bac + K);
    long ans = 0;
    long idx = 0;
    for (long i = 0; i < K; i++)
    {
        long cb = bac[i];

        while (idx < N && cb >= jul[idx].first)
        {
            pq.push(jul[idx].second);
            idx++;
        }
        if (!pq.empty())
        {
            ans = ans + pq.top();
            pq.pop();
        }
    }
    cout << ans;
}