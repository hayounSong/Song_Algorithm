#include <iostream>
using namespace std;
#include <stack>

int main()
{
    int N;
    cin >> N;
    stack<int> s;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (num == 0)
        {
            s.pop();
        }
        else
        {
            s.push(num);
        }
    }
    int ans = 0;
    while (!s.empty())
    {
        ans = ans + s.top();
        s.pop();
    }
    cout << ans;
}