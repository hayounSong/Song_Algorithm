#include <iostream>
#include <vector>
using namespace std;

int num[10001] = {0};
int root;
vector<int> v[10001];
int inde = 0;
int cur = 0;
void tree(int start, int end)
{
    if (start >= end)
    {
        return;
    }
    if (start == end - 1)
    {
        cout << num[start] << "\n";
        return;
    }
    int idx = start + 1;
    while (num[start] > num[idx])
    {
        if (idx >= end)
        {
            break;
        }
        idx++;
    }
    tree(start + 1, idx);
    tree(idx, end);

    cout << num[start] << "\n";
}
int main()
{
    int temp;

    while (cin >> temp)
    {
        num[inde] = temp;
        inde++;
    }
    tree(0, inde);
}