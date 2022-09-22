#include <iostream>

using namespace std;

int count_sum = 0;
void sumsum(int n, int sum)
{
    if (sum == n)
    {
        count_sum++;
    }
    else
    {
        for (int i = 1; i < 4; i++)
        {
            if (sum + i > n)
            {
                continue;
            }
            else
            {
                sumsum(n, sum + i);
            }
        }
    }
}

int main()
{
    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int n;
        cin >> n;

        sumsum(n, 0);

        cout << count_sum << "\n";
        count_sum = 0;
    }
}