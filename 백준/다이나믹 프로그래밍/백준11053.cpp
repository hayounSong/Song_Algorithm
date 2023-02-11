#include <iostream>
using namespace std;
int num[1001] = {0};
int check[1001] = {1};
int N;
int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }

    for (int i = N - 1; i >= 0; i--)
    {
        if (i == N - 1)
        {
            check[i] = 1;
        }
        else
        {
            int max = 0;
            for (int j = i + 1; j <= N - 1; j++)
            {

                if (num[j] > num[i])
                {
                    if (check[j] > max)
                    {
                        max = check[j];
                    }
                }
            }
            check[i] = max + 1;
        }
    }
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        if (check[i] > max)
        {
            max = check[i];
        }
    }
    cout << max;
}