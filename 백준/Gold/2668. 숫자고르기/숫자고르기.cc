#include <iostream>
#include <vector>
using namespace std;
int num[101] = {0};
int N;
int visited[101] = {0};

int dfs(int start)
{
    for (int i = 1; i <= N; i++)
    {
        visited[i] = 0;
    }
    int a = start;

    while (true)
    {
        if (num[a] == start)
        {
            return 1;
            break;
        }
        else if (visited[num[a]] > 0)
        {
            return 0;
            break;
        }
        else
        {
            a = num[a];
            visited[a]++;
        }
    }
    return 0;
}
int main()
{

    cin >> N;
    int ans = 0;
    vector<int> v;
    for (int i = 1; i <= N; i++)
    {
        cin >> num[i];
    }
    for (int i = 1; i <= N; i++)
    {
        int b = dfs(i);
        ans = ans + b;
        if (b == 1)
        {
            v.push_back(i);
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\n";
    }
}