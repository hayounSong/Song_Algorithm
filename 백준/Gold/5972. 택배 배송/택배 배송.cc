#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    };
};
int N, M;
long range[50001] = {0};
int visited[50001] = {0};
vector<pair<int, int>> v[50001];

void dikstra(int start)
{
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({start, 0});

    while (!pq.empty())
    {

        int front = pq.top().first;
        int value = pq.top().second;
        visited[front] = 1;
        // cout << front;
        pq.pop();
        for (int i = 0; i < v[front].size(); i++)
        {
            pair<int, int> df = v[front][i];
            // cout << front;
            if (range[df.first] > value + df.second)
            {

                range[df.first] = value + df.second;
                // if (visited[df.first] == 0)
                // {
                pq.push({df.first, value + df.second});
                // }
            }
        }
    }
}
int main()
{
    cin >> N >> M;

    for (int i = 0; i <= N; i++)
    {
        range[i] = 50000001;
    }

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    // for (int i = 0; i < v[1].size(); i++)
    // {
    //     // cout << v[1][i].first;
    //     range[v[1][i].first] = v[1][i].second;
    // }
    dikstra(1);
    cout << range[N];
}