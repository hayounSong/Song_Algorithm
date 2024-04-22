#include <iostream>
using namespace std;

long long num[100001] = {0};
long long tree[10000001] = {0};

long long N, M;

long long init(long long start, long long end, long long node)
{
    if (start == end)
    {
        return tree[node] = num[start];
    }
    long long mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long find(long long start, long long end, long long node, long long left, long long right)
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
    return (find(start, mid, node * 2, left, right) + find(mid + 1, end, node * 2 + 1, left, right));
}

void updated(long long start, long long end, long long node, long long target, long long diff)
{
    if (target < start || target > end)
    {
        return;
    }
    tree[node] = tree[node] + diff;
    if (start == end)
    {

        return;
    }
    long long mid = (start + end) / 2;
    updated(start, mid, node * 2, target, diff);
    updated(mid + 1, end, node * 2 + 1, target, diff);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (long long i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    init(0, N - 1, 1);
    for (long long i = 0; i < M; i++)
    {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        cout << find(0, N - 1, 1, a - 1, b - 1) << "\n";
        long long temp = num[c - 1];
        num[c - 1] = d;
        long long diff = num[c - 1] - temp;
        updated(0, N - 1, 1, c - 1, diff);
    }
}