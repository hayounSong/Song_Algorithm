#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int K;
int tree;
int root;
int num[3001] = {0};
vector<int> v[3001];
vector<int> f[11];
int sumi(int where, int floor)
{
    int current = num[where];
    if (floor <= -1)
    {
        return current;
    }
    int cf = pow(2, floor);
    int left = sumi(where - cf, floor - 1);
    int right = sumi(where + cf, floor - 1);
    f[floor + 1].push_back(left);
    f[floor + 1].push_back(right);
    v[current].push_back(left);
    v[current].push_back(right);
    return current;
}

int main()
{
    cin >> K;
    tree = pow(2, K) - 1;
    for (int i = 0; i < tree; i++)
    {
        cin >> num[i];
    }
    root = tree / 2;
    f[K].push_back(num[root]);
    sumi(root, K - 2);

    for (int i = K; i >= 1; i--)
    {
        for (int j = 0; j < f[i].size(); j++)
        {
            cout << f[i][j] << " ";
        }
        cout << "\n";
    }
}