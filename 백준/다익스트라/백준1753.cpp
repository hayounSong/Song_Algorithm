#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

long V, E;
vector<pair<int, int>> v[20001];
int visited[20001] = {0};
int dist[20001];
int INF = 9999999;

void djak(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});

    while (!pq.empty())
    {
        int current = pq.top().second;
        int distance = pq.top().first;
        pq.pop();
        if (visited[current] != 0)
        {
            continue;
        }
        visited[current] = 1;
        for (int i = 0; i < v[current].size(); i++)
        {
            int next = v[current][i].first;
            int nextdist = v[current][i].second;

            if (dist[next] > distance + nextdist)
            {
                dist[next] = distance + nextdist;
                pq.push({dist[next], next});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> V >> E;

    int start;

    cin >> start;

    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        v[a].push_back({b, c});
    }

    dist[start] = 0;
    fill(dist, dist + 20001, INF);

    djak(start);

    for (int i = 1; i <= V; i++)
    {
        int a = dist[i];
        if (i == start)
        {
            cout << 0 << endl;
        }
        else if (a == INF)
        {
            cout << "INF" << endl;
        }
        else
        {
            cout << a << endl;
        }
    }
}