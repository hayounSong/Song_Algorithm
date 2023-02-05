#include <iostream>
using namespace std;
#include <vector>
int N;

int ans[101][101];
int visited[101] = {0};
vector<int> num[101];

void dfs(int start)
{

    for (int i = 0; i < num[start].size(); i++)
    {
        int t = num[start][i];
        if (visited[t] == 0)
        {
            visited[t] = 1;
            dfs(t);
        }
    }
}
int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int a;
            cin >> a;
            if (a == 1)
            {
                num[i].push_back(j);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int a = 0; a <= N; a++)
        {
            visited[a] = 0;
        }
        dfs(i);
        for (int j = 1; j <= N; j++)
        {
            cout << visited[j] << " ";
        }
        cout << "\n";
    }
}