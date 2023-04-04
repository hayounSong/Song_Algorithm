#include <iostream>
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
            for (int a = i; a >= i / 2 - 1; a--)
            {

                if (num[a] != 0)
                {

                    if (ans > num[a] + num[i - a])
                    {

                        ans = num[a] + num[i - a];
                        inde = a;
                        // break;
                    }
                }
            }
            num[i] = ans;
        }
    }
    cout << inde << " ";
    cout << num[n];
}