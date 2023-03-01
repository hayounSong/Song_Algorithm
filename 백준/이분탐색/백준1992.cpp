#include <iostream>
#include <string>
using namespace std;

int N;
int num[64][64];

string quard(int startx, int starty, int size)
{
    if (size == 1)
    {
        string ans = to_string(num[startx][starty]);
        return ans;
    }
    string ans = "";
    int start = num[startx][starty];
    int check = 1;
    for (int i = startx; i < startx + size; i++)
    {
        for (int j = starty; j < starty + size; j++)
        {
            if (num[i][j] != start)
            {
                check = 0;
                break;
            }
        }
    }

    if (check == 1)
    {

        ans = ans + to_string(start);
    }
    else
    {
        ans = "(";
        ans = ans + quard(startx, starty, size / 2);
        ans = ans + quard(startx, starty + size / 2, size / 2);
        ans = ans + quard(startx + size / 2, starty, size / 2);
        ans = ans + quard(startx + size / 2, starty + size / 2, size / 2);
        ans = ans + ")";
    }

    return ans;
}
int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string c;
        cin >> c;
        for (int j = 0; j < N; j++)
        {
            num[i][j] = int(c[j]) - '0';
        }
    }

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << num[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << '(';
    cout << quard(0, 0, N);
    // cout << ')';
}