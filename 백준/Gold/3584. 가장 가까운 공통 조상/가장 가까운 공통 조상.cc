#include <iostream>
#include <queue>
using namespace std;
int T, N;
int node[10001] = {0};

int comp(int a, int b)
{

    queue<pair<int, int>> q;

    q.push({a, b});
    while (!q.empty())
    {
        int fa = q.front().first;
        int fb = q.front().second;
        q.pop();

        if (fa == fb)
        {
            return fa;
        }
        else
        {
            if (node[fb] != fb)
            {
                q.push({fa, node[fb]});
            }
            if (node[fa] != fa)
            {
                q.push({node[fa], fb});
            }
        }
    }
}
int main()
{
    cin >> T;

    for (int tt = 0; tt < T; tt++)
    {
        cin >> N;
        for (int i = 0; i <= N; i++)
        {
            node[i] = i;
        }
        for (int i = 0; i < N - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            node[b] = a;
        }
        int a, b;
        cin >> a >> b;
        cout << comp(a, b) << "\n";
    }
}