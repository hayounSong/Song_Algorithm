#include <iostream>
using namespace std;

long long num[1000001];
int main()
{
    int t;
    cin >> t;

    num[1] = 1;
    num[2] = 2;
    num[3] = 4;
    for (int tt = 0; tt < t; tt++)
    {
        int a;
        cin >> a;
        for (int i = 4; i <= a; i++)
        {
            num[i] = (num[i - 3] + num[i - 2] + num[i - 1]) % 1000000009;
        }
        cout << num[a] << "\n";
    }
}