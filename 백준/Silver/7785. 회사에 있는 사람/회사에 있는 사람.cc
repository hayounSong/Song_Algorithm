#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    set<string, greater<string>> s;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string a, b;
        cin >> a >> b;

        if (b == "enter")
        {
            s.insert(a);
        }
        else
        {
            s.erase(a);
        }
    }
    // sort(s.begin(), s.end());

    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << "\n";
    }
}