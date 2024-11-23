#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, N, M, K;
vector<pair<int, int>> root[101];
vector<int> people;
int to[101][101];

int main()
{
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int score = 987654321;
        int ans = -1;
        cin >> N >> M;
        for (int i = 0; i < N + 1; i++)
        {
            root[i].clear();
            for (int j = 0; j < N + 1; j++)
            {
                to[i][j] = 987654321;
            }
        }

        for (int i = 0; i < M; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            root[a].push_back({b, c});
            root[b].push_back({a, c});
        }

        cin >> K;
        people.clear();
        for (int i = 0; i < K; i++)
        {
            int a;
            cin >> a;
            people.push_back(a);
        }
        for (int i = 1; i <= N; i++)
        {
            int start = i;

            priority_queue<pair<int, int>> q;
            to[start][start] = 0;
            q.push({0, start});

            while (!q.empty())
            {
                int where = q.top().second;
                int value = -q.top().first;
                q.pop();
                for (int j = 0; j < root[where].size(); j++)
                {

                    int dvalue = value + root[where][j].second;
                    int next = root[where][j].first;

                    if (to[start][next] > dvalue)
                    {
                        to[start][next] = dvalue;
                        q.push({-dvalue, next});
                    }
                }
            }
            int tscore = 0;
            for (int j = 0; j < K; j++)
            {
                tscore = tscore + to[start][people[j]];
            }
            if (tscore < score)
            {
                ans = start;
                score = tscore;
            }
        }
        cout << ans << "\n";
    }
}