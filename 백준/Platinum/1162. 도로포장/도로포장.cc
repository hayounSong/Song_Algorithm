#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
const long long MAXTIME = LONG_MAX;
using namespace std;
long long root[25][10001] = {0};
long long N, M, K;
vector<pair<long long, long long>> v[10001];
#include <climits>
#define TIME_LIMIT LLONG_MAX
long long ans = TIME_LIMIT;
void daick()
{
    priority_queue<pair<long long, pair<long long, long long>>> q;
    root[0][1] = 0;
    q.push({0, {0, 1}});
    while (!q.empty())
    {
        long long qv = -q.top().first;
        long long qw = q.top().second.second;
        long long qc = q.top().second.first;
        q.pop();

        if (root[qc][qw] < qv)
        {
            continue;
        }

        for (long long i = 0; i < v[qw].size(); i++)
        {
            long long dw = v[qw][i].first;
            long long dv = v[qw][i].second;

            if (qv + dv < root[qc][dw])
            {
                root[qc][dw] = qv + dv;
                if (dw == N)
                {
                    if (qv + dv < ans)
                    {
                        ans = qv + dv;
                    }
                }
                q.push({-(qv + dv), {qc, dw}});
            }
            if (qv < root[qc + 1][dw] && qc < K)
            {
                if (dw == N)
                {
                    if (qv < ans)
                    {
                        ans = qv;
                    }
                }
                root[qc + 1][dw] = qv;
                q.push({-(qv), {qc + 1, dw}});
            }
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;

    for (long long i = 0; i < M; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for (long long i = 0; i <= K; i++)
    {
        for (long long j = 0; j <= N; j++)
        {
            root[i][j] = TIME_LIMIT;
        }
    }
    daick();
    if (ans == TIME_LIMIT)
    {
        ans = 0;
    }
    cout << ans;
}