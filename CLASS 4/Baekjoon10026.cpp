#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
int N;
char num[101][101];
int visited[101][101] = {0};
int none = 0;
int nonegreen = 0;
int direcx[4] = {1, 0, -1, 0};
int direcy[4] = {0, -1, 0, 1};
void bfs_green(int startx, int starty)
{
    char co = num[startx][starty];
    queue<pair<int, int>> q;
    pair<int, int> p;
    q.push(make_pair(startx, starty));
    visited[startx][starty] = 1;
    while (!q.empty())
    {
        p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int px = p.first + direcx[i];
            int py = p.second + direcy[i];

            if (px > 0 && px <= N && py > 0 && py <= N)
            {
                if (visited[px][py] == 0)
                {
                    if (num[px][py] == co)
                    {
                        visited[px][py] = 1;
                        q.push(make_pair(px, py));
                    }
                }
            }
        }
    }
}

void bfs_nonegreen(int startx, int starty)
{
    char co = num[startx][starty];
    queue<pair<int, int>> q;
    pair<int, int> p;
    q.push(make_pair(startx, starty));
    visited[startx][starty] = 1;
    while (!q.empty())
    {
        p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int px = p.first + direcx[i];
            int py = p.second + direcy[i];

            if (px > 0 && px <= N && py > 0 && py <= N)
            {
                if (visited[px][py] == 0)
                {
                    if (co == 'G' || co == 'R')
                    {
                        if (num[px][py] == 'G' || num[px][py] == 'R')
                        {
                            visited[px][py] = 1;
                            q.push(make_pair(px, py));
                        }
                    }
                    else
                    {
                        if (num[px][py] == co)
                        {
                            visited[px][py] = 1;
                            q.push(make_pair(px, py));
                        }
                    }
                }
            }
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
            cin >> num[i][j];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (visited[i][j] == 0)
            {
                none++;
                bfs_green(i, j);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            visited[i][j] = 0;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (visited[i][j] == 0)
            {
                nonegreen++;
                bfs_nonegreen(i, j);
            }
        }
    }

    cout << none << " " << nonegreen;
}