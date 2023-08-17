#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int ans[1000001];
int main()
{
    stack<pair<int, int>> s;

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;

        if (s.empty())
        {
            s.push({a, i});
        }
        else
        {
            while (!s.empty() && s.top().first < a)
            {
                ans[s.top().second] = a;
                s.pop();
            }
            s.push({a, i});
        }
    }
    while (!s.empty())
    {
        ans[s.top().second] = -1;
        s.pop();
    }

    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << " ";
    }
}