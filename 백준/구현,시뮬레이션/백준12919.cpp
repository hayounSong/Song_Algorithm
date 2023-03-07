#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string temp = "";
void check(string s, string t)
{

    if (s == t)
    {
        cout << 1;
        exit(0);
    }
    if (s.size() >= t.size())
    {

        return;
    }

    if (t[t.size() - 1] == 'A')
    {
        temp = t;
        temp.erase(temp.size() - 1);
        check(s, temp);
    }
    if (t[0] == 'B')
    {
        temp = t;
        temp.erase(temp.begin());
        reverse(temp.begin(), temp.end());
        check(s, temp);
    }
}

string s, t;
int main()

{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s >> t;

    check(s, t);
    cout << 0;
}