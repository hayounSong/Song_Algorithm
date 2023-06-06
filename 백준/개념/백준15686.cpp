#include <iostream>
#include <vector>
using namespace std;
int N, M;
int vil[51][51] = {0};
vector<int> ans;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
int min1 = 999999;
void check1(int count, int last)
{

    if (count == M)
    {
        int imsi = 0;

        for (int i = 0; i < house.size(); i++)
        {
            int housesize = 999999;
            for (int j = 0; j < ans.size(); j++)
            {
                if ((abs(chicken[ans[j]].first - house[i].first) + abs(chicken[ans[j]].second - house[i].second)) < housesize)
                {
                    housesize = abs(chicken[ans[j]].first - house[i].first) + abs(chicken[ans[j]].second - house[i].second);
                }
            }
            imsi = imsi + housesize;
        }
        if (imsi < min1)
        {

            min1 = imsi;
        }
    }
    else
    {

        for (int i = last + 1; i < chicken.size(); i++)
        {
            ans.push_back(i);
            check1(count + 1, i);
            ans.pop_back();
        }
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> vil[i][j];
            if (vil[i][j] == 1)
            {
                house.push_back({i, j});
            }
            if (vil[i][j] == 2)
            {
                chicken.push_back({i, j});
            }
        }
    }

    check1(0, -1);
    cout << min1;
}