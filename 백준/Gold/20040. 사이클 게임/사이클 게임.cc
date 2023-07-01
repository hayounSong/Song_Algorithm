#include <iostream>
using namespace std;

int n, m;
int parent[500001];

int find(int a)
{
    while (a != parent[a])
    {
        a = parent[a];
    }
    return a;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b))
        {
            cout << i + 1;
            return 0;
        }
        else
        {
            parent[find(b)] = find(a);
        }
    }
    cout << 0;
}