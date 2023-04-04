#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main()
{

    stack<string> v;
    stack<int> num;
    int ans = 0;
    string s;
    cin >> s;
    int result = 0;
    int temp = 1;
    for (int i = 0; i < s.length(); i++)
    {

        string a = "";
        string r = "";
        if (i > 0)
        {
            r = r + s[i - 1];
        }
        a = a + s[i];

        if (a == "(")
        {
            temp = temp * 2;
            v.push(a);
        }
        if (a == "[")
        {
            temp = temp * 3;
            v.push(a);
        }
        if (a == ")")
        {
            if (v.size() == 0 || v.top() != "(")
            {
                cout << 0;
                return 0;
            }
            else
            {
                if (r == "(")
                {
                    ans = ans + temp;
                    temp = temp / 2;
                    v.pop();
                }
                else
                {
                    temp = temp / 2;
                    v.pop();
                }
            }
        }
        if (a == "]")
        {
            if (v.size() == 0 || v.top() != "[")
            {
                cout << 0;
                return 0;
            }
            else
            {
                if (r == "[")
                {
                    ans = ans + temp;
                    temp = temp / 3;
                    v.pop();
                }
                else
                {
                    temp = temp / 3;
                    v.pop();
                }
            }
        }
    }
    cout << ans;
}