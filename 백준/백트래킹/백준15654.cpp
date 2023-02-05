#include <iostream>
using namespace std;
#include <algorithm>
int N, M;
int num[10];
int ans[10];
int visited[10] = {0};
void NM(int count)
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
        for (int i = 0; i < N; i++)
        {
            if (visited[i] == 0)
            {
                ans[count] = num[i];
                visited[i] = 1;
                NM(count + 1);
                visited[i] = 0;
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
    NM(0);
}