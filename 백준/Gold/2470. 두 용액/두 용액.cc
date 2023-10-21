#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

// long num[100001] = {0};
int main()
{
    vector<long> v;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        long a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int i = 0;
    int j = v.size() - 1;

    long sum = labs(v[i] + v[j]);
    long a1 = i;
    long b1 = j;
    while (true)
    {
        if (i == j)
        {
            break;
        }
        long a = v[i] + v[j];
        if (labs(a) < labs(sum))
        {
            // cout << labs(a) << " ";
            a1 = i;
            b1 = j;
            sum = abs(a);
        }

        if (a > 0)
        {
            j--;
        }
        else if (a == 0)
        {
            a1 = i;
            b1 = j;
            sum = a;
            break;
        }
        else
        {
            i++;
        }
    }
    cout << v[a1] << " " << v[b1];
}
