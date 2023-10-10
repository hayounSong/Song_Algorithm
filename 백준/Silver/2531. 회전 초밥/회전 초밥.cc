#include <iostream>
using namespace std;

int N, d, k, c;
int coll[30011] = {0};
int num[30011] = {0};
int main()
{
    cin >> N >> d >> k >> c;

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int semi = 0;
        for (int j = i; j < i + k; j++)
        {
            int jj = j;
            if (jj >= N)
            {

                jj = jj - N;
            }
            coll[num[jj]]++;
        }
        for (int j = 1; j <= d; j++)
        {
            if (coll[j] > 0)
            {
                semi++;
            }
        }

        if (coll[c] == 0)
        {
            semi++;
        }
        if (semi > ans)
        {

            ans = semi;
        }

        for (int j = 1; j <= d; j++)
        {
            coll[j] = 0;
        }
    }
    // if (ans < k)
    // {
    //     ans = k;
    // }
    cout << ans;
}