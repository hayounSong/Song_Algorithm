#include <iostream>
using namespace std;

int main()
{
    int N;

    cin >> N;

    int list[1001][3];

    for (int i = 0; i < N; i++)
    {
        for (int a = 0; a < 3; a++)
        {
            cin >> list[i][a];
        }
    }

    for (int i = N - 2; i >= 0; i--)
    {

        for (int a = 0; a < 3; a++)
        {
            int min = 999999;
            for (int b = 0; b < 3; b++)
            {
                if (a != b)
                {
                    if (list[i + 1][b] < min)
                    {
                        min = list[i + 1][b];
                    }
                }
            }
            list[i][a] = list[i][a] + min;
        }
    }
    int ans = 999999;
    for (int i = 0; i < 3; i++)
    {
        if (list[0][i] < ans)
        {
            ans = list[0][i];
        }
    }
    cout << ans;
}