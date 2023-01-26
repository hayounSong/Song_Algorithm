#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;
priority_queue<int, vector<int>, greater<int>> min_queue;
priority_queue<int, vector<int>, less<int>> max_queue;
map<int, int> test;
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        test.clear();
        while (min_queue.empty() == 0)
        {
            min_queue.pop();
        }
        while (max_queue.empty() == 0)
        {
            max_queue.pop();
        }

        int coun;
        cin >> coun;

        for (int j = 0; j < coun; j++)
        {
            char a;
            int b;
            cin >> a >> b;

            if (a == 'I')
            {
                min_queue.push(b);
                max_queue.push(b);
                if (test.count(b) == 0)
                {
                    test[b] = 1;
                }
                else
                {
                    test[b]++;
                }
            }
            if (a == 'D')
            {

                if (b == 1)
                {

                    while (!max_queue.empty() && test[max_queue.top()] == 0)
                    {
                        max_queue.pop();
                    }
                    if (max_queue.empty() == 1)
                    {
                        continue;
                    }
                    // cout << max_queue.top();
                    test[max_queue.top()]--;
                    max_queue.pop();
                }
                if (b == -1)
                {

                    while (!min_queue.empty() && test[min_queue.top()] == 0)
                    {
                        min_queue.pop();
                    }
                    if (min_queue.empty() == 1)
                    {
                        continue;
                    }
                    test[min_queue.top()]--;
                    // cout << min_queue.top() << "s";
                    min_queue.pop();
                }
            }
        }

        while (!max_queue.empty() && test[max_queue.top()] == 0)
        {
            max_queue.pop();
        }
        while (!min_queue.empty() && test[min_queue.top()] == 0)
        {
            min_queue.pop();
        }

        if (max_queue.empty() == 1)
        {
            cout << "EMPTY\n";
        }
        else
        {
            cout << max_queue.top() << " " << min_queue.top() << "\n";
        }
    }
}