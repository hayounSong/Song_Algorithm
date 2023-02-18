#include <iostream>
#include <queue>
using namespace std;

int N;

int num[20][20] = {0};
int direcx[4] = {-1, 0, 0, 1};
int direcy[4] = {0, -1, 1, 0};
int catchfish = 0;
int minrange = 9999999;
int sharkx, sharky;
int csize = 2;
int sizecount = 0;
int minx = 99999;
int miny = 99999;
int bfs(int startx, int starty, int visited[][20], int size)
{

    queue<pair<int, int>> q;

    q.push({startx, starty});
    if (catchfish == 0)
    {
        visited[startx][starty] = 1;
    }
    else
    {
        visited[startx][starty] = catchfish;
    }
    while (!q.empty())
    {

        int frontx = q.front().first;
        int fronty = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int px = frontx + direcx[i];
            int py = fronty + direcy[i];
            if (px >= 0 && py >= 0 && px < N && py < N)
            {

                if (visited[px][py] == 0)
                {

                    if (num[px][py] == 0 || num[px][py] == 9)
                    {
                        q.push({px, py});
                        visited[px][py] = visited[frontx][fronty] + 1;
                    }
                    else
                    {
                        if (num[px][py] == size)
                        {
                            q.push({px, py});
                            visited[px][py] = visited[frontx][fronty] + 1;
                        }
                        else if (num[px][py] > size)
                        {
                            continue;
                        }
                        else
                        {

                            if (minrange != 999999)
                            {

                                if (visited[frontx][fronty] + 1 > minrange)
                                {

                                    continue;
                                }
                                if (visited[frontx][fronty] + 1 == minrange)
                                {

                                    if (px > minx)
                                    {

                                        continue;
                                    }

                                    if (px == minx)
                                    {
                                        if (py > miny)
                                        {
                                            continue;
                                        }
                                    }
                                }
                            }

                            catchfish = visited[frontx][fronty] + 1;

                            sharkx = px;
                            sharky = py;
                            minrange = visited[frontx][fronty] + 1;

                            minx = px;
                            miny = py;
                        }
                    }
                }
            }
        }
    }
    return minrange;
}
int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> num[i][j];
            if (num[i][j] == 9)
            {
                sharkx = i;
                sharky = j;
                num[i][j] = 0;
            }
        }
    }

    while (1)
    {

        if (sizecount == csize)
        {
            csize = csize + 1;
            sizecount = 0;
        }
        minrange = 999999;
        int visited[20][20] = {0};

        bfs(sharkx, sharky, visited, csize);
        if (minrange != 999999)
        {
            num[minx][miny] = 0;
            sharkx = minx;
            sharky = miny;
        }

        if (minrange == 999999)
        {
            if (catchfish == 0)
            {
                cout << 0;
                return 0;
            }
            cout << catchfish - 1;
            return 0;
        }
        sizecount++;
    }
}