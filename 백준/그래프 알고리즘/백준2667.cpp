#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int apart[26][26] = {0};
int visited[26][26] = {0};
vector<int> ans_apart;
int ans = 0;
int direcx[4] = {1, 0, -1, 0};
int direcy[4] = {0, -1, 0, 1};
int N;
void bfs(int startx, int starty)
{
    queue<pair<int, int>> q;

    q.push(make_pair(startx, starty));
    visited[startx][starty] = 1;
    ans++;
    while (!q.empty())
    {

        int frontx = q.front().first;
        int fronty = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int dx = frontx + direcx[i];
            int dy = fronty + direcy[i];
            if (dx >= 0 && dx < N && dy >= 0 && dy < N)
            {
                if (visited[dx][dy] == 0 && apart[dx][dy] == 1)
                {
                    visited[dx][dy] = 1;
                    q.push(make_pair(dx, dy));
                    ans++;
                }
            }
        }
    }
}

int main()
{

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string a;
        cin >> a;
        for (int j = 0; j < N; j++)
        {
            apart[i][j] = a[j] - '0';
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j] == 0 && apart[i][j] == 1)
            {

                bfs(i, j);
                ans_apart.push_back(ans);

                ans = 0;
            }
        }
    }
    sort(ans_apart.begin(), ans_apart.end());
    cout << ans_apart.size() << "\n";

    for (int i = 0; i < ans_apart.size(); i++)
    {
        cout << ans_apart[i] << "\n";
    }
}