#include <iostream>
using namespace std;
#include <queue>
#include <algorithm>
int tomato[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int tcount = 0;
int G;
int S;
queue<pair<int, int>> q;
bool IsInside(int ny, int nx)
{
    return (0 <= nx && 0 <= ny && nx < S && ny < G);
}
void bfs()
{

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {

            int nx = x + dx[i];
            int ny = y + dy[i];

            if (IsInside(ny, nx) == true && tomato[nx][ny] == 0)
            {

                pair<int, int> p;

                tomato[nx][ny] = tomato[x][y] + 1;
                p.first = nx;
                p.second = ny;
                q.push(p);
            }
        }
    }
}
int main()
{

    cin >> G >> S;

    for (int i = 0; i < S; i++)
    {
        for (int j = 0; j < G; j++)
        {
            int a;
            cin >> a;
            if (a == 1)
            {

                q.push(make_pair(i, j));
            }
            tomato[i][j] = a;
        }
    }
    bfs();

    for (int i = 0; i < S; i++)
    {
        for (int j = 0; j < G; j++)
        {
            if (tomato[i][j] == 0)
            {
                cout << -1;
                return 0;
            }
            if (tcount < tomato[i][j])
            {
                tcount = tomato[i][j];
            }
        }
    }
    cout << tcount - 1;
}