#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int T;

    cin >> T;

    for (int tt = 0; tt < T; tt++)
    {
        char s[10001];
        cin >> s;

        int K;
        cin >> K;
        int fmin = 999999;
        int dmax = -1;
        int value[26] = {0};
        for (int z = 0; z < 26; z++)
        {
            value[z] = 0;
        }
        for (int z = 0; z < strlen(s); z++)
        {
            value[s[z] - 96]++;
        }
        for (int i = 0; i < strlen(s); i++)
        {
            if (value[s[i] - 96] < K)
            {
                continue;
            }
            else
            {
                int count = 0;
                for (int j = i; j < strlen(s); j++)
                {
                    if (s[i] == s[j])
                    {
                        count++;
                    }
                    if (count == K)
                    {
                        fmin = min(fmin, j - i + 1);
                        dmax = max(dmax, j - i + 1);
                        break;
                    }
                }
            }
        }

        if (fmin == 999999)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << fmin << " " << dmax << "\n";
        }
    }
}