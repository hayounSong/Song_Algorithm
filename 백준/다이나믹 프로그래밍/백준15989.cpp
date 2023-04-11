#include <iostream>
#include <algorithm>
using namespace std;
int num[10001][4];
int main()
{
    int T;
    cin >> T;

    num[1][1] = 1;
    num[1][2] = 0;
    num[1][3] = 0;
    num[2][1] = 1;
    num[2][2] = 1;
    num[2][3] = 0;
    num[3][1] = 1;
    num[3][2] = 1;
    num[3][3] = 1;

    for (int i = 4; i < 10001; i++)
    {
        num[i][1] = num[i - 1][1];
        num[i][2] = num[i - 2][1] + num[i - 2][2];
        num[i][3] = num[i - 3][1] + num[i - 3][2] + num[i - 3][3];
    }

    for (int i = 0; i < T; i++)
    {
        int a;
        cin >> a;
        cout << num[a][1] + num[a][2] + num[a][3] << "\n";
    }
}
