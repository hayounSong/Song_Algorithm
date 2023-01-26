#include <iostream>
#include <map>
#include <queue>
using namespace std;

int map1[101] = {0};
int visited[101] = {0};
int ans = 0;
void bfs(int start)
{
    visited[start] = 1;
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {

        int front = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++)
        {
            if (front + i == 100)
            {

                cout << visited[front];

                return;
            }
            if (front + i < 100)
            {
                if (visited[front + i] == 0)
                {
                    if (map1[front + i] != 0)
                    {
                        if (visited[map1[front + i]] == 0)
                        {

                            q.push(map1[front + i]);
                            visited[front + i] = visited[front] + 1;
                            visited[map1[front + i]] = visited[front] + 1;
                        }
                    }
                    else
                    {

                        q.push(front + i);
                        visited[front + i] = visited[front] + 1;
                    }
                }
            }
        }
    }
}

int main()
{
    int trail, snake;
    cin >> trail >> snake;

    for (int i = 0; i < trail; i++)
    {
        int a, b;
        cin >> a >> b;
        map1[a] = b;
    }
    for (int i = 0; i < snake; i++)
    {
        int a, b;
        cin >> a >> b;
        map1[a] = b;
    }
    bfs(1);
}