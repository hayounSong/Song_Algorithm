#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> v;
    vector<int> ans;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
        ans.push_back(a);
    }
    int answer = -1;
    int check = 0;
    while (next_permutation(v.begin(), v.end()))
    {
        for (int i = 0; i < N; i++)
        {
            cout << v[i] << " ";
        }
        check = 1;
        break;
    }
    if (check == 0)
    {
        cout << -1;
    }
}
