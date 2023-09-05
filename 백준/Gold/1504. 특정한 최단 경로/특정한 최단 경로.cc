#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, E;
int a, b;

struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

int range[801] = {999999};
vector<pair<int, int>> v[801];
void didk(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push(make_pair(start, 0));

    while (!pq.empty())
    {
        pair<int, int> front = pq.top();
        pq.pop();

        // if (range[front.first] < front.second)
        // {
        //     continue;
        // }
        for (int i = 0; i < v[front.first].size(); i++)
        {
            int vv = v[front.first][i].first;
            int value = v[front.first][i].second;

            if (range[vv] >= value + range[front.first])
            {

                range[vv] = value + range[front.first];
                pq.push({vv, range[vv]});
            }
        }
    }
}

int main()
{
    cin >> N >> E;
    for (int i = 0; i < E; i++)
    {
        int c, d, e;
        cin >> c >> d >> e;
        v[c].push_back({d, e});
        v[d].push_back({c, e});
    }
    for (int i = 0; i <= N; i++)
    {
        range[i] = 999999999;
    }
    cin >> a >> b;
    for (int i = 0; i < v[1].size(); i++)
    {
        range[v[1][i].first] = v[1][i].second;
    }
    long ans = 0;
    range[1] = 0;
    didk(1);
    long route1 = 0;
    long route2 = 0;

    route1 = route1 + range[b];
    route2 = route2 + range[a];

    for (int i = 0; i <= N; i++)
    {
        range[i] = 999999999;
    }
    for (int i = 0; i < v[a].size(); i++)
    {
        range[v[a][i].first] = v[a][i].second;
    }
    range[a] = 0;
    didk(a);

    route1 = route1 + range[b];
    route2 = route2 + range[b];
    route1 = route1 + range[N];

    for (int i = 0; i <= N; i++)
    {
        range[i] = 999999999;
    }
    for (int i = 0; i < v[b].size(); i++)
    {
        range[v[b][i].first] = v[b][i].second;
    }
    range[b] = 0;
    didk(b);

    route2 = route2 + range[N];
    // cout << range[4] << " ";
    ans = min(route1, route2);
    if (ans >= 999999999)
    {
        cout << -1;
    }
    else
    {
        cout << min(route1, route2);
    }
}