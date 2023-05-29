#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
vector<pair<int, int>> v[20012];
int checked[20012] = {0};
int tmax = 0;
void dfs(int start, int value)
{

    checked[start] = 1;
    if (value > tmax)
    {
        // if (value == 28)
        // {
        //     cout << start;
        // }
        tmax = value;
    }
    for (int i = 0; i < v[start].size(); i++)
    {

        int y = v[start][i].first;

        if (checked[y] == 0)
        {

            // if (start == 6)
            // {
            //     cout << value << " ";
            // }
            dfs(y, value + v[start][i].second);
        }
    }
}
int main()
{
    int vsize;

    cin >> vsize;

    for (int i = 0; i < vsize - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    for (int i = 1; i <= vsize; i++)
    {
        memset(checked, 0, sizeof(checked));
        dfs(i, 0);
    }
    cout << tmax;
}