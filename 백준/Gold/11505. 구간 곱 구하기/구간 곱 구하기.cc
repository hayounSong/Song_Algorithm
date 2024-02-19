#include <iostream>
using namespace std;

long long N, M, K;
long long num[10000001] = {0};
long long tree[10000001] = {0};

long long init(int start, int end, int node)
{
    if (start == end)
    {
        tree[node] = num[start] % 1000000007;
        return tree[node] % 1000000007;
    }
    else
    {
        int mid = (start + end) / 2;
        tree[node] = init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1) % 1000000007;

        return tree[node] % 1000000007;
    }
}

long long sum(int start, int end, int node, int left, int right)
{
    if (start > right || end < left)
    {
        return 1;
    }
    if (left <= start && end <= right)
    {
        return tree[node] % 1000000007;
    }

    int mid = (start + end) / 2;
    // cout << mid;
    return sum(start, mid, node * 2, left, right) * sum(mid + 1, end, node * 2 + 1, left, right) % 1000000007;
}

void update(int start, int end, int node, int target, long long diff)
{

    if (target > end || target < start)
    {
        return;
    }
    if (diff == 0)
    {
        tree[node] = 0;
    }
    if (start == end)
    {
        tree[node] = diff % 1000000007;
        return;
    }
    else
    {
        int mid = (start + end) / 2;
        update(start, mid, node * 2, target, diff);
        update(mid + 1, end, node * 2 + 1, target, diff);
        tree[node] = tree[node * 2] * tree[node * 2 + 1] % 1000000007;
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    init(0, N - 1, 1);
    for (int i = 0; i < M + K; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {

            update(0, N - 1, 1, b - 1, c);
        }
        if (a == 2)
        {
            cout << sum(0, N - 1, 1, b - 1, c - 1) % 1000000007
                 << "\n";
        }
    }
}