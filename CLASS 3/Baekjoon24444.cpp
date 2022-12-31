#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> list[100001];
int visited[100001] = {
    0,
};
int ans[100001] = {
    0,
};
int inde = 1;
void bfs(int start)
{
    queue<int> que;

    que.push(start);
    visited[start] = 1;

    while (!que.empty())
    {
        int back = que.front();
        que.pop();
        ans[back] = inde;
        inde++;

        for (int i = 0; i < list[back].size(); i++)
        {
            int temp = list[back][i];
            if (visited[temp] == 0)
            {
                visited[temp] = 1;
                que.push(temp);
            }
        }
    }
}

int main()
{

    int node, link, start;
    cin >> node >> link >> start;

    for (int i = 0; i < link; i++)
    {
        int a, b;
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }
    for (int i = 1; i <= node; i++)
    {
        sort(list[i].begin(), list[i].end());
    }
    bfs(start);
    for (int i = 1; i <= node; i++)
    {

        cout << ans[i] << "\n";
    }
}