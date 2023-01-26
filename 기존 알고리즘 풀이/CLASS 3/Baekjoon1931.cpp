#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> list;

    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> end >> start;
        list.push_back(make_pair(start, end));
    }
    sort(list.begin(), list.end());

    int time = list[0].first;
    int ans = 1;
    int j = 0;
    for (int i = 1; i <= n; i++)
    {
        if (list[i].second >= time)
        {
            ans++;
            time = list[i].first;
        }
    }
    cout << ans;
}