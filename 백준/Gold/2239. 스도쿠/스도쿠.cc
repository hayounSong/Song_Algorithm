#include <iostream>
#include <vector>
using namespace std;

int zcount = 0;
int num[10][10] = {0};

vector<pair<int, int>> zeronum;

int sdoku(int startx, int starty, int cnum)
{
    if (cnum == zcount)
    {
        return 1;
    }
    else
    {
        int checksum = 0;
        int wherex;
        int wherey;

        if (startx % 3 == 0)
        {
            wherex = 1;
        }
        else if (startx % 3 == 1)
        {
            wherex = 2;
        }
        else
        {
            wherex = 3;
        }

        if (starty % 3 == 0)
        {
            wherey = 1;
        }
        else if (starty % 3 == 1)
        {
            wherey = 2;
        }
        else
        {
            wherey = 3;
        }
        for (int i = 1; i <= 9; i++)
        {

            int entireBreak = 0;

            for (int j = 0; j < 9; j++)
            {
                if (num[startx][j] == i)
                {
                    entireBreak = 1;
                    break;
                }
                if (num[j][starty] == i)
                {
                    entireBreak = 1;
                    break;
                }
            }
            if (wherex == 1)
            {
                if (wherey == 1)
                {
                    for (int c = 0; c < 3; c++)
                    {
                        for (int d = 0; d < 3; d++)
                        {
                            if (num[startx + c][starty + d] == i)
                            {
                                entireBreak = 1;
                            }
                        }
                    }
                }
                if (wherey == 2)
                {
                    for (int c = 0; c < 3; c++)
                    {
                        for (int d = -1; d <= 1; d++)
                        {
                            if (num[startx + c][starty + d] == i)
                            {
                                entireBreak = 1;
                            }
                        }
                    }
                }
                if (wherey == 3)
                {
                    for (int c = 0; c < 3; c++)
                    {
                        for (int d = -2; d <= 0; d++)
                        {
                            if (num[startx + c][starty + d] == i)
                            {
                                entireBreak = 1;
                            }
                        }
                    }
                }
            }

            if (wherex == 2)
            {
                if (wherey == 1)
                {
                    for (int c = -1; c <= 1; c++)
                    {
                        for (int d = 0; d < 3; d++)
                        {
                            if (num[startx + c][starty + d] == i)
                            {
                                entireBreak = 1;
                            }
                        }
                    }
                }
                if (wherey == 2)
                {
                    for (int c = -1; c <= 1; c++)
                    {
                        for (int d = -1; d <= 1; d++)
                        {
                            if (num[startx + c][starty + d] == i)
                            {
                                entireBreak = 1;
                            }
                        }
                    }
                }
                if (wherey == 3)
                {
                    for (int c = -1; c <= 1; c++)
                    {
                        for (int d = -2; d <= 0; d++)
                        {
                            if (num[startx + c][starty + d] == i)
                            {
                                entireBreak = 1;
                            }
                        }
                    }
                }
            }

            if (wherex == 3)
            {
                if (wherey == 1)
                {
                    for (int c = -2; c <= 0; c++)
                    {
                        for (int d = 0; d < 3; d++)
                        {
                            if (num[startx + c][starty + d] == i)
                            {
                                entireBreak = 1;
                            }
                        }
                    }
                }
                if (wherey == 2)
                {
                    for (int c = -2; c <= 0; c++)
                    {
                        for (int d = -1; d <= 1; d++)
                        {
                            if (num[startx + c][starty + d] == i)
                            {
                                entireBreak = 1;
                            }
                        }
                    }
                }
                if (wherey == 3)
                {
                    for (int c = -2; c <= 0; c++)
                    {
                        for (int d = -2; d <= 0; d++)
                        {
                            if (num[startx + c][starty + d] == i)
                            {
                                entireBreak = 1;
                            }
                        }
                    }
                }
            }

            if (entireBreak == 0)
            {

                num[startx][starty] = i;

                if (cnum + 1 == zcount)
                {

                    return 1;
                }
                else
                {

                    int ans = sdoku(zeronum[cnum + 1].first, zeronum[cnum + 1].second, cnum + 1);
                    if (ans == 1)
                    {

                        return 1;
                    }
                    else
                    {

                        num[startx][starty] = 0;
                        continue;
                    }
                }
            }
        }

        return 0;
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        char c[10];
        cin >> c;

        for (int j = 0; j < 9; j++)
        {
            num[i][j] = c[j] - '0';
            if (num[i][j] == 0)
            {
                zcount++;
                zeronum.push_back({i, j});
            }
        }
    }

    sdoku(zeronum[0].first, zeronum[0].second, 0);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << num[i][j];
        }
        cout << endl;
    }
}