#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> v[100001];
int visited[100001] = {0};
int V;
int maxi = 0;
int maxiw = 0;
void dfs(int s, int val)
{
    visited[s] = 1;
    if (maxi < val)
    {
        maxi = val;
        maxiw = s;
    }
    for (int i = 0; i < v[s].size(); i++)
    {
        if (visited[v[s][i].first] == 0)
        {

            dfs(v[s][i].first, v[s][i].second + val);
        }
    }
    // return ans;
}

int main()
{
    cin >> V;

    for (int i = 1; i <= V; i++)
    {
        int a;
        cin >> a;
        while (true)
        {
            int b;
            cin >> b;
            if (b == -1)
            {
                break;
            }
            else
            {
                int c;
                cin >> c;
                v[a].push_back({b, c});
            }
        }
    }
    dfs(1, 0);
    for (int i = 0; i <= V; i++)
    {
        visited[i] = 0;
    }
    dfs(maxiw, 0);
    cout << maxi;
}