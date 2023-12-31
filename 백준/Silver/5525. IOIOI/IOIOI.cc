#include <iostream>
#include <string>
using namespace std;
int N;
int M;
int main()
{
    cin >> N >> M;

    string s;
    cin >> s;
    int ans = 0;
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'O')
        {
            continue;
        }
        else
        {
            if (s[i + 1] == 'O' && s[i + 2] == 'I')
            {
                count++;
                if (count == N)
                {
                    ans++;
                    count--;
                }
                i = i + 1;
            }
            else
            {
                count = 0;
            }
        }
    }
    cout << ans;
}