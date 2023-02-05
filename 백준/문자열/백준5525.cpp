#include <iostream>
#include <string>
using namespace std;

int main()
{
    long long P;
    cin >> P;

    long long N;
    cin >> N;

    string s;
    cin >> s;
    P = P * 2 + 1;
    long long pcount = 0;
    int boo = 0;
    int ans = 0;
    for (long long i = 0; i < N; i++)
    {

        if (pcount < P && pcount % 2 == 0)
        {
            if (s[i] == 'I')
            {

                pcount++;
                boo = 1;
            }
            else
            {

                pcount = 0;

                boo = 0;
            }
        }
        else if (pcount < P && pcount % 2 == 1)
        {
            if (s[i] == 'O')
            {
                pcount++;
                boo = 1;
            }
            else
            {
                i--;
                pcount = 0;
                boo = 0;
            }
        }
        else if (pcount == P)
        {
            ans++;
            pcount = pcount - 2;
            i--;

            boo = 0;
        }
    }
    cout << ans;
}