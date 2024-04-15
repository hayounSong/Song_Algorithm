#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M, K;
int num[10001][101] = {0};
vector<pair<int, pair<int, int>>> v[101];
int T;
int ans = 987654321;

void daick()
{
    // 비용, 위치
    num[0][1] = 0;
    // 시간, 위치,비용
    priority_queue<pair<int, pair<int, int>>> q;
    q.push({0, {1, 0}});
    while (!q.empty())
    {
        int ft = -q.top().first;
        int fw = q.top().second.first;
        int fv = q.top().second.second;
        q.pop();
        if (ft > num[fv][fw])
        {
            continue;
        }
        if (fv > M)
        {
            continue;
        }
        if (ft > ans)
        {
            continue;
        }
        for (int i = 0; i < v[fw].size(); i++)
        {
            int dt = v[fw][i].first;
            int dw = v[fw][i].second.first;
            int dv = v[fw][i].second.second;
            if (dv + fv > M)
            {
                continue;
            }
            if (ft + dt > ans)
            {
                continue;
            }
            if (dt + ft < num[dv + fv][dw])
            {
                num[dv + fv][dw] = dt + ft;
                if (dw == N)
                {
                    if (ans > dt + ft)
                    {
                        ans = dt + ft;
                    }
                }
                q.push({-(dt + ft), {dw, dv + fv}});
            }
        }
    }
}

int main()
{
    cin >> T;
    for (int tt = 0; tt < T; tt++)
    {
        cin >> N >> M >> K;
        ans = 987654321;
        for (int i = 0; i <= N; i++)
        {
            v[i].clear();
            for (int j = 0; j <= M; j++)
            {
                num[j][i] = 987654321;
            }
        }

        for (int i = 0; i < K; i++)
        {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            if (c > M)
            {
                continue;
            }
            // 시간, 위치,비용
            v[a].push_back({d, {b, c}});
        }

        for (int i = 1; i <= N; i++)
        {
            sort(v[i].begin(), v[i].end());
        }
        daick();

        if (ans == 987654321)
        {
            cout << "Poor KCM\n";
        }
        else
        {
            cout << ans << "\n";
        }
    }
}