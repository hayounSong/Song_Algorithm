#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>
#include <map>
vector<int> p[100001];
int ans[100001];
int N;
void dfs(int start)
{
    for (int i = 0; i < p[start].size(); i++)
    {
        int node = p[start][i];
        if (ans[node] == 0)
        {
            ans[node] = start;
            dfs(node);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        p[a].push_back(b);
        p[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(p[i].begin(), p[i].end());
    }

    dfs(1);
    for (int i = 2; i <= N; i++)
    {

        cout << ans[i] << "\n";
    }
}