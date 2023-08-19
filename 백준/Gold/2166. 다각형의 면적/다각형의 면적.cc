#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
pair<long double, long double> s[10001];
long double square(pair<long double, long double> s2, pair<long double, long double> s3)
{

    return (s[0].first * s2.second + s2.first * s3.second + s3.first * s[0].second - s2.first * s[0].second - s3.first * s2.second - s[0].first * s3.second) / 2;
}
int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        long double a, b;
        cin >> a >> b;
        s[i] = {a,
                b};
    }
    long double ans = 0;
    for (int i = 0; i < N - 2; i++)
    {
        ans = ans + square(s[i + 1], s[i + 2]);
    }
    cout << fixed;
    cout.precision(1);
    cout << abs(ans);
}