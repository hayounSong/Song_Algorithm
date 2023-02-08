#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
map<string, pair<string, string>> m;

void preorder(string center)
{
    string dots = ".";
    if (center != dots)
    {
        cout
            << center;
        preorder(m[center].first);
        preorder(m[center].second);
    }
}

void inorder(string center)
{
    string dots = ".";
    if (center != dots)
    {
        inorder(m[center].first);
        cout
            << center;

        inorder(m[center].second);
    }
}
void postorder(string center)
{
    string dots = ".";
    if (center != dots)
    {
        postorder(m[center].first);

        postorder(m[center].second);
        cout
            << center;
    }
}
int main()
{

    int N;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string center, left, right;

        cin >> center >> left >> right;

        m[center] = {left, right};
    }

    preorder("A");
    cout << "\n";
    inorder("A");
    cout << "\n";
    postorder("A");
}