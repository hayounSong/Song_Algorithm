#include <iostream>
#include <queue>
using namespace std;

int N, K;
int visited[100001] = {0};
void bfs(int first, int end)
{
    queue<int> q;

    q.push(first);
    visited[first] = 1;

    while (!q.empty())
    {

        int start = q.front();
        q.pop();

        if (start == end)
        {
            cout << visited[start] - 1 << endl;
            return;
        }
        if (start * 2 <= 100000)
        {
            if (visited[start * 2] == 0 || visited[start] + 1 < visited[start * 2])
            {

                visited[start * 2] = visited[start] + 1;
                q.push(start * 2);
            }
        }
        if (start + 1 <= 100000)
        {
            if (visited[start + 1] == 0 || visited[start] + 1 < visited[start + 1])
            {
                visited[start + 1] = visited[start] + 1;
                q.push(start + 1);
            }
        }
        if (start - 1 >= 0)
        {
            if (visited[start - 1] == 0 || visited[start] + 1 < visited[start - 1])
            {
                visited[start - 1] = visited[start] + 1;
                q.push(start - 1);
            }
        }
    }
}

int main()
{
    cin >> N >> K;

    bfs(N, K);
    fill(visited, visited + 100001, 0);
    bfs(K, N);
}