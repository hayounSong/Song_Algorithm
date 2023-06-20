#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long S;
long long num[1000001];
int main()
{
    cin >> N >> S;
    num[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> num[i];
    }

    for (int i = 1; i <= N; i++)
    {
        num[i] = num[i] + num[i - 1];
    }

    int min = 999999;
    int start = 1;
    int end = 1;

    while (end <= N)
    {
        int sum = 0;
        sum = num[end] - num[start - 1];

        if (sum >= S)
        {
            if (min > end - start + 1)
            {
                min = end - start + 1;
            }
            start++;
            if (start > end)
            {
                end++;
            }
        }
        if (sum < S)
        {
            end++;
        }
    }
    if (min == 999999)
    {
        min = 0;
    }
    cout << min;
}