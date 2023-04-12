#include <iostream>
#include <stack>
using namespace std;

int tower[500001];
int ans[500001];
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> tower[i];
    }

    stack<pair<int, int>> s;

    for (int i = t; i > 0; i--)
    {
        if (s.empty())
        {
            s.push({i, tower[i]});
        }
        else
        {
            int a = s.top().first;
            int b = s.top().second;
            while (b < tower[i] && !s.empty())
            {

                ans[a] = i;

                s.pop();
                if (!s.empty())
                {
                    a = s.top().first;
                    b = s.top().second;
                }
            }
            s.push({i, tower[i]});
        }
    }

    for (int i = 1; i <= t; i++)
    {
        cout << ans[i] << " ";
    }
}