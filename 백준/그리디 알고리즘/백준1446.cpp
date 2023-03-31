#include <iostream>
#include <vector>
using namespace std;
int ball[500001];
int road[10001] = {0};
int N, D;
vector<pair<pair<int, int>, int>> v;
int main()
{
    cin >> N;
    cin >> D;

    for (int i = 0; i <= D; i++)
    {
        road[i] = i;
    }

    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (road[a] + c < road[b])
        {
            road[b] = road[a] + c;
            v.push_back({{a, b}, c});
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        int a, b, c;
    }
    int check = 0;
    for (int i = 0; i <= D; i++)
    {
        int start = 0;
        start = road[i];
        if (road[check] + i - check < road[i])
        {

            road[i] = road[check] + i - check;
        }
        if (start < i)
        {

            check = i;
            // cout << check << " ";
        }
    }
    cout << road[70];
}