#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N;
vector<string> v;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    int maxi = 0;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }

    int ans1 = -1;
    int ans2 = -1;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (v[i] == v[j])
            {
                continue;
            }

            int slen = min(v[i].length(), v[j].length());

            int coun = 0;
            for (int z = 0; z < slen; z++)
            {
                if (v[i][z] == v[j][z])
                {
                    coun++;
                }
                else
                {
                    if (coun > maxi)
                    {
                        maxi = coun;
                        ans1 = i;
                        ans2 = j;
                    }
                    break;
                }
            }
            if (coun > maxi)
            {

                maxi = coun;
                ans1 = i;
                ans2 = j;
            }
        }
    }
    cout << v[ans1] << "\n";
    cout << v[ans2];
}