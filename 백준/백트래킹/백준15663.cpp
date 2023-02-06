#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
int num[9] = {0};
int ans[9] = {0};
int visited[9] = {0};

vector<string> str;
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
        int last = 0;
        for (int i = 0; i < N; i++)
        {
            if (visited[i] == 0)
            {
                if (last != num[i])
                {

                    visited[i] = 1;
                    ans[count] = num[i];
                    last = num[i];
                    NM(count + 1);
                    visited[i] = 0;
                }
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    sort(num, num + N);

    NM(0);
}