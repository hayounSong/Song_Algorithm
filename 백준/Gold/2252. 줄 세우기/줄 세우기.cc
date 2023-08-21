#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> line[100001];
int lcount[32001] = {0};
int N, M;
int main()
{
    cin >> N >> M;
    vector<int> ans;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        line[a].push_back(b);
        lcount[b]++;
    }
    queue<int> zeroq;
    while (ans.size() < N)
    {
        for (int i = 1; i <= N; i++)
        {
            if (lcount[i] == 0)
            {

                zeroq.push(i);
            }
        }

        while (!zeroq.empty())
        {
            if (lcount[zeroq.front()] != -1)
            {
                ans.push_back(zeroq.front());
                lcount[zeroq.front()] = -1;
            }
            for (int i = 0; i < line[zeroq.front()].size(); i++)
            {
                lcount[line[zeroq.front()][i]]--;
            }
            zeroq.pop();
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}