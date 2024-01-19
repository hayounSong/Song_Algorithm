#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, R;
int item[101] = {0};
int root[101] = {0};
int visited[101] = {0};
int maxi = 0;
vector<pair<int, int>> v[101];

void dick(int start)
{
    for (int i = 0; i <= N; i++)
    {
        root[i] = 999999;
    }
    root[start] = 0;
    priority_queue<pair<int, int>> q;
    q.push({0, start});
    // for (int i = 0; i < v[start].size(); i++)
    // {
    //     if (v[start][i].first > M)
    //     {
    //         continue;
    //     }
    //     else
    //     {
    //         q.push({-v[start][i].first, v[start][i].second});
    //     }
    // }
    while (!q.empty())
    {
        int value = -q.top().first;
        int where = q.top().second;
        q.pop();

        for (int i = 0; i < v[where].size(); i++)
        {
            int dw = v[where][i].second;
            int dv = v[where][i].first;

            if (dv + value > M)
            {
                continue;
            }
            else
            {
                if (root[dw] > value + dv)
                {
                    root[dw] = value + dv;
                    q.push({-root[dw], dw});
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (root[i] != 999999)
        {

            ans = ans + item[i];
        }
    }

    if (ans > maxi)
    {
        maxi = ans;
    }
}

int main()
{
    cin >> N >> M >> R;
    for (int i = 1; i <= N; i++)
    {
        cin >> item[i];
    }

    for (int i = 0; i < R; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        v[a].push_back({c, b});
        v[b].push_back({c, a});
    }

    for (int i = 1; i <= N; i++)
    {
        dick(i);
    }
    cout << maxi;
}