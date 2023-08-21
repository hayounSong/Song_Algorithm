#include <queue>
#include <iostream>
using namespace std;

int N, M;
vector<int> v[100001];
int lcount[32001] = {0};
int main()
{
    cin >> N >> M;
    vector<int> ans;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        lcount[b]++;
    }

    while (ans.size() < N)
    {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 1; i <= N; i++)
        {
            if (lcount[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            if (lcount[q.top()] != -1)
            {
                ans.push_back(q.top());
                lcount[q.top()] = -1;
            }
            queue<int> zlist;
            for (int i = 0; i < v[q.top()].size(); i++)
            {

                lcount[v[q.top()][i]]--;
                if (lcount[v[q.top()][i]] == 0)
                {
                    zlist.push(v[q.top()][i]);
                }
            }

            q.pop();
            while (!zlist.empty())
            {
                q.push(zlist.front());
                zlist.pop();
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << " ";
    }
}