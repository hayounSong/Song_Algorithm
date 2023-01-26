#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct cmp
{
    bool operator()(int a, int b)
    {
        int ta = a;
        int tb = b;
        if (a < 0)
        {
            ta = a * -1;
        }
        if (b < 0)
        {
            tb = tb * -1;
        }
        if (ta == tb)
        {
            return a > b;
        }
        else
        {
            return ta > tb;
        }
    }
};

int main()
{

    priority_queue<int, vector<int>, cmp> q;

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        if (a == 0)
        {
            if (q.empty())
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << q.top() << "\n";
                q.pop();
            }
        }
        else
        {
            q.push(a);
        }
    }
}