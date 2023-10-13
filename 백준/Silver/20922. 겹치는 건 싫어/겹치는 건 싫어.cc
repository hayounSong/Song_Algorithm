#include <iostream>
using namespace std;

int num[200001] = {0};
int coun[100001] = {0};
int N, K;
int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    int maxrange = 0;
    int range = 0;
    int j = 0;
    for (int i = 0; i < N; i++)
    {
        if (coun[num[i]] + 1 <= K)
        {
            coun[num[i]]++;
            range++;
            if (range > maxrange)
            {
                maxrange = range;
            }
        }
        else
        {
            range--;
            coun[num[j]]--;
            i = i - 1;
            j++;
        }
    }
    cout << maxrange;
}