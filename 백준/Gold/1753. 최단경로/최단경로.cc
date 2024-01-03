#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> v[20001];
int V, E, K;
int visited[20001] = {0};

struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    };
};

void dick()
{
    int start = K;

    visited[K] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    pq.push({K, 0});

    while (!pq.empty())
    {
        int front = pq.top().first;
        int value = pq.top().second;
        pq.pop();

        for (int i = 0; i < v[front].size(); i++)
        {
            if (visited[v[front][i].first] > v[front][i].second + value)
            {
                visited[v[front][i].first] = v[front][i].second + value;
                pq.push({v[front][i].first, v[front][i].second + value});
            }
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> V >> E;
    cin >> K;

    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    for (int i = 0; i <= V; i++)
    {
        visited[i] = 987654321;
    }
    dick();

    for (int i = 1; i <= V; i++)
    {
        if (visited[i] == 987654321)
        {
            cout << "INF"
                 << "\n";
        }
        else
        {
            cout << visited[i] << "\n";
        }
    }
}