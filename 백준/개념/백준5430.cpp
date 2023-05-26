#include <iostream>

#include <algorithm>
#include <string>
#include <sstream>
#include <deque>
using namespace std;
int main()
{
    deque<int> v;
    int T;

    cin >> T;

    for (int t = 0; t < T; t++)
    {
        v.clear();
        string s;
        cin >> s;
        int h;
        cin >> h;
        string a;
        cin >> a;

        string imsi = "";
        for (int i = 0; i < a.size(); i++)
        {
            if (isdigit(a[i]))
            {
                imsi = imsi + a[i];
            }
            else
            {
                if (imsi.size() > 0)
                {
                    int current = stoi(imsi);
                    // cout << current;
                    v.push_back(current);
                    imsi = "";
                }
            }
        }
        int e = 0;
        int rcount = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'R' && v.size() > 0)
            {
                rcount++;
            }
            if (s[i] == 'D')
            {
                if (v.size() == 0)
                {
                    e = 1;
                    cout << "error"
                         << "\n";
                    break;
                }
                if (rcount % 2 == 0)
                {
                    v.pop_front();
                }
                else
                {
                    v.pop_back();
                }
            }
        }

        if (rcount % 2 != 0)
        {
            reverse(v.begin(), v.end());
        }
        if (e == 1)
        {
            continue;
        }
        else
        {
            cout << '[';
            if (v.size() > 0)
            {
                for (int i = 0; i < v.size() - 1; i++)
                {
                    cout << v[i] << ',';
                }
                cout << v[v.size() - 1];
            }
            cout << ']' << "\n";
        }
    }
}