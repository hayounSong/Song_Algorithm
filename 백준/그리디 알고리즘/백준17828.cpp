#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int main()
{

    long long N;
    long long X;

    cin >> N >> X;
    if (26 * N < X)
    {
        cout << "!";
        return 0;
    }
    if (X < N)
    {
        cout << "!";
        return 0;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 26; j >= 1; j--)
        {
            if (X - j >= N - i - 1)
            {
                v.push_back(j);
                X = X - j;
                break;
            }
        }
    }

    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << char('A' + v[i] - 1);
    }
}