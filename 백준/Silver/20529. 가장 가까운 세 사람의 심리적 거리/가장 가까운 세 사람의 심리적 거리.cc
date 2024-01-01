#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int T;
int N;
string s[100001];
vector<string> v;
int maxi = 99999999;
void backtrack(int current, int lock)
{
    if (current == 3)
    {
        int sum = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = i + 1; j < 3; j++)
            {
                // cout << s[j] << " ";
                for (int z = 0; z < 4; z++)
                {
                    if (v[i][z] != v[j][z])
                    {
                        sum++;
                    }
                }
            }
        }
        if (sum < maxi)
        {
            maxi = sum;
        }
        return;
    }
    else
    {
        for (int i = lock + 1; i < N; i++)
        {
            v.push_back(s[i]);
            // cout << s[i] << " ";
            backtrack(current + 1, i);
            v.pop_back();
            // cout << v.size();
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        cin >> N;
        maxi = 9999999;

        for (int i = 0; i < N; i++)
        {
            cin >> s[i];
        }
        if (N >= 33)
        {
            cout << 0 << "\n";
            continue;
        }
        backtrack(0, -1);
        cout << maxi << "\n";
    }
}