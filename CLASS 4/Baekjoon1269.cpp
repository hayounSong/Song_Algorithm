#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> A;
    vector<int> B;
    map<int, int> re;
    vector<int> Result;
    int n, m;
    int count;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
        re[a]++;
    }
    for (int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        B.push_back(b);
    }
    int ans;
    for (int i = 0; i < m; i++)
    {
        if (re[B[i]] > 0)
        {
            count++;
        }
    }
    // set_difference(A.begin(), A.end(), B.begin(), B.end(), Result.begin());

    cout << n + m - 2 * count;
}