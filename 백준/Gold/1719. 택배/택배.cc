#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> v[201];
int root[201][201] = {0};
int ans[201][201] = {0};
int N, M;

void dick(int start)
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {

        int fv = -pq.top().first;
        int fw = pq.top().second;
        pq.pop();

        if (root[start][fw] < fv)
        {
            continue;
        }

        for (int i = 0; i < v[fw].size(); i++)
        {
            int dw = v[fw][i].first;
            int dv = v[fw][i].second;
            if (fv + dv < root[start][dw])
            {
                ans[start][dw] = fw;
                root[start][dw] = fv + dv;
                pq.push({-(fv + dv), dw});
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if (i == j)
            {
                root[i][j] = 0;
            }
            else
            {
                root[i][j] = 987654321;
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        dick(i);
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
            {
                cout << "- ";
            }
            else
            {
                cout << ans[j][i] << " ";
            }
        }
        cout << "\n";
    }
}