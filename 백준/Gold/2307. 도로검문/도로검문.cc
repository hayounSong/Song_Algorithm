#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int maxi = 0;
int mini = 0;
int N, M;
vector<pair<int, int>> v[1001];
vector<int> root[1001];
int visited[1001] = {0};
void daick(int start)
{
    priority_queue<pair<int, int>> q;
    q.push({0, start});
    root[start].push_back(start);
    while (!q.empty())
    {

        int fw = q.top().second;
        int fv = -q.top().first;
        q.pop();
        if (fv > visited[fw])
        {
            continue;
        }
        if (fw == N)
        {
            continue;
        }
        for (int i = 0; i < v[fw].size(); i++)
        {
            int dw = v[fw][i].second;
            int dv = v[fw][i].first;
            if (dv + fv < visited[dw])
            {
                visited[dw] = dv + fv;
                q.push({-visited[dw], dw});
                root[dw] = root[fw];
                root[dw].push_back(dw);
            }
        }
    }
}

void ndaick(int start, int ss, int ee)
{

    priority_queue<pair<int, int>> q;
    q.push({0, start});
    while (!q.empty())
    {
        int fw = q.top().second;
        int fv = -q.top().first;
        q.pop();
        if (fv > visited[fw])
        {
            continue;
        }
        if (fw == N)
        {
            continue;
        }
        for (int i = 0; i < v[fw].size(); i++)
        {
            int dw = v[fw][i].second;
            int dv = v[fw][i].first;
            // cout << fw << " " << dw;
            if (fw == ss && dw == ee)
            {
                continue;
            }
            if (dw == ss && fw == ee)
            {
                continue;
            }
            if (dv + fv < visited[dw])
            {
                visited[dw] = dv + fv;
                q.push({-visited[dw], dw});
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({c, b});
        v[b].push_back({c, a});
    }
    for (int i = 1; i <= N; i++)
    {
        visited[i] = 987654321;
    }
    daick(1);
    mini = visited[N];
    for (int i = 0; i < root[N].size() - 1; i++)
    {
        int start = root[N][i];
        int end = root[N][i + 1];
        for (int j = 1; j <= N; j++)
        {
            visited[j] = 987654321;
        }
        ndaick(1, start, end);
        if (visited[N] > maxi)
        {
            maxi = visited[N];
        }
    }
    // for (int i = 0; i < root[N].size(); i++)
    // {
    //     cout << root[N][i];
    // }
    // cout << mini;
    if (maxi == 987654321 || maxi - mini <= 0)
    {
        cout << -1;
    }
    else
    {
        cout << maxi - mini;
    }
}