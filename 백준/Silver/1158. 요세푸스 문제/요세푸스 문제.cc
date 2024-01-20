#include <iostream>
#include <queue>
using namespace std;

int N, K;
queue<int> v;
queue<int> ans;
int main()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        v.push(i);
    }
    cout << "<";
    for (int i = 1; i <= N - 1; i++)
    {
        for (int j = 0; j < K - 1; j++)
        {
            int a = v.front();
            v.pop();
            v.push(a);
        }
        cout << v.front() << ", ";
        v.pop();
    }
    cout << v.front();
    cout << ">";
    // for (int i = 0; i < N - 1; i++)
    // {
    //     cout << ans.front() << ",";
    //     ans.pop();
    // }
}