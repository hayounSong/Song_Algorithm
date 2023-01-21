#include <iostream>
using namespace std;

int main()
{

    int m, n;

    cin >> n >> m;

    unsigned long long num = 1;

    if (m >= n / 2)
    {

        for (int i = m + 1; i <= n; i++)
        {
            num = num * i;
        }
        unsigned long long mi = 1;

        for (int i = n - m; i >= 1; i--)
        {
            num = num / i;
        }
        cout << num;
    }
    else
    {
        for (int i = n - m + 1; i <= n; i++)
        {
            num = num * i;
        }
        unsigned long long mi = 1;
        for (int i = m; i >= 1; i--)
        {
            num = num / i;
        }
        cout << num;
    }
}