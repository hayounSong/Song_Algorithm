#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, K;
vector<pair<int, int>> v;
int dy[101][100001] = {0};
int main()
{
    v.push_back({0, 0});
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {

            if (v[i].first > j)
            {
                dy[i][j] = dy[i - 1][j];
            }
            else
            {
                dy[i][j] = max(dy[i - 1][j - v[i].first] + v[i].second, dy[i - 1][j]);
            }
        }
    }
    cout << dy[N][K];
}