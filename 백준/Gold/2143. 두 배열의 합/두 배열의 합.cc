#include <iostream>
#include <map>
using namespace std;

long T;
long n, m;
long anum[1001] = {0};
long bnum[1001] = {0};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    map<long, long> mapa;
    cin >> T;
    cin >> n;
    for (long i = 0; i < n; i++)
    {
        cin >> anum[i];
    }
    cin >> m;
    for (long i = 0; i < m; i++)
    {
        cin >> bnum[i];
    }

    for (long i = 0; i < n; i++)
    {
        long numi = 0;
        for (long j = i; j < n; j++)
        {
            numi = numi + anum[j];
            mapa[numi] += 1;
        }
    }
    long ans = 0;
    for (long i = 0; i < m; i++)
    {
        long numi = 0;
        for (long j = i; j < m; j++)
        {
            numi = numi + bnum[j];
            long su = T - numi;
            if (mapa[su] > 0)
            {
                ans = ans + mapa[su];
            }
        }
    }
    cout << ans;
}