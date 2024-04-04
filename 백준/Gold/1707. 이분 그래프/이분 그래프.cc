#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int K;
int V, E;
int num[20001] = {0};
vector<int> v[20001];
int ans = 0;
void bfs(int start)
{
    queue<int> q;
    if (num[start] == 0)
    {
        num[start] = 1;
    }
    q.push(start);
    while (!q.empty())
    {
        int w = q.front();
        int color = num[w];
        q.pop();

        for (int i = 0; i < v[w].size(); i++)
        {
            int dw = v[w][i];
            if (num[dw] == 0)
            {
                q.push(dw);
                num[dw] = color * -1;
            }
            else
            {
                if (color == num[dw])
                {
                    ans = 1;
                    return;
                }
                else
                {
                    continue;
                }
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> K;

    for (int kk = 0; kk < K; kk++)
    {
        ans = 0;
        cin >> V >> E;
        for (int i = 0; i <= V; i++)
        {
            num[i] = 0;
            v[i].clear();
        }
        for (int i = 0; i < E; i++)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for (int i = 1; i <= V; i++)
        {

            {
                bfs(i);
                if (ans == 1)
                {
                    break;
                }
            }
        }

        if (ans == 1)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
}