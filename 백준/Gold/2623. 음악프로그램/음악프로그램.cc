#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int value[1001];
vector<int> v[1001];
int visited[1001];
int main()
{
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int aa;
        cin >> aa;
        vector<int> imsi;
        for (int j = 0; j < aa; j++)
        {
            int a;
            cin >> a;
            imsi.push_back(a);
        }
        for (int j = 1; j < aa; j++)
        {
            value[imsi[j]]++;
            v[imsi[j - 1]].push_back(imsi[j]);
        }
    }
    vector<int> ans;
    int alright = 0;
    while (ans.size() < N)
    {
        queue<int> check;
        for (int i = 1; i <= N; i++)
        {
            if (value[i] == 0 && visited[i] == 0)
            {
                check.push(i);
                visited[i] = 1;
            }
        }
        if (check.size() == 0)
        {
            alright = 1;
            break;
        }
        while (!check.empty())
        {
            int front = check.front();
            for (int i = 0; i < v[front].size(); i++)
            {
                value[v[front][i]]--;
            }
            ans.push_back(front);
            check.pop();
        }
    }
    if (alright == 0)
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << "\n";
        }
    }
    else
    {
        cout << 0;
    }
}