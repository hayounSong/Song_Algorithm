#include <iostream>
#include <cmath>
using namespace std;

int N;
int stair[10001] = {0};
int maxi[10001] = {0};
int ccount = 0;
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> stair[i];
    }
    maxi[0] = stair[0];
    maxi[1] = stair[1] + stair[0];
    maxi[2] = max(stair[0] + stair[2], stair[1] + stair[2]);
    maxi[2] = max(maxi[1], maxi[2]);
    for (int i = 3; i < N; i++)
    {
        int temp = max(stair[i] + stair[i - 1] + maxi[i - 3], stair[i] + maxi[i - 2]);
        maxi[i] = max(temp, maxi[i - 1]);
    }
    cout << maxi[N - 1];
}