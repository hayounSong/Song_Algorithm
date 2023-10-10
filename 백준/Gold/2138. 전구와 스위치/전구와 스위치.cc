#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
int ans[100001];
int num[100001];
int num2[100001];
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    char c[100001];

    cin >> c;

    for (int i = 0; i < N; i++)
    {
        num[i] = c[i] - '0';
        num2[i] = c[i] - '0';
    }

    char a[100001];
    cin >> a;

    for (int i = 0; i < N; i++)
    {
        ans[i] = a[i] - '0';
    }
    int ccount = 0;
    int ccount2 = 1;
    int howmuch = 0;

    for (int i = 1; i < N; i++)
    {
        if (ans[i - 1] != num[i - 1])
        {
            ccount++;
            num[i - 1] = abs(num[i - 1] - 1);
            num[i] = abs(num[i] - 1);
            if (i <= N - 1)
            {
                num[i + 1] = abs(num[i + 1] - 1);
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (ans[i] != num[i])
        {
            ccount = 9999999;
            break;
        }
    }

    num2[0] = abs(num2[0] - 1);
    num2[1] = abs(num2[1] - 1);
    for (int i = 1; i < N; i++)
    {
        if (ans[i - 1] != num2[i - 1])
        {
            ccount2++;
            num2[i - 1] = abs(num2[i - 1] - 1);
            num2[i] = abs(num2[i] - 1);
            if (i <= N - 1)
            {
                num2[i + 1] = abs(num2[i + 1] - 1);
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (ans[i] != num2[i])
        {
            ccount2 = 9999999;
            break;
        }
    }

    if (ccount == 9999999 && ccount2 == 9999999)
    {
        cout << -1;
    }
    else
    {
        cout << min(ccount, ccount2);
    }
}