#include <iostream>
#include <string>
using namespace std;

int direcx[4] = {-1, 0, 1, 0};
int direcy[4] = {0, 1, 0, -1};

int main()
{
    int T;
    cin >> T;

    for (int testcase = 0; testcase < T; testcase++)
    {
        int cd = 0;
        string s;
        cin >> s;
        int minx = 0;
        int maxx = 0;
        int miny = 0;
        int maxy1 = 0;
        int cx = 0;
        int cy = 0;
        for (int i = 0; i < s.length(); i++)
        {

            if (s[i] == 'F')
            {
                cx = cx + direcx[cd];
                cy = cy + direcy[cd];
                if (minx > cx)
                {
                    minx = cx;
                }
                if (maxx < cx)
                {
                    maxx = cx;
                }
                if (miny > cy)
                {

                    miny = cy;
                }
                if (maxy1 < cy)
                {

                    maxy1 = cy;
                }
            }
            else if (s[i] == 'B')
            {
                cx = cx - direcx[cd];
                cy = cy - direcy[cd];
                if (minx > cx)
                {
                    minx = cx;
                }
                if (maxx < cx)
                {
                    maxx = cx;
                }
                if (miny > cy)
                {
                    miny = cy;
                }
                if (maxy1 < cy)
                {
                    maxy1 = cy;
                }
            }
            else if (s[i] == 'L')
            {
                cd--;
                if (cd == -1)
                {
                    cd = 3;
                }
            }
            else if (s[i] == 'R')
            {
                cd++;
                if (cd == 4)
                {
                    cd = 0;
                }
            }
        }
        // cout << maxx << minx << maxy1 << miny;
        cout << abs(maxx - minx) * abs(maxy1 - miny) << endl;
    }
}