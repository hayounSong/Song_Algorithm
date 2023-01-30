#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int ans = 0;
void check(string c)
{
    for (int j = 0; j < c.size(); j++)
    {
        int start = c[j];
        int con = 1;
        for (int k = j + 1; k < c.size(); k++)
        {
            if (start == c[k])
            {
                if (con == 0)
                {
                    return;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                con = 0;
            }
        }
    }
    ans = ans + 1;
}

int main()
{

    int N;
    cin >> N;
    string c;

    for (int i = 0; i < N; i++)
    {
        cin >> c;
        check(c);
    }

    cout << ans;
}