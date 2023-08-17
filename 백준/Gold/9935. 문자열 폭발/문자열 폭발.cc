#include <iostream>
#include <stack>
#include <deque>
#include <algorithm>
#include <memory.h>
#include <cstring>
using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char s[1000011];
    cin >> s;

    char a[1000011];
    cin >> a;

    deque<char> stack1;
    deque<char> ans;
    int count = 0;
    int alen = strlen(a);
    int slen = strlen(s);

    for (int i = 0; i < slen; i++)
    {
        stack1.push_back(s[i]);
    }

    count = 1;
    int same = 0;
    int scount = 0;
    for (int i = 0; i < slen; i++)
    {
        if (stack1.empty())
        {
            break;
        }
        char temp = stack1.front();
        stack1.pop_front();
        ans.push_back(temp);
        scount++;

        if (ans.back() == a[same])
        {
            same++;
        }
        else
        {
            same = 0;
            if (ans.back() == a[same])
            {
                same++;
            }
        }
        if (same == alen)
        {

            for (int j = 0; j < alen; j++)
            {

                if (!ans.empty())
                {
                    ans.pop_back();
                    scount--;
                }
            }
            if (!ans.empty())
            {
                for (int j = 0; j < alen; j++)
                {
                    if (ans.empty())
                    {
                        break;
                    }
                    stack1.push_front(ans.back());
                    ans.pop_back();
                }
                i = i - alen;
                count = 0;
                same = 0;
            }
        }
    }

    if (ans.empty())
    {
        cout << "FRULA";
    }
    else
    {
        while (!ans.empty())
        {
            cout << ans.front();
            ans.pop_front();
        }
    }
}