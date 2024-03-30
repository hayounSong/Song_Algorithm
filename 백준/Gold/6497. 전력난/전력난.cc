#include <iostream>
#include <queue>
using namespace std;
long parent[200001] = {0};
long N, M;

long find(long a)
{
    if (a == parent[a])
    {
        return a;
    }
    else
    {
        return find(parent[a]);
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<pair<long, pair<long, long>>> pq;
    while (true)
    {
        cin >> N >> M;
        if (N == 0 && M == 0)
        {
            break;
        }
        for (long i = 0; i <= N; i++)
        {
            parent[i] = i;
        }
        long origin = 0;
        for (long i = 0; i < M; i++)
        {
            long a, b, c;
            cin >> a >> b >> c;
            origin = origin + c;
            pq.push({-c, {a, b}});
        }

        long ans = 0;
        while (!pq.empty())
        {
            long fv = -pq.top().first;
            long fa = pq.top().second.first;
            long fb = pq.top().second.second;
            long ffa = find(fa);
            long ffb = find(fb);
            pq.pop();
            if (ffa == ffb)
            {
                continue;
            }
            else
            {
                if (ffa < ffb)
                {
                    parent[ffb] = ffa;
                }
                else
                {
                    parent[ffa] = ffb;
                }
                ans = ans + fv;
            }
        }
        cout << origin - ans << "\n";
    }
}