#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> v[1001];
int N, M, X;
int back[1001][1001] = {0};

void dick(int s)
{
    priority_queue<pair<int, int>> pq;

    pq.push({0, s});

    while (!pq.empty())
    {
        int wh = pq.top().second;
        int wv = -pq.top().first;
        pq.pop();
        if (back[s][wh] < wv)
        {
            continue;
        }
        for (int i = 0; i < v[wh].size(); i++)
        {
            int dh = v[wh][i].first;
            int dv = v[wh][i].second;
            if (wv + dv < back[s][dh])
            {
                back[s][dh] = wv + dv;
                pq.push({-back[s][dh], dh});
            }
        }
    }
}

int main()
{
    cin >> N >> M >> X;

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            back[i][j] = 999999;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        dick(i);
    }
    int maxi = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i == X)
        {
            continue;
        }
        if (maxi < back[i][X] + back[X][i])
        {
            maxi = back[i][X] + back[X][i];
        }
    }
    cout << maxi;
}