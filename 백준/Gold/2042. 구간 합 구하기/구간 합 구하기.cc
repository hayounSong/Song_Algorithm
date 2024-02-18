#include <iostream>
using namespace std;
long long N, M, K;
long long num[10000001] = {0};
long long tree[10000001] = {0};

long long init(long long start, long long end, long long node)
{
    if (start == end)
    {
        tree[node] = num[start];
        return tree[node];
    }
    long long mid = (start + end) / 2;

    tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
    return tree[node];
}

void update(long long start, long long end, long long node, long long target, long long diff)
{
    if (target > end || target < start)
    {
        return;
    }
    tree[node] = tree[node] + diff;
    if (start == end)
    {
        return;
    }
    long long mid = (start + end) / 2;

    update(start, mid, node * 2, target, diff);
    update(mid + 1, end, node * 2 + 1, target, diff);
}

long long sum(long long start, long long end, long long node, long long left, long long right)
{
    if (start > right || end < left)
    {
        return 0;
    }
    if (left <= start && end <= right)
    {
        return tree[node];
    }
    long long mid = (start + end) / 2;
    long long ans = sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
    return ans;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;
    for (long long i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    init(0, N - 1, 1);
    for (long i = 0; i < M + K; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            long long diff = c - num[b - 1];
            num[b - 1] = c;
            update(0, N - 1, 1, b - 1, diff);
        }
        if (a == 2)
        {
            cout << sum(0, N - 1, 1, b - 1, c - 1) << "\n";
        }
    }
}