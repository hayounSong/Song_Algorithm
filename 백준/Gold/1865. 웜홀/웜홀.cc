#include <iostream>
#include <vector>
using namespace std;
int N, M, W;
vector<pair<int, int>> r[501];
int dist[501] = {0};
int main()
{
    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++)
    {
        cin >> N >> M >> W;
        for (int i = 0; i <= N; i++)
        {
            r[i].clear();
            dist[i] = 10000 * 2500;
        }

        for (int i = 0; i < M; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;

            int ncou = 0;
            int nfin = 0;
            for (int j = 0; j < r[a].size(); j++)
            {
                if (r[a][j].first == b)
                {
                    nfin = 1;
                    if (r[a][j].second > c)
                    {
                        r[a][j].second = c;
                        ncou = 1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (nfin == 0)
            {
                r[a].push_back({b, c});
            }

            ncou = 0;
            nfin = 0;
            for (int j = 0; j < r[b].size(); j++)
            {
                if (r[b][j].first == a)
                {
                    nfin = 1;
                    if (r[b][j].second > c)
                    {
                        r[b][j].second = c;
                        ncou = 1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (nfin == 0)
            {
                r[b].push_back({a, c});
            }
        }
        for (int i = 0; i < W; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            c = -c;
            int ncou = 0;
            int nfin = 0;
            for (int j = 0; j < r[a].size(); j++)
            {
                if (r[a][j].first == b)
                {
                    nfin = 1;
                    if (r[a][j].second > c)
                    {
                        r[a][j].second = c;
                        ncou = 1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (nfin == 0)
            {
                r[a].push_back({b, c});
            }
        }
        int ans = 0;
        // dist[1] = 0;
        for (int ii = 0; ii < N; ii++)
        {
            for (int i = 1; i <= N; i++)
            {
                // if (dist[i] == 987654321)
                // {
                //     continue;
                // }
                for (int j = 0; j < r[i].size(); j++)
                {
                    int next = r[i][j].first;
                    int value = r[i][j].second;
                    if (dist[next] > dist[i] + value)
                    {
                        if (ii == N - 1)
                        {
                            ans = 1;
                        }
                        dist[next] = dist[i] + value;
                    }
                }
            }
        }
        if (ans == 1)
        {
            cout << "YES"
                 << "\n";
        }
        else
        {
            cout << "NO"
                 << "\n";
        }
    }
}
