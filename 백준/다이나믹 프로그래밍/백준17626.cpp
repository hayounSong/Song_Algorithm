#include <iostream>
#include <cmath>
using namespace std;
int num[50001] = {0};
int sum[50001] = {0};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;

    cin >> n;
    int inde;
    for (int i = 1; i * i <= n; i++)
    {
        int a = i * i;
        sum[a] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (sum[i] == 1)
        {
            num[i] = sum[i];
            continue;
        }
        else
        {
            int ans = 999999;
            int a = sqrt(i);

            for (int b = 1; b <= a; b++)
            {

                if (ans > num[b * b] + num[i - b * b])
                {
                    inde = b;
                    ans = num[b * b] + num[i - b * b];
                    // cout << i << b << num[b * b] << num[i - b * b] << " ";
                }
            }
            num[i] = ans;
        }
    }
    // cout << inde << " ";
    cout << num[n];
}