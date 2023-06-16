#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, K, X;
vector<int> v[300001];

int visited[3000001];
int way[3000001];

void daik()
{
    queue<int> q;

    q.push(X);

    while (!q.empty())
    {

        int front = q.front();
        q.pop();

        for (int i = 0; i < v[front].size(); i++)
        {
            if (visited[v[front][i]] == 0)
            {

                if (way[v[front][i]] > way[front] + 1)
                {
                    way[v[front][i]] = way[front] + 1;
                }
                visited[v[front][i]] = 1;
                q.push(v[front][i]);
            }
        }
    }
}

int main()
{
    cin >> N >> M >> K >> X;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    for (int i = 0; i <= N; i++)
    {
        way[i] = 999999;
    }
    way[X] = 0;
    visited[X] = 1;
    for (int i = 0; i < v[X].size(); i++)
    {
        way[v[X][i]] = 1;
    }

    daik();
    int count = 0;
    for (int i = 1; i <= N; i++)
    {

        if (way[i] == K)
        {
            cout << i << "\n";
            count = 1;
        }
    }
    if (count == 0)
    {
        cout << -1;
    }
}