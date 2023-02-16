#include <iostream>
#include <algorithm>
using namespace std;
int input[101];
int coin[10001] = {0};
int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    sort(input, input + n);

    coin[0] = 1;
    for (int j = 0; j < n; j++)
    {
        for (int i = input[j]; i <= k; i++)
        {
            coin[i] = coin[i] + coin[i - input[j]];
        }
    }

    cout << coin[k];
}