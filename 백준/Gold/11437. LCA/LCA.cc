#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, M;
vector<int> node[50001];
int visited[50001] = {0};
int parent[50001] = {0};
int depth[50001] = {0};
queue<int> pq;
int bfs(int a, int b)
{
    if (a == b)
    {
        return a;
    }
    if (depth[a] > depth[b])
    {
        swap(a, b);
    }

    while (depth[a] != depth[b])
    {
        b = parent[b];
    }

    while (a != b)
    {
        a = parent[a];
        b = parent[b];
    }

    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    pq.push(1);

    visited[1] = 1;
    depth[1] = 1;
    while (!pq.empty())
    {
        int f = pq.front();
        int fd = depth[f];
        pq.pop();

        for (int i = 0; i < node[f].size(); i++)
        {
            if (visited[node[f][i]] == 0)
            {
                visited[node[f][i]] = 1;
                parent[node[f][i]] = f;
                depth[node[f][i]] = fd + 1;
                pq.push(node[f][i]);
            }
        }
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << bfs(a, b) << "\n";
    }
}
