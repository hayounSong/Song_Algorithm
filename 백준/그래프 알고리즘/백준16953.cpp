#include <iostream>
#include <queue>
#include <map>
using namespace std;

long A, B;
int ans = 0;
map<long, long> m;
void bfs(long A, long B)
{
    if (A == B)
    {
        cout << ans;
        return;
    }
    else
    {
        queue<int> q;
        q.push(A);
        m[A] = 1;
        while (!q.empty())
        {

            long front = q.front();
            if (front == B)
            {
                cout << m[front];
                return;
            }
            q.pop();

            if (front * 2 <= B)
            {
                q.push(front * 2);
                m[front * 2] = m[front] + 1;
            }
            if (front * 10 + 1 <= B)
            {
                q.push(front * 10 + 1);
                m[front * 10 + 1] = m[front] + 1;
            }
            ans++;
        }
        cout << -1;
    }
}

int main()
{
    cin >> A >> B;

    bfs(A, B);

    // cout << ans;
}