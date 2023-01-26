#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int mi = 0;
int visited[2000020] = {0};
void bfs(int a, int b)
{
    queue<int> q;
    q.push(a);
    while (true)
    {
        int a = q.front();
        q.pop();
        if (a == b)
        {
            cout << visited[a];
            break;
        }
        if (a + 1 <= 100000)
        {
            if (visited[a + 1] == 0 && a + 1 <= 100000)
            {
                q.push(a + 1);
                visited[a + 1] = visited[a] + 1;
            }
        }
        if (a - 1 >= 0)
        {
            if (visited[a - 1] == 0 && a - 1 >= 0)
            {
                q.push(a - 1);
                visited[a - 1] = visited[a] + 1;
            }
        }
        if (a + 1 <= 100000)
        {
            if (visited[a * 2] == 0 && a * 2 <= 100000)
            {
                q.push(a * 2);
                visited[a * 2] = visited[a] + 1;
            }
        }
    }
}

int main()
{

    int a, b;

    cin >> a >> b;

    bfs(a, b);
}