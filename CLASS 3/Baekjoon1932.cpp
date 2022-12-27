#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<long long> tri[501];

    for (int i = 1; i <= N; i++)
    {
        for (int a = 0; a < i; a++)
        {
            int d;
            cin >> d;
            tri[i].push_back(d);
        }
    }
    if (N > 1)
    {
        for (int i = N - 1; i >= 1; i--)
        {
            for (int j = 0; j < i; j++)
            {

                tri[i][j] = tri[i][j] + max(tri[i + 1][j], tri[i + 1][j + 1]);
            }
        }
    }
    cout << tri[1][0];
}