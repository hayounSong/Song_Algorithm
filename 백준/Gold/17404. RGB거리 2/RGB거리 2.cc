#include <iostream>
#include <algorithm>
using namespace std;

int house[1001][3];
int house1[1001][3];
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> house[i][j];
            house1[i][j] = house[i][j];
        }
    }
    int min = 9999999;
    for (int x = 0; x < 3; x++)
    {

        for (int i = N - 2; i >= 1; i--)
        {
            for (int k = 0; k < 3; k++)
            {
                if (i == N - 2)
                {
                    int smin = 999999;
                    for (int j = 0; j < 3; j++)
                    {

                        if (j == x || j == k)
                        {
                            continue;
                        }
                        else
                        {
                            if (house1[i + 1][j] < smin)
                            {
                                smin = house1[i + 1][j];
                            }
                        }
                    }
                    house1[i][k] = smin + house1[i][k];
                }
                else
                {
                    int smin = 999999;
                    for (int j = 0; j < 3; j++)
                    {
                        if (j == k)
                        {
                            continue;
                        }
                        else
                        {
                            if (house1[i + 1][j] < smin)
                            {
                                smin = house1[i + 1][j];
                            }
                        }
                    }
                    house1[i][k] = smin + house1[i][k];
                                }
            }
        }

        int tmin = 999999;
        for (int i = 0; i < 3; i++)
        {

            if (i == x)
            {
                continue;
            }
            else
            {

                if (house1[1][i] < tmin)
                {
                    tmin = house1[1][i];
                }
            }
        }
        if (tmin + house1[0][x] < min)
        {

            min = tmin + house1[0][x];
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 3; j++)
            {

                house1[i][j] = house[i][j];
            }
        }
    }

    cout << min;
}