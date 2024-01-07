#include <iostream>
using namespace std;

int num[31][31] = {0};
int main()
{
    int tt;
    cin >> tt;

    for (int t = 0; t < tt; t++)
    {
        int N, M;
        cin >> N >> M;
        int up = 1;
        long long down = 1;
        int r = 1;
        for (int i = M; i > M - N; i--)
        {
            down = down * i;
            down = down / r;
            r = r + 1;
        }
        cout << down << "\n";
    }
}