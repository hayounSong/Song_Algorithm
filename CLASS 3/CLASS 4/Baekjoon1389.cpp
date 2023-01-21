#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int P, relate;
int ans = 999999;
vector<int> num[101];
int visited[101] = {0};

int bfs(int N, int target)
{

    if (N == target)
    {
        return 0;
    }
    queue<int> q;

    q.push(N);
    int re = 0;
    visited[N] = 1;
    while (!q.empty())
    {
        int front = q.front();

        q.pop();
        re++;
        for (int i = 0; i < num[front].size(); i++)
        {

            if (visited[num[front][i]] == 0)
            {

                if (num[front][i] == target)
                {
                    return visited[front];
                }
                q.push(num[front][i]);
                visited[num[front][i]] = visited[front] + 1;
            }
        }
    }

    return re;
}

int main()
{
    int inde = 0;
    cin >> P >> relate;

    for (int i = 1; i <= relate; i++)
    {
        int a, b;
        cin >> a >> b;
        num[a].push_back(b);
        num[b].push_back(a);
        sort(num[a].begin(), num[a].end());
        sort(num[b].begin(), num[b].end());
    }
    for (int i = 1; i <= P; i++)
    {
        int count = 0;
        for (int j = 1; j <= P; j++)
        {
            for (int j = 1; j <= P; j++)
            {
                visited[j] = 0;
            }
            int a = bfs(i, j);
            count = count + a;
        }

        if (count < ans)
        {

            ans = count;
            inde = i;
        }
    }
    cout << inde;
}
