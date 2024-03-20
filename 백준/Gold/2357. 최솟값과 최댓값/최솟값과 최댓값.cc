#include <iostream>
using namespace std;
long long num[1000001] = {0};
long long seg[1000001] = {0};
long long segm[1000001] = {0};
int N, M;

long long init(int start, int end, long long node)
{
    if (start == end)
    {
        seg[node] = num[start];
        return seg[node];
    }

    int mid = (start + end) / 2;
    return seg[node] = max(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}
long long initm(int start, int end, long long node)
{
    if (start == end)
    {
        segm[node] = num[start];
        return segm[node];
    }

    int mid = (start + end) / 2;
    return segm[node] = min(initm(start, mid, node * 2), initm(mid + 1, end, node * 2 + 1));
}

long long find(int start, int end, long long node, int left, int right)
{
    if (left > end || right < start)
    {
        return 0;
    }
    if (left <= start && end <= right)
    {
        return seg[node];
    }
    int mid = (start + end) / 2;
    return max(find(start, mid, node * 2, left, right), find(mid + 1, end, node * 2 + 1, left, right));
}
long long findm(int start, int end, long long node, int left, int right)
{
    if (left > end || right < start)
    {
        return 1000000001;
    }
    if (left <= start && end <= right)
    {
        return segm[node];
    }
    int mid = (start + end) / 2;
    return min(findm(start, mid, node * 2, left, right), findm(mid + 1, end, node * 2 + 1, left, right));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    init(0, N - 1, 1);
    initm(0, N - 1, 1);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << findm(0, N - 1, 1, a - 1, b - 1) << " ";
        cout << find(0, N - 1, 1, a - 1, b - 1) << "\n";
    }
}