#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int N;

long long num[100001];
int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    int mfirst = 0;
    int msecond = N - 1;
    long long min = labs(num[0] + num[N - 1]);
    int first = 0;
    int second = N - 1;
    while (true)
    {

        long long current = (num[first] + num[second]);
        if (current == 0)
        {
            mfirst = first;
            msecond = second;
            break;
        }
        if (current < 0)
        {

            if (min > llabs(current))
            {
                min = llabs(current);
                mfirst = first;
                msecond = second;
            }
            first++;
            if (first == second)
            {
                break;
            }
        }
        if (current > 0)
        {

            if (min > llabs(current))
            {

                min = llabs(current);
                mfirst = first;
                msecond = second;
            }
            second--;
            if (first == second)
            {
                break;
            }
        }
    }

    cout << num[mfirst] << " " << num[msecond];
}