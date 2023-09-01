#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
long long num[5001];
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }

    sort(num, num + N);
    long long min = 50000000000;
    int ansi, ansj, ansz;
    for (int i = 1; i < N - 1; i++)
    {
        int j, z;

        j = i - 1;
        z = i + 1;

        while (z < N && j >= 0)
        {

            if (llabs(num[i] + num[j] + num[z]) < min)
            {

                min = llabs(num[i] + num[j] + num[z]);
                ansi = i;
                ansj = j;
                ansz = z;
            }
            if (num[i] + num[j] + num[z] < 0)
            {
                z = z + 1;
                if (z == i)
                {
                    z++;
                }
            }
            else if (num[i] + num[j] + num[z] > 0)
            {
                j = j - 1;
                if (j == i)
                {
                    j--;
                }
            }
            else
            {
                ansi = i;
                ansj = j;
                ansz = z;
                min = 0;
                break;
            }
        }
    }
    int answer[3];
    answer[0] = (ansi);
    answer[1] = (ansj);
    answer[2] = (ansz);
    sort(answer, answer + 3);
    for (int i = 0; i < 3; i++)
    {
        cout << num[answer[i]] << " ";
    }
}