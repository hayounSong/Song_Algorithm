#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
pair<double, double> num[1001];
vector<pair<double, pair<double, double>>> v;
int parent[1001] = {0};

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

int main()
{

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        int a, b;
        cin >> a >> b;
        parent[i] = i;
        num[i] = {a, b};
    }
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        int fa = find(a);
        int fb = find(b);
        parent[fa] = fb;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            int fa = find(i);
            int fb = find(j);
            if (fa == fb)
            {
                continue;
            }
            double valu = sqrt((num[j].first - num[i].first) * (num[j].first - num[i].first) + (num[j].second - num[i].second) * (num[j].second - num[i].second));
            v.push_back({valu, {i, j}});
        }
    }

    sort(v.begin(), v.end());
    double ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        double valu = v[i].first;
        double a = v[i].second.first;
        double b = v[i].second.second;

        int fa = find(a);
        int fb = find(b);
        if (fa == fb)
        {
            continue;
        }
        else
        {
            if (fa > fb)
            {
                parent[fb] = fa;
                ans = ans + valu;
            }
            else
            {
                parent[fa] = fb;
                ans = ans + valu;
            }
        }
    }
    cout << fixed;
    cout.precision(2);
    ans = round(ans * 100) / 100;
    cout << ans;
}