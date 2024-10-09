#include <iostream>
#include <vector>
using namespace std;

vector<int> node[100001];

int ncount[100001] = {0};
int N, R, Q;

int getnum(int s)
{
    ncount[s] = 1;
    for (int i = 0; i < node[s].size(); i++)
    {
        if (ncount[node[s][i]] >= 1)
        {
            continue;
        }
        int a = getnum(node[s][i]);
        ncount[s] = ncount[s] + a;
    }
    return ncount[s];
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> R >> Q;
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
        ncount[i + 1] = 0;
    }
    getnum(R);
    for (int i = 0; i < Q; i++)
    {
        int a;
        cin >> a;
        cout << ncount[a] << "\n";
    }
}