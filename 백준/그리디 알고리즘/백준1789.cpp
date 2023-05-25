#include <iostream>
using namespace std;

int main()
{
    long long N;
    cin >> N;
    long long cnum = N;
    long long ans = 0;
    for (long long i = 1; i <= cnum; i++)
    {
        if (cnum - i >= 0)
        {
            ans++;
            cnum = cnum - i;
        }
    }
    cout << ans;
}