#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int INF = 999999;
int start, endm;
vector<pair<int, int>> node[5001];
int dist[5001];
int visited[5001] = {0};
void djak(int start)
{
    dist[start] = 0;

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
        for (int i = 0; i < node[current].size(); i++)
        {
            int next = node[current][i].first;
            int nextvalue = node[current][i].second;

            if (dist[next] > distance + nextvalue)
            {
                dist[next] = distance + nextvalue;
                pq.push({distance + nextvalue, next});
            }
        }
    }
}

int main()
{
    int M;
    int N;

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        node[a].push_back({b, c});
        node[b].push_back({a, c});
    }

    fill(dist, dist + 5001, INF);

    cin >> start >> endm;
    djak(start);
    cout << dist[endm];
}
