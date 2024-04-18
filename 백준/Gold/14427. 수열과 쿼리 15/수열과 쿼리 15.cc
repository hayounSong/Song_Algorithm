#include <iostream>
using namespace std;
int num[1000001] = {0};
int seg[1000001] = {0};
int N, M;

int inits(int start, int end, int node)
{
    if (start == end)
    {
        return seg[node] = start;
    }
    else
    {
        int mid = (start + end) / 2;
        int a = inits(start, mid, node * 2);
        int b = inits(mid + 1, end, node * 2 + 1);
        if (num[a] < num[b])
        {
            return seg[node] = a;
        }
        else if (num[a] == num[b])
        {
            if (a <= b)
            {
                return seg[node] = a;
            }
            else
            {
                return seg[node] = b;
            }
        }
        else
        {
            return seg[node] = b;
        }
    }
}

int update(int start, int end, int node, int target)
{
    if (target < start || target > end || start == end)
    {
        return seg[node];
    }
    int mid = (start + end) / 2;
    int a = update(start, mid, node * 2, target);
    int b = update(mid + 1, end, node * 2 + 1, target);
    if (num[a] < num[b])
    {
        return seg[node] = a;
    }
    else if (num[a] == num[b])
    {
        if (a <= b)
        {
            return seg[node] = a;
        }
        else
        {
            return seg[node] = b;
        }
    }
    else
    {
        return seg[node] = b;
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    cin >> M;
    inits(0, N - 1, 1);
    for (int i = 0; i < M; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int b, c;
            cin >> b >> c;
            num[b - 1] = c;
            update(0, N - 1, 1, b - 1);
        }
        else
        {
            cout << seg[1] + 1 << "\n";
        }
    }
}