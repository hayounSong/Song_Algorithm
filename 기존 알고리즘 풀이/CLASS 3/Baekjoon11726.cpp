#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int tile[n];
    tile[1] = 1;
    tile[2] = 3;

    for (int i = 3; i <= n; i++)
    {
        tile[i] = (tile[i - 1] + tile[i - 2] * 2) % 10007;
    }
    cout << tile[n] % 10007;
}