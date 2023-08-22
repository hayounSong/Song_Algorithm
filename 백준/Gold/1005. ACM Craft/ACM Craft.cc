#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int N, K;
        int value[1001] = {0};
        int lcount[1001] = {0};
        int result[1001] = {0};
        int ansvalue = 0;
        cin >> N >> K;
        vector<int> ans;
        for (int i = 1; i <= N; i++)
        {
            int a;
            cin >> a;
            value[i] = a;
            result[i] = a;
        }
        vector<int> v[1001];

        for (int i = 0; i < K; i++)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            lcount[b]++;
        }
        int W;
        cin >> W;
        queue<int> q;

        while (ans.size() < N)
        {
            for (int i = 1; i <= N; i++)
            {
                if (lcount[i] == 0)
                {
                    q.push(i);
                }
            }
            int maxi = 0;
            int finding = 0;

            while (!q.empty())
            {
                if (lcount[q.front()] != -1)
                {
                    ans.push_back(q.front());
                    lcount[q.front()] = -1;
                    if (value[q.front()] > maxi)
                    {
                        maxi = value[q.front()];
                    }
                }

                for (int i = 0; i < v[q.front()].size(); i++)
                {
                    lcount[v[q.front()][i]]--;
                    if (lcount[v[q.front()][i]] == 0)
                    {
                        q.push(v[q.front()][i]);
                    }

                    result[v[q.front()][i]] = max(result[v[q.front()][i]], value[v[q.front()][i]] + result[q.front()]);
                }

                q.pop();
            }
            ansvalue = ansvalue + maxi;
            if (finding == 1)
            {
                break;
            }
        }
        // for (int i = 1; i <= N; i++)
        // {
        cout << result[W] << " ";
        // }
    }
}