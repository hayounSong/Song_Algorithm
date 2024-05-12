#include <iostream>
#include <queue>
#include <vector>
using namespace std;
long visited[10001] = {0};
vector<pair<int, int>> v[10001];
int N, D, C;
long ans = 0;
long coun = 1;
void daick(int start)
{
    visited[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, C});

    while (!pq.empty())
    {
        int fv = -pq.top().first;
        int fw = pq.top().second;
        pq.pop();
        if (visited[fw] < fv)
        {
            continue;
        }

        for (int i = 0; i < v[fw].size(); i++)
        {
            int dv = v[fw][i].first;
            int dw = v[fw][i].second;

            if (dv + fv < visited[dw])
            {
                if (visited[dw] == 9876543210)
                {
                    coun += 1;
                }
                visited[dw] = dv + fv;
                pq.push({-visited[dw], dw});
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++)
    {
        ans = 0;
        coun = 1;
        cin >> N >> D >> C;
        for (int i = 0; i <= N; i++)
        {
            v[i].clear();
            visited[i] = 9876543210;
        }
        for (int i = 0; i < D; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;

            v[b].push_back({c, a});
        }
        daick(C);
        for (int i = 1; i <= N; i++)
        {
            if (visited[i] != 9876543210)
            {
                ans = max(ans, visited[i]);
            }
        }
        cout << coun << " " << ans << "\n";
    }
}