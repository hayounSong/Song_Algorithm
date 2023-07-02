#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int direc[1000001];
int parent[1000001];
pair<pair<int, int>, int> v[1000001];

int find(int x)
{
    if (x == parent[x])
        return x;

    else
        return parent[x] = find(parent[x]);
}

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return a.second < b.second;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i <= N; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[i] = {{a, b}, c};
    }

    sort(v, v + M, compare);

    int max = 0;
    int ans = 0;
    for (int i = 0; i < M; i++)
    {
        int f = v[i].first.first;
        int b = v[i].first.second;
        int l = v[i].second;
        int ff = find(f);
        int bf = find(b);

        if (ff == bf)
        {
            continue;
        }
        else
        {
            parent[bf] = ff;
            ans = ans + l;
            if (l > max)
            {
                max = l;
            }
        }
    }

    cout << ans - max;
}