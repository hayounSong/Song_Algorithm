#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int num[41] = {0};
int snum[8000001] = {0};
int N, S;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> S;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    // sort(num, num + N);
    queue<pair<int, pair<int, int>>> q;
    int high = (N - 1) / 2;
    int low = 0;
    q.push({0, {0, 0}});
    long long ans = 0;
    while (!q.empty())
    {
        int qc = q.front().first;
        int qf = q.front().second.first;
        int qv = q.front().second.second;
        q.pop();
        if (qf == high)
        {
            if (qv == S && qc != 0)
            {
                ans = ans + 1;
            }

            if (qc != 0)
            {
                if (qv < 0)
                {
                    qv = -qv + 4000000;
                }
                snum[qv] = snum[qv] + 1;
            }

            continue;
        }
        q.push({qc, {qf + 1, qv}});
        q.push({qc + 1, {qf + 1, qv + num[qf]}});
    }

    q.push({0, {high, 0}});

    while (!q.empty())
    {
        int qc = q.front().first;
        int qf = q.front().second.first;
        int qv = q.front().second.second;
        q.pop();

        if (qf == N)
        {
            if (qc != 0 && qv == S)
            {
                ans = ans + 1;
            }
            if (qc != 0)
            {
                int q = S - qv;
                if (q < 0)
                {
                    q = -q + 4000000;
                }
                if (snum[q] > 0)
                {
                    ans = ans + snum[q];
                }
            }
            continue;
        }
        q.push({qc, {qf + 1, qv}});
        q.push({qc + 1, {qf + 1, qv + num[qf]}});
    }
    cout << ans;
}