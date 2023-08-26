#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, K;
vector<int> v[50001];
int value[50001] = {0};
int visited[50001] = {0};
int bag[50001][5001] = {0};
vector<pair<int, int>> ans;

pair<int, int> bfs(int start)
{

    queue<int> q;
    q.push(start);
    visited[start] = 1;
    int avalue = 0;
    int kids = 1;
    avalue = avalue + value[start];
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (int i = 0; i < v[front].size(); i++)
        {
            int m = v[front][i];
            if (visited[m] == 0)
            {
                visited[m] = 1;
                q.push(m);
                avalue = avalue + value[m];
                kids++;
            }
        }
    }
    return {avalue, kids};
}
int main()
{
    ans.push_back({0, 0});
    cin >>
        N >> M >> K;

    for (int i = 1; i <= N; i++)
    {
        cin >> value[i];
    }
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == 0)
        {
            ans.push_back(bfs(i));
        }
    }
    // int max = 0;
    int cvalue = 0;

    for (int i = 1; i <= ans.size(); i++)
    {
        for (int j = 1; j <= K - 1; j++)
        {
            if (ans[i].second > j)
            {
                bag[i][j] = bag[i - 1][j];
            }
            else
            {
                bag[i][j] = max(bag[i - 1][j], bag[i - 1][j - ans[i].second] + ans[i].first);
            }
        }
    }
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i].first << " " << ans[i].second << "s ";
    // }
    cout << bag[ans.size() - 1][K - 1] << "\n";
    // for (int i = 0; i <= ans.size(); i++)
    // {
    //     for (int j = 0; j <= K; j++)
    //     {
    //         cout << bag[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}