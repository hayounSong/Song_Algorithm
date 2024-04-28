#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
long long N, M;
vector<pair<long long, long long>> v[10001];
long long value[10001] = {0};
int ans = 0;
void dick(long long a, long long b)
{
    priority_queue<pair<long long, long long>> q;
    q.push({1000000000, a});
    while (!q.empty())
    {

        long long fw = q.top().second;
        long long fv = q.top().first;
        q.pop();
        if (fw == b)
        {
            if (fv > ans)
            {
                ans = fv;
            }
            else
            {
                continue;
            }
        }
        if (fv < value[fw] || fv < ans)
        {
            continue;
        }
        for (long long i = 0; i < v[fw].size(); i++)
        {
            long long dw = v[fw][i].second;
            long long dv = v[fw][i].first;

            long long qv = min(fv, dv);
            if (qv > value[dw])
            {
                q.push({qv, dw});
                value[dw] = qv;
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (long long i = 0; i < M; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({c, b});
        v[b].push_back({c, a});
    }
    long long a, b;
    cin >> a >> b;

    dick(a, b);
    cout << value[b];
}