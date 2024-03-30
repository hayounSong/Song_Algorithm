#include <iostream>
#include <vector>
using namespace std;
int N, M;
int parent[201] = {0};
int find(int a)
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
    cin >> N >> M;
    for (int i = 0; i <= N; i++)
    {
        parent[i] = i;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int a;
            cin >> a;
            if (a == 1)
            {
                parent[find(i)] = find(j);
            }
        }
    }
    int start = -1;
    for (int i = 0; i < M; i++)
    {
        int a;
        cin >> a;
        if (i == 0)
        {
            start = find(a);
        }
        else
        {
            if (find(a) != start)
            {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}