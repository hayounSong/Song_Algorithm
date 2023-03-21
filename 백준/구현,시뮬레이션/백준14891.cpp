#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int num[5][3] = {0}; // start center end
int wheel[5][9] = {0};

int wheelwhere[5] = {0, 0, 0, 0, 0};

void gowheel(int m)
{
    if (wheelwhere[m] == 1)
    {
        for (int i = 0; i < 3; i++)
        {
            num[m][i]--;
            if (num[m][i] <= 0)
            {
                num[m][i] = num[m][i] + 8;
            }
        }
    }
    else if (wheelwhere[m] == -1)
    {
        for (int i = 0; i < 3; i++)
        {
            num[m][i]++;
            if (num[m][i] > 8)
            {
                num[m][i] = num[m][i] - 8;
            }
        }
    }
    else
    {
        return;
    }
}

int main()
{
    for (int i = 1; i <= 4; i++)
    {
        string s;

        cin >> s;
        for (int j = 1; j <= 8; j++)
        {

            wheel[i][j] = s[j - 1] - '0';
        }
    }
    for (int i = 1; i <= 4; i++)
    {
        num[i][0] = 7; // start
        num[i][1] = 1; // center
        num[i][2] = 3; // end
    }

    int count = 0;
    cin >> count;

    for (int countc = 0; countc < count; countc++)
    {
        int what, where;
        cin >> what >> where;

        wheelwhere[what] = where;

        if (what == 1)
        {
            if (wheel[1][num[1][2]] != wheel[2][num[2][0]])
            {

                wheelwhere[2] = where * -1;
            }
            if (wheel[2][num[2][2]] != wheel[3][num[3][0]])
            {

                wheelwhere[3] = wheelwhere[2] * -1;
            }
            if (wheel[3][num[3][2]] != wheel[4][num[4][0]])
            {

                wheelwhere[4] = wheelwhere[3] * -1;
            }
        }
        if (what == 2)
        {
            if (wheel[1][num[1][2]] != wheel[2][num[2][0]])
            {

                wheelwhere[1] = wheelwhere[2] * -1;
            }
            if (wheel[2][num[2][2]] != wheel[3][num[3][0]])
            {

                wheelwhere[3] = wheelwhere[2] * -1;
            }
            if (wheel[3][num[3][2]] != wheel[4][num[4][0]])
            {

                wheelwhere[4] = wheelwhere[3] * -1;
            }
        }
        if (what == 3)
        {
            if (wheel[2][num[2][2]] != wheel[3][num[3][0]])
            {

                wheelwhere[2] = wheelwhere[3] * -1;
            }
            if (wheel[1][num[1][2]] != wheel[2][num[2][0]])
            {

                wheelwhere[1] = wheelwhere[2] * -1;
            }
            if (wheel[3][num[3][2]] != wheel[4][num[4][0]])
            {

                wheelwhere[4] = wheelwhere[3] * -1;
            }
        }
        if (what == 4)
        {
            if (wheel[3][num[3][2]] != wheel[4][num[4][0]])
            {

                wheelwhere[3] = wheelwhere[4] * -1;
            }
            if (wheel[2][num[2][2]] != wheel[3][num[3][0]])
            {

                wheelwhere[2] = wheelwhere[3] * -1;
            }
            if (wheel[1][num[1][2]] != wheel[2][num[2][0]])
            {

                wheelwhere[1] = wheelwhere[2] * -1;
            }
        }

        for (int i = 1; i <= 4; i++)
        {
            gowheel(i);
        }
        for (int i = 0; i <= 5; i++)
        {
            wheelwhere[i] = 0;
        }
    }
    int ans = 0;

    if (wheel[1][num[1][1]] == 1)
    {
        ans = ans + 1;
    }
    if (wheel[2][num[2][1]] == 1)
    {
        ans = ans + 2;
    }
    if (wheel[3][num[3][1]] == 1)
    {
        ans = ans + 4;
    }
    if (wheel[4][num[4][1]] == 1)
    {
        ans = ans + 8;
    }
    cout << ans;
}
