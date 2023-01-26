#include <iostream>
#include <vector>
using namespace std;

int visited[101] = {0};
vector<int> list[101];
int ans = 0;
void dfs(int x)
{
    visited[x] = 1;

    if (x != 1)
    {
        ans++;
    }

    for (int i = 0; i < list[x].size(); i++)
    {
        if (visited[list[x][i]] != 1)
        {

            dfs(list[x][i]);
        }
    }
};

int main()
{
    int computer;
    int n;

    cin >> computer;
    cin >> n;
    ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;

        cin >> a >> b;

        list[b].push_back(a);

        list[a].push_back(b);
    }
    dfs(1);
    cout << ans;
}