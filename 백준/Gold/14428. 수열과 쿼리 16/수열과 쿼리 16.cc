#include <iostream>
using namespace std;

long long num[1000005] = {0};
long long tree[5000001] = {0};
long long N, M;

long long init(long long start, long long end, long long node)
{
    if (start == end)
    {
        tree[node] = start;
        return tree[node];
    }

    long long mid = (start + end) / 2;
    long long a = init(start, mid, node * 2);
    long long b = init(mid + 1, end, node * 2 + 1);
    if (num[a] < num[b])
    {
        return tree[node] = a;
    }
    else if (num[a] == num[b])
    {
        if (a < b)
        {
            return tree[node] = a;
        }
        else
        {
            return tree[node] = b;
        }
    }
    else
    {
        return tree[node] = b;
    }
}

long long update(long long start, long long end, long long node, long long target, long long diff)
{
    if (target < start || target > end)
    {
        return tree[node];
    }
    else if (start == end)
    {
        return tree[node];
    }
    long long mid = (start + end) / 2;
    long long a = update(start, mid, node * 2, target, diff);
    long long b = update(mid + 1, end, node * 2 + 1, target, diff);
    if (num[a] < num[b])
    {
        return tree[node] = a;
    }
    else if (num[a] == num[b])
    {
        if (a < b)
        {
            return tree[node] = a;
        }
        else
        {
            return tree[node] = b;
        }
    }
    else
    {
        return tree[node] = b;
    }
}

long long find(long long start, long long end, long long left, long long right, long long node)
{
    if (left > end || right < start)
    {
        return 0;
    }
    if (left <= start && end <= right)
    {
        return tree[node];
    }

    long long mid = (start + end) / 2;
    long long a = find(start, mid, left, right, node * 2);
    long long b = find(mid + 1, end, left, right, node * 2 + 1);
    // if (a > right || a < left)
    // {
    //     a = 0;
    // }
    // if (b > right || b < left)
    // {
    //     b = 0;
    // }
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }
    if (num[a] < num[b])
    {
        return a;
    }
    else if (num[a] == num[b])
    {
        if (a < b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
    else
    {
        return b;
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    num[0] = 9876543210;
    for (long long i = 1; i <= N; i++)
    {
        cin >> num[i];
    }
    cin >> M;
    init(1, N, 1);
    for (long long i = 0; i < M; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            num[b] = c;
            update(1, N, 1, b, c);
        }
        else
        {
            cout << find(1, N, b, c, 1) << "\n";
        }
    }
}