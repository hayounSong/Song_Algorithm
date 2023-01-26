#include <iostream>
using namespace std;

int main()
{

    unsigned long long G[2000000];

    unsigned long long n;

    cin >> n;
    G[1] = 1;
    G[2] = 2;
    for (unsigned long long a = 2; a <= n;)
    {
        unsigned long long b;
        unsigned long long temp = G[a];
        unsigned long long d;
        for (d = a; d < G[temp] + a; d++)
        {
            if (d > n)
            {
                break;
            }
            G[d] = temp;
        }

        G[d] = temp + 1;
        a = d;
    }
    cout << G[n];

    return 0;
}