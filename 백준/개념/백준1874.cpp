#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;

    stack<int> s;
    queue<char> c;
    int num[n + 1];

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        while (true)
        {
            if (s.size() == 0)
            {
                c.push('+');
                s.push(count);
                count++;
            }
            if (num[i] == s.top())
            {
                s.pop();
                c.push('-');
                break;
            }
            if (num[i] > s.top())
            {
                s.push(count);
                count++;
                c.push('+');
            }
            if (num[i] < s.top())
            {
                cout << "NO";
                return 0;
            }
        }
    }

    while (!c.empty())
    {
        cout << c.front() << "\n";
        c.pop();
    }
}