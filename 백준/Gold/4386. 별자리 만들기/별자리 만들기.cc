#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
int N;
pair<double, double> num[101];
double range[101][101] = {0};
int parent[101] = {0};
priority_queue<pair<double, pair<int, int>>> pq;

int find(int a)
{
    if (a == parent[a])
    {
        return a;
    }
    else
    {
        return find(parent[a]);
    }
}
int make_p(int a, int b)
{
    if (a == parent[a])
    {
        parent[a] = b;
        return a;
    }
    else
    {
        parent[a] = b;
        return find(parent[a]);
    }
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
        double a, b;
        cin >> a >> b;
        num[i] = {a, b};
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                continue;
            }
            range[i][j] = sqrt(pow(num[i].second - num[j].second, 2) + pow(num[i].first - num[j].first, 2));
            pq.push({-range[i][j], {i, j}});
        }
    }
    // cout << pq.top().first;
    double ans = 0;
    cout.precision(3);
    while (!pq.empty())
    {
        double fv = -pq.top().first;
        double fa = pq.top().second.first;
        double fb = pq.top().second.second;
        pq.pop();
        if (find(fa) == find(fb))
        {
            continue;
        }
        else
        {
            ans = ans + fv;
            parent[find(fa)] = find(fb);
        }
    }
    cout << ans;
}