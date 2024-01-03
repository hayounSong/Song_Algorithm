#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<pair<pair<long long, long long>, long long>> v;
long long visited[501] = {0};
int ttime = 0;
#define MAX 9876543210

// long long MAX = 500 * 6000 * 10000 + 1;
void bfs()
{
    visited[1] = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            long long first = v[j].first.first;
            long long second = v[j].first.second;
            long long value = v[j].second;

            if (visited[first] != MAX && visited[second] > visited[first] + value)
            {
                if (i == N - 1 && N > 2)
                {
                    ttime = 1;
                    return;
                }
                visited[second] = visited[first] + value;
            }
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({{a, b}, c});
    }
    for (int i = 0; i <= N; i++)
    {
        visited[i] = MAX;
    }
    bfs();
    if (ttime == 1)
    {
        cout << -1 << "\n";
    }
    else
    {
        for (int i = 2; i <= N; i++)
        {
            if (visited[i] == MAX)
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << visited[i] << "\n";
            }
        }
    }
}