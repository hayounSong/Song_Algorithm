#include <iostream>
#include <algorithm>

using namespace std;

long long num[2][100001] = {0};
long long check[2][100001] = {0};

int main()
{

    int T;

    cin >> T;

    for (int t = 0; t < T; t++)
    {
        long N;
        cin >> N;
        for (long i = 0; i < N; i++)
        {
            cin >> num[0][i];
        }
        for (long i = 0; i < N; i++)
        {
            cin >> num[1][i];
        }

        for (long i = N - 1; i >= 0; i--)
        {
            for (long j = 0; j < 2; j++)
            {
                if (i == N - 1)
                {
                    check[j][i] = num[j][i];
                }
                else if (i + 2 >= N)
                {
                    if (j == 0)
                    {
                        check[j][i] = num[j][i] + check[1][i + 1];
                    }
                    else
                    {
                        check[j][i] = num[j][i] + check[0][i + 1];
                    }
                }

                else
                {
                    if (j == 0)
                    {
                        check[j][i] = num[j][i] + max({num[1][i + 1] + check[0][i + 2], check[1][i + 2], check[1][i + 1]});
                    }
                    else
                    {
                        check[j][i] = num[j][i] + max({num[0][i + 1] + check[1][i + 2], check[0][i + 2], check[0][i + 1]});
                    }
                }
            }
        }

        cout << max(check[0][0], check[1][0]) << '\n';
    }
}