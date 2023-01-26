#include <iostream>
using namespace std;

int main()
{

    int N;
    cin >> N;

    int sum[N][3];

    for (int i = 0; i < N; i++)
    {
        cin >> sum[i][0];
        sum[i][1] = 1;
        sum[i][2] = 0;
        for (int a = 0; a < 3; a++)
        {
            int d;
            cin >> d;
            sum[i][1] *= d;
            sum[i][2] += d;
        }
    }

    for (int i = 1; i < N; i++)
    {
        for (int a = 0; a < N - i; a++)
        {
            if (sum[a][1] > sum[a + 1][1])
            {
                int temp = sum[a][0];
                sum[a][0] = sum[a + 1][0];
                sum[a + 1][0] = temp;

                temp = sum[a][1];
                sum[a][1] = sum[a + 1][1];
                sum[a + 1][1] = temp;

                temp = sum[a][2];
                sum[a][2] = sum[a + 1][2];
                sum[a + 1][2] = temp;
            }
            if (sum[a][1] == sum[a + 1][1])
            {

                if (sum[a][2] > sum[a + 1][2])
                {
                    int temp = sum[a][0];
                    sum[a][0] = sum[a + 1][0];
                    sum[a + 1][0] = temp;

                    temp = sum[a][1];
                    sum[a][1] = sum[a + 1][1];
                    sum[a + 1][1] = temp;

                    temp = sum[a][2];
                    sum[a][2] = sum[a + 1][2];
                    sum[a + 1][2] = temp;
                }
            }
            if (sum[a][1] == sum[a + 1][1] && sum[a][2] == sum[a + 1][2])
            {
                if (sum[a][0] > sum[a + 1][0])
                {
                    int temp = sum[a][0];
                    sum[a][0] = sum[a + 1][0];
                    sum[a + 1][0] = temp;

                    temp = sum[a][1];
                    sum[a][1] = sum[a + 1][1];
                    sum[a + 1][1] = temp;

                    temp = sum[a][2];
                    sum[a][2] = sum[a + 1][2];
                    sum[a + 1][2] = temp;
                }
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        cout << sum[i][0] << " ";
    }
}
