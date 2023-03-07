#include <iostream>
#include <queue>
using namespace std;

int n, w, L;
int truck[1001];
int main()
{
    cin >> n >> w >> L;

    for (int i = 0; i < n; i++)
    {
        cin >> truck[i];
    }

    int time = 0;
    int truckindex = 0;
    queue<int> q;
    int cweight = 0;
    while (true)
    {
        if (truckindex == n)
        {
            cout << time + w;
            break;
        }
        if (cweight + truck[truckindex] <= L)
        {
            cweight = cweight + truck[truckindex];
            q.push(truck[truckindex]);
            truckindex++;
        }
        else
        {
            q.push(0);
        }
        if (q.size() == w)
        {
            cweight = cweight - q.front();
            q.pop();
        }
        time++;
    }
}