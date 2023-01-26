#include <iostream>

using namespace std;
unsigned long long sum(unsigned long long a, unsigned long long b, unsigned long long c)
{
    if (b == 1)
    {
        return a;
    }
    if (b % 2 == 0)
    {
        unsigned long long d;
        d = sum(a % c, b / 2, c) % c;
        return d % c * d % c % c;
    }
    if (b % 2 == 1)
    {
        unsigned long long d;
        d = sum(a % c, b / 2, c) % c;
        return (a % c * d % c * d % c) % c;
    }
}

int main()
{
    unsigned long long a;
    unsigned long long b;
    unsigned long long c;

    cin >> a;
    cin >> b;
    cin >> c;

    cout << sum(a, b, c) % c;
}