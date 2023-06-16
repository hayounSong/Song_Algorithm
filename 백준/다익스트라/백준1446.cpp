#include <iostream>
#include <vector>
using namespace std;

int N, D;
int way[10001] = {0};
int root[10001];
vector<pair<int, int>> fast[10001];
int main()
{
    cin >> N >> D;

    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (b - a > c)
        {
            fast[b].push_back({a, c});
            root[b] = 1;
        }
    }

    for (int i = 1; i <= D; i++)
    {
        if (root[i] == 0)
        {
            way[i] = way[i - 1] + 1;
        }
        else
        {
            int small = way[i - 1] + 1;
            for (int j = 0; j < fast[i].size(); j++)
            {
                if (fast[i][j].second + way[fast[i][j].first] < small)
                {
                    small = fast[i][j].second + way[fast[i][j].first];
                }
            }
            way[i] = small;
        }
    }
    cout << way[D];
}