#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int brokencount;
int breaked[10] = {0};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    cin >> brokencount;

    for (int i = 0; i < brokencount; i++)
    {
        int a;
        cin >> a;
        breaked[a] = 1;
    }

    int testN = N;
    int tencount = 0;

    while (testN >= 1)
    {

        testN = testN / 10;
        tencount++;
    }

    int num = 100;

    if (N == 100)
    {
        cout << 0;
        return 0;
    }
    if (N == 0)
    {
        tencount = 1;
    }
    int ans = tencount;
    int ccount = 0;
    int minc = 999999;
    while (true)
    {

        if (N + ccount < 1000000)
        {
            if (tencount + ccount > abs(N - 100))
            {
                minc = min(minc, abs(N - 100));
                break;
            }
            int current = N + ccount;

            string scurrent = to_string(current);
            int check = 0;
            for (int i = 0; i < scurrent.length(); i++)
            {
                if (breaked[int(scurrent[i]) - '0'] == 1)
                {
                    check = 1;
                    break;
                }
            }

            if (check == 0)
            {
                int newten = 0;
                int newtest = N + ccount;
                if (newtest == 0)
                {
                    newten = 1;
                }
                while (newtest >= 1)
                {
                    newtest = newtest / 10;
                    newten++;
                }

                minc = min(minc, newten + ccount);
            }
        }
        if (N - ccount >= 0)
        {
            int current = N - ccount;
            string scurrent = to_string(current);
            int check = 0;
            for (int i = 0; i < scurrent.length(); i++)
            {
                if (breaked[int(scurrent[i]) - '0'] == 1)
                {
                    check = 1;
                    break;
                }
            }
            if (check == 0)
            {
                int newten = 0;
                int newtest = N - ccount;
                if (newtest == 0)
                {
                    newten = 1;
                }
                while (newtest >= 1)
                {
                    newtest = newtest / 10;
                    newten++;
                }
                minc = min(minc, newten + ccount);
            }
        }
        if (N + ccount > 500000 && N - ccount < 0)
        {
            break;
        }

        ccount++;
    }
    cout << minc;
}