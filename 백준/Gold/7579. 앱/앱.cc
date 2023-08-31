#include <iostream>
using namespace std;

int num[101][10001] = {0};
int N, M;
int bytel[10000001];
int cost[10000001];
int main()
{
    cin >> N;
    cin >> M;

    for (int i = 1; i <= N; i++)
    {
        cin >> bytel[i];
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> cost[i];
    }
    int amin = 999999;

    for (int i = 1; i <= 100; i++)
    {

        for (int j = 1; j <= 10000; j++)
        {

            if (cost[i] > j)
            {
                num[i][j] = num[i - 1][j];
            }
            else
            {

                num[i][j] = max(bytel[i] + num[i - 1][j - cost[i]], num[i - 1][j]);

                // cout << bytel[i] + num[i - 1][j - cost[i]];
                if (num[i][j] >= M)
                {

                    if (j < amin)
                    {
                        if (j == 4)
                        {
                            // cout << "s" << i << " " << j << endl;

                            // cout << num[i - 1][j - cost[i]];
                        }
                        amin = j;
                    }
                }
            }
        }
    }

    cout << amin;
}