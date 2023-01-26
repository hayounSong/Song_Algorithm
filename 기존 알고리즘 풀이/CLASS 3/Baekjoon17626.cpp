#include <iostream>
#include <math.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int num = sqrt(n);

    int count = 0;

    n = n - num * num;
    count++;
    int checked[num];
    for (int i = 0; i < num; i++)
    {
        checked[i] = 0;
    }
    if (n == 0)
    {
        cout << count;
    }
    else
    {
        int max = num;

        while (n > 0)
        {
            for (int i = max; i >= 1; i--)
            {
                if (n - i * i >= 0)
                {

                    if (checked[i] != 1)
                    {
                        count++;

                        n = n - i * i;
                        max = i;
                        checked[i] = 1;
                    }
                    else
                    {
                        n = n - i * i;
                        max = i;
                    }
                }
                else
                {
                    continue;
                }
            }
        }
        cout << count;
    }
}