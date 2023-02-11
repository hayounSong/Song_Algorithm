#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int N, M;
vector<pair<int, int>> v[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
int dist[1001] = {
    99999999,
};
int visited[1001] = {0};
int start, endm;
void bfs(int start)
{
    q.push({0, start});
    dist[start] = 0;

    while (!q.empty())
    {

        int distance = q.top().first;
        int inde = q.top().second;

        q.pop();

        if (visited[inde] != 0)
        {
            continue;
        }
        visited[inde] = 1;
        for (int i = 0; i < v[inde].size(); i++)
        {
            int next = v[inde][i].first;
            int value = v[inde][i].second;

            if (dist[next] > distance + value)
            {

                dist[next] = distance + value;

                q.push({dist[next], next});
            }
        }
    }
}
int main()
{

    cin >> N;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }

    cin >> start >> endm;
    dist[start] = 0;
    fill(dist, dist + 1001, 99999999);
    bfs(start);

    cout << dist[endm];
}