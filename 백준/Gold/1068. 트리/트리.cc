#include <iostream>
#include <vector>
using namespace std;

vector<int> child[501];
vector<int> parent[501];
int alive[501] = {0};
int how[501] = {0};

int N;

void deleteNode(int now)
{
    if (child[now].size() == 0)
    {
        alive[now] = 1;
        for (int i = 0; i < parent[now].size(); i++)
        {
            how[parent[now][i]]--;
        }
    }
    else
    {
        for (int i = 0; i < child[now].size(); i++)
        {
            deleteNode(child[now][i]);
        }
        for (int i = 0; i < parent[now].size(); i++)
        {
            how[parent[now][i]]--;
        }
        alive[now] = 1;
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        if (a == -1)
        {
            continue;
        }
        else
        {
            child[a].push_back(i);
            parent[i].push_back(a);
            how[a]++;
        }
    }
    int del;
    cin >> del;
    deleteNode(del);
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (how[i] == 0 && alive[i] == 0)
        {
            ans++;
        }
    }
    cout << ans;
}