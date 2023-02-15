#include <iostream>
#include <algorithm>
using namespace std;
int INF = 9999999;

int dist[101][101] = {0};

int main()
{

    int N, M;

    cin >> N >> M;

    for (int i = 0; i <= N; i++)
    {
        fill(dist[i], dist[i] + 101, INF);
    }

    for (int i = 1; i <= N; i++)
    {
        dist[i][i] = 0;
    }

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (dist[a][b] > c)
        {
            dist[a][b] = c;
        }
    }

    for (int i = 1; i <= N; i++)
    {

        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                if (k == i)
                {
                    continue;
                }
                // if (j == 1 && k == 4)
                // {
                //     cout << dist[j][k] << 's';
                // }
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}