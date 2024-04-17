#include <iostream>
#include <queue>
using namespace std;

int N;
int main()
{
    cin >> N;
    priority_queue<int> q;

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        q.push(-a);
    }
    int ans = 0;
    int coun = 0;
    while (!q.empty())
    {
        int fq = -q.top();
        q.pop();
        if (q.empty())
        {
            break;
        }
        int fq2 = -q.top();
        q.pop();
        coun = fq + fq2;
        ans = ans + coun;
        q.push(-coun);
    }
    cout << ans;
}