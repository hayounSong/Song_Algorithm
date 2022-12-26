#include <iostream>
using namespace std;
#include <vector>
int countl;
vector<int> list[101];
int visited[101];
int ans[101];
int go;
int dfs(int start, int end)
{
    for (int i = 0; i < list[start].size(); i++)
    {
        if (list[start][i] == end)
        {

            return 1;
        }
    }
    int min = 999999;
    for (int i = 0; i < list[start].size(); i++)
    {

        int a = dfs(list[start][i], end);
        if (a <= min)
        {
            min = a;
        }
    }
    return 1 + min;
}
int main()
{

    int node;
    int link;
    cin >> node >> link;

    for (int i = 0; i < link; i++)
    {
        int a, b;
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
        visited[i + 1] = 0;
    }
    go = 1;
    cout << dfs(1, 5);
}