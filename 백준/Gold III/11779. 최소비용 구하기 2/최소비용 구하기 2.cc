#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
vector<pair<long, long>> root[1001];
vector<long> how[1001];
long far[1001] = {0};
int st, fi;

void dick()
{
    priority_queue<pair<long, long>> pq;
    pq.push({0, st});
    far[st] = 0;
    how[st].push_back(st);
    while (!pq.empty())
    {
        long fw = pq.top().second;
        long val = -pq.top().first;
        pq.pop();
        if (far[fw] < val)
        {
            continue;
        }
        for (int i = 0; i < root[fw].size(); i++)
        {
            long dw = root[fw][i].second;
            long dva = root[fw][i].first;

            if (far[dw] > val + dva)
            {
                far[dw] = val + dva;
                how[dw] = how[fw];
                how[dw].push_back(dw);
                pq.push({-far[dw], dw});
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
        long a, b, c;
        cin >> a >> b >> c;
        root[a].push_back({c, b});
    }

    cin >> st >> fi;
    for (int i = 0; i <= N; i++)
    {
        far[i] = 987654321;
        // how[i].push_back(i);
    }
    dick();
    cout << far[fi] << "\n";
    cout << how[fi].size() << "\n";
    for (int i = 0; i < how[fi].size(); i++)
    {
        cout << how[fi][i] << " ";
    }
}