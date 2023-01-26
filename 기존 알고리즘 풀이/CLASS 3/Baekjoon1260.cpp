#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> list[1001];
int visited[1001];
void dfs(int x)
{
    cout << x << " ";
    visited[x] = 1;
    for (int i = 0; i < list[x].size(); i++)
    {
        if (visited[list[x][i]] != 1)
        {
            dfs(list[x][i]);
        }
    }
}
void bfs(int x)
{
    queue<int> q;
    q.push(x);
    visited[x] = true;

    while (!q.empty())
    {
        int back = q.front();
        q.pop();
        cout << back << " ";

        for (int i = 0; i < list[back].size(); i++)
        {
            if (visited[list[back][i]] == 0)
            {
                q.push(list[back][i]);
                visited[list[back][i]] = 1;
            }
        }
    }
}
int main()
{

    int node;
    int link;
    int start;
    cin >> node;
    cin >> link;
    cin >> start;
    for (int i = 0; i <= node; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < link; i++)
    {
        int s, e;
        cin >> s >> e;
        list[s].push_back(e);
        sort(list[s].begin(), list[s].end());
        list[e]
            .push_back(s);
        sort(list[e].begin(), list[e].end());
    }
    dfs(start);
    for (int i = 0; i <= node; i++)
    {
        visited[i] = 0;
    }
    cout << endl;
    bfs(start);
}