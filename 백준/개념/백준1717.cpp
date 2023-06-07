#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

int N, M;
int parent[1000001] = {0};

int findparent(int start)
{
    if (!(parent[start] == start))
    {
        parent[start] = findparent(parent[start]);
        return parent[start];
    }
    return parent[start];
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i <= N; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 0)
        {
            int aa = parent[findparent(c)];
            int bb = parent[findparent(b)];
            if (aa != bb)
            {
                parent[findparent(b)] = findparent(c);
            }
        }
        else
        {
            int bpar = findparent(b);
            int cpar = findparent(c);

            if (bpar == cpar)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}