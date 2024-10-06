#include <iostream>
#include <vector>
using namespace std;

int aList[101] = {0};
int bList[101] = {0};
int A, B;
vector<int> ans;
vector<int> indeList;
int main()
{
    cin >> A;

    for (int i = 0; i < A; i++)
    {
        cin >> aList[i];
    }

    cin >> B;
    for (int i = 0; i < B; i++)
    {
        cin >> bList[i];
    }
    int ainde = 0;
    int binde = 0;
    int maxi = 0;
    vector<int> ans;
    while (ainde < A && binde < B)
    {
        int che = 0;
        int ii = 0;
        int jj = 0;
        for (int i = ainde; i < A; i++)
        {
            for (int j = binde; j < B; j++)
            {

                if (aList[i] == bList[j])
                {
                    if (aList[i] > maxi)
                    {
                        maxi = aList[i];
                        // cout << maxi;
                        ii = i;
                        jj = j;
                        che = 1;
                    }
                }
            }
        }
        if (che == 1)
        {
            ainde = ii + 1;
            binde = jj + 1;
            ans.push_back(maxi);
            maxi = 0;
        }
        if (che == 0)
        {
            break;
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}