#include <iostream>
using namespace std;

int num[14];
int ans[7];
int visited[14];
int k;

void check(int count, int cindex)
{

    if (count == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";

        return;
    }
    else
    {
        for (int i = cindex; i < k; i++)
        {
            if (visited[num[i]] == 0)
            {

                ans[count] = num[i];
                visited[num[i]] = 1;
                check(count + 1, i + 1);

                visited[num[i]] = 0;
            }
        }
    }
    return;
}

int main()
{

    while (true)
    {
        cin >> k;
        if (k == 0)
        {
            return 0;
        }
        cout << "\n";
        for (int i = 0; i < k; i++)
        {
            cin >> num[i];
        }
        check(0, 0);
    }
}