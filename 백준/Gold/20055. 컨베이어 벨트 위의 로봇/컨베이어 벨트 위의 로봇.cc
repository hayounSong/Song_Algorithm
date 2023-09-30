#include <iostream>
using namespace std;
int container[202] = {0};
int robot[202] = {0};
int N, K;

int main()
{

    cin >> N >> K;
    int endr = N - 1;
    int start = 0;
    for (int i = 0; i < 2 * N; i++)
    {
        cin >> container[i];
    }
    int stage = 0;
    while (true)
    {

        int count = 0;
        for (int i = 0; i < 2 * N; i++)
        {
            if (container[i] <= 0)
            {
                count++;
            }
        }
        if (count >= K)
        {
            break;
        }

        start = start - 1;
        if (start < 0)
        {
            start = start + 2 * N;
        }
        endr = endr - 1;
        if (endr < 0)
        {
            endr = endr + 2 * N;
        }

        robot[endr] = 0;

        for (int i = 1; i < 2 * N; i++)
        {
            int a = endr - i;
            if (a < 0)
            {
                a = a + 2 * N;
            }
            int aplus = a + 1;
            if (aplus >= 2 * N)
            {
                aplus = aplus - 2 * N;
            }
            if (robot[aplus] == 0 && container[aplus] > 0 && robot[a] > 0)
            {
                robot[aplus]++;
                robot[a] = 0;
                container[aplus]--;
            }
        }
        robot[endr] = 0;

        if (container[start] > 0 && robot[start] == 0)
        {
            robot[start]++;
            container[start]--;
        }
        stage++;
    }

    cout << stage;
}