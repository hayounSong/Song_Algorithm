#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int V, E;

int parent[100001];
vector<pair<pair<int, int>, int>> v;
int visited[1000001] = {0};

int find(int a)
{
    while (a != parent[a])
    {
        a = parent[a];
    }
    return a;
}
bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return a.second < b.second;
}
int main()
{
    cin >> V >> E;

    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({{a, b}, c});
    }
    for (int i = 1; i <= V; i++)
    {
        parent[i] = i;
    }
    long long ans = 0;
    sort(v.begin(), v.end(), compare);
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i].second;
    // }
    for (int i = 0; i < v.size(); i++)
    {
        if (find(v[i].first.first) == find(v[i].first.second))
        {
            continue;
        }
        else
        {
            ans = ans + v[i].second;
            parent[find(v[i].first.second)] = find(v[i].first.first);
        }
    }
    cout << ans;
}