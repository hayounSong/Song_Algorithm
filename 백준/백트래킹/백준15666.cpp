#include <iostream>
#include <algorithm>
using namespace std;

int M, N;
int num[10] = {0};
int ans[10] = {0};

void NM(int start, int count)
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
        int last = -1;

        for (int i = start; i < N; i++)
        {

            if (num[i] != last)
            {
                ans[count] = num[i];
                NM(i, count + 1);
                last = num[i];
            }
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