#include <iostream>
#include <map>
#include <queue>
using namespace std;
long num[41] = {0};
long N, S;

int main()
{
    cin >> N >> S;
    for (long i = 0; i < N; i++)
    {
        cin >> num[i];
    }

    queue<pair<long, pair<long, long>>> q;

    q.push({0, {0, 0}});
    long ans = 0;
    while (!q.empty())
    {

        long qc = q.front().first;
        long qf = q.front().second.first;
        long qv = q.front().second.second;
        q.pop();

        if (qf == N)
        {
            if (qc != 0 && qv == S)
            {
                ans++;
            }
            continue;
        }
        q.push({qc, {qf + 1, qv}});
        q.push({qc + 1, {qf + 1, qv + num[qf]}});
    }
    cout << ans;
}