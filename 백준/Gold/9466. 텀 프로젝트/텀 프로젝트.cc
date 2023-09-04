#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

int N;
int v[100001] = {0};
int correct[100001] = {0};
int visited[100001] = {0};
int ans = 0;

void dfs(int start)
{
    visited[start] = 1;

    int c = v[start];

    if (visited[c] == 0)
    {
        dfs(c);
    }
    else if (correct[c] == 0)
    {
        for (int i = c; i != start; i = v[i])
        {

            ans++;
        }
        ans++;
    }
    correct[start] = 1;
}

int main()
{
    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++)
    {

        int N;
        cin >> N;
        for (int i = 1; i <= N; i++)
        {
            cin >> v[i];
            visited[i] = 0;
            correct[i] = 0;
        }
        ans = 0;
        for (int i = 1; i <= N; i++)
        {
            if (visited[i] == 0)
            {
                dfs(i);
            }
        }
        cout << N - ans << "\n";
    }
}