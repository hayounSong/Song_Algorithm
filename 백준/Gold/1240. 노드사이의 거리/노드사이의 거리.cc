#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> v[1001];
int visited[1001] = {0};
int range[1001][1001] = {0};
int N, M;

void ran(int a)
{
    queue<pair<int, int>> q;
    q.push({a, 0});
    for (int i = 1; i <= N; i++)
    {
        visited[i] = -1;
        range[a][i] = 999999;
    }
    range[a][a] = 0;
    while (!q.empty())
    {
        int fw = q.front().first;
        int fv = q.front().second;

        q.pop();
        if (fv > range[a][fw])
        {
            continue;
        }
        else
        {
            for (int i = 0; i < v[fw].size(); i++)
            {
                int dw = v[fw][i].first;
                int dv = v[fw][i].second;

                if (dv + fv < range[a][dw])
                {
                    range[a][dw] = dv + fv;
                    q.push({dw, dv + fv});
                }
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for (int i = 1; i <= N; i++)
    {
        ran(i);
    }
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << range[a][b] << "\n";
    }
}