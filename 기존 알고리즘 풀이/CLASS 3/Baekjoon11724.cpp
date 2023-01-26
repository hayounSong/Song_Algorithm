#include <iostream>
#include <vector>
using namespace std;
vector<int> list[1009];
int visited[1009];
void dfs(int x)
{
    visited[x] = 1;

    for (int i = 0; i < list[x].size(); i++)
    {
        if (visited[list[x][i]] == 0)
        {
            dfs(list[x][i]);
        }
    }
}

int main()
{
    int node;
    int link;
    cin >> node >> link;
    int ans = 0;
    for (int i = 0; i < link; i++)
    {
        int a, b;
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }

    for (int i = 1; i <= node; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i);
            ans++;
        }
    }

    cout << ans;
}
ㅌ