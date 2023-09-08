#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<pair<int, int>> v;
int startx, starty;
int n;
int finalx, finaly;
int ans = 0;
int visited[101] = {0};

void bfs(int startx, int starty)
{

    queue<pair<int, int>> q;
    q.push({startx, starty});

    while (!q.empty())
    {

        int frontx = q.front().first;
        int fronty = q.front().second;
        q.pop();
        // cout << finalx - frontx + finaly - fronty;
        if (abs(finalx - frontx) + abs(finaly - fronty) <= 1000)
        {
            cout << "happy"
                 << "\n";
            ans = 1;
            break;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (visited[i] == 1)
                {
                    continue;
                }
                else
                {
                    if (abs(v[i].first - frontx) + abs(v[i].second - fronty) <= 1000)
                    {
                        visited[i] = 1;
                        q.push({v[i].first, v[i].second});
                    }
                }
            }
        }
    }
}
int main()
{
    int tt;
    cin >> tt;

    for (int t = 0; t < tt; t++)
    {
        ans = 0;
        cin >> n;
        cin >> startx >> starty;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
            visited[i] = 0;
        }
        cin >> finalx >> finaly;

        bfs(startx, starty);
        if (ans == 0)
        {
            cout << "sad"
                 << "\n";
        }
        while (!v.empty())
        {
            v.pop_back();
        }
    }
}