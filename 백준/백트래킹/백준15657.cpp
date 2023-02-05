#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N, M;
int num[9];
int ans[10];

void NM(int min, int count)
{

    if (count == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for (int i = min; i < N; i++)
        {
            ans[count] = num[i];
            NM(i, count + 1);
        }
    }
}

int main()
{

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    sort(num, num + N);
    NM(0, 0);
}