#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int V, E;
vector<pair<int, int>> v[401];
int root[401][401] = {0};
#define INF 987654321
int maxi = INF;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> V >> E;
    for (int i = 0; i <= V; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            root[i][j] = INF;
        }
    }
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        root[a][b] = c;
    }
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            for (int z = 1; z <= V; z++)
            {
                if (root[j][z] > root[j][i] + root[i][z])
                {
                    root[j][z] = root[j][i] + root[i][z];
                }
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            if (i == j)
            {
                continue;
            }
            else
            {
                if (maxi > root[i][j] + root[j][i])
                {
                    maxi = root[i][j] + root[j][i];
                }
            }
        }
    }
    if (maxi >= INF)
    {
        cout << -1;
    }
    else
    {
        cout << maxi;
    }
}