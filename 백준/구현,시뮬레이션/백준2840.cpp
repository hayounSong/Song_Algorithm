#include <iostream>
#include <map>
using namespace std;

int N, K;
map<int, char> m;
map<char, int> check;
int main()
{
    cin >> N >> K;
    int current = 0;
    for (int i = 0; i < K; i++)
    {
        int a;
        char b;
        cin >> a;
        cin >> b;
        current = current + a;
        if (!m[current % N])
        {
            if (check[b])
            {
                cout << "!";
                return 0;
            }
            m[current % N] = b;
            check[b] = 1;
        }
        else
        {
            if (m[current % N] != b)
            {
                cout << "!";
                return 0;
            }
        }
    }

    current = current % N;
    int pcount = 0;
    while (pcount < N)
    {
        if (current == -1)
        {

            current = N - 1;
        }
        if (m[current])
        {
            cout << m[current];
        }
        else
        {
            cout << "?";
        }
        pcount++;
        if (current == -1)
        {

            current = N - 1;
        }
        else
        {
            current--;
        }
    }
}