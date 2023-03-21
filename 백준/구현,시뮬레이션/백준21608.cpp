#include <iostream>
#include <vector>
using namespace std;
int chair[22][22];
vector<int> v[404];
int N;
int direcx[4] = {1, 0, -1, 0};
int direcy[4] = {0, 1, 0, -1};
int main()
{
    cin >> N;

    for (int iz = 0; iz < N * N; iz++)
    {
        int student;
        cin >> student;
        for (int i = 0; i < 4; i++)
        {
            int a;
            cin >> a;
            v[student].push_back(a);
        }

        // 1번
        vector<pair<int, int>> fi;
        int min = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (chair[i][j] != 0)
                {
                    continue;
                }
                else
                {
                    int count = 0;
                    for (int a = 0; a < 4; a++)
                    {
                        int cx = direcx[a] + i;
                        int cy = direcy[a] + j;
                        if (cx <= 0 || cy <= 0 || cx > N || cy > N)
                        {
                            continue;
                        }
                        for (int k = 0; k < 4; k++)
                        {
                            if (chair[cx][cy] == v[student][k])
                            {
                                count++;
                            }
                        }
                    }
                    if (count >= min)
                    {

                        if (count > min)
                        {
                            while (!fi.empty())
                            {
                                fi.pop_back();
                            }
                        }
                        min = count;
                        fi.push_back(make_pair(i, j));
                    }
                }
            }
        }

        if (fi.size() == 1)
        {
            chair[fi.back().first][fi.back().second] = student;
            continue;
        }
        // 2번
        vector<pair<int, int>> se;
        min = 0;
        for (int a = 0; a < fi.size(); a++)
        {
            int fx = fi[a].first;
            int fy = fi[a].second;
            int count = 0;
            for (int c = 0; c < 4; c++)
            {
                int cx = direcx[c] + fx;
                int cy = direcy[c] + fy;
                if (cx <= 0 || cy <= 0 || cx > N || cy > N)
                {
                    continue;
                }
                else if (chair[cx][cy] == 0)
                {
                    count++;
                }
            }
            if (count >= min)
            {
                if (count > min)
                {
                    while (!se.empty())
                    {

                        se.pop_back();
                    }
                }
                min = count;
                se.push_back(make_pair(fx, fy));
            }
        }
        if (se.size() == 1)
        {
            chair[se.back().first][se.back().second] = student;
            // cout << chair[2][2];
            continue;
        }
        // cout<<se.size();
        // 3번
        vector<pair<int, int>> th;
        int minx = 9999;
        int miny = 9999;

        for (int a = 0; a < se.size(); a++)
        {
            int tx = se[a].first;
            int ty = se[a].second;
            if (tx < minx)
            {
                minx = tx;
                miny = ty;
                while (!th.empty())
                {

                    th.pop_back();
                }
                th.push_back(make_pair(tx, ty));
            }
            else if (tx == minx)
            {
                if (ty < miny)
                {
                    minx = tx;
                    miny = ty;
                    while (!th.empty())
                    {

                        th.pop_back();
                    }
                    th.push_back(make_pair(tx, ty));
                }
            }
        }
        chair[th.back().first][th.back().second] = student;
        // cout << chair[1][1];
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int count = 0;
            int current = chair[i][j];
            for (int a = 0; a < 4; a++)
            {
                int cx = direcx[a] + i;
                int cy = direcy[a] + j;
                if (cx <= 0 || cy <= 0 || cx > N || cy > N)
                {
                    continue;
                }
                for (int k = 0; k < 4; k++)
                {
                    if (chair[cx][cy] == v[current][k])
                    {
                        count++;
                    }
                }
            }
            if (count == 1)
            {
                ans = ans + 1;
            }
            else if (count == 2)
            {
                ans = ans + 10;
            }
            else if (count == 3)
            {
                ans = ans + 100;
            }
            else if (count == 4)
            {
                ans = ans + 1000;
            }
        }
    }
    cout << ans;
}