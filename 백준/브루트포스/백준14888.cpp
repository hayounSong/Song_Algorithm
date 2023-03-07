#include <iostream>
#include <algorithm>
using namespace std;
int N;
int num[12];
int met[4];

long long summax(int currentnum, int result)
{
    long long max = -1000000000;

    if (currentnum == N)
    {
        return result;
    }
    long long plus, minus, multi, divide;
    if (met[0] > 0)
    {
        met[0] = met[0] - 1;
        plus = summax(currentnum + 1, result + num[currentnum]);
        if (plus > max)
        {
            max = plus;
        }
        met[0] = met[0] + 1;
    }
    if (met[1] > 0)
    {
        met[1] = met[1] - 1;
        minus = summax(currentnum + 1, result - num[currentnum]);
        if (minus > max)
        {
            max = minus;
        }
        met[1] = met[1] + 1;
    }
    if (met[2] > 0)
    {
        met[2] = met[2] - 1;
        multi = summax(currentnum + 1, result * num[currentnum]);
        if (multi > max)
        {
            max = multi;
        }
        met[2] = met[2] + 1;
    }
    if (met[3] > 0)
    {
        met[3] = met[3] - 1;
        divide = summax(currentnum + 1, result / num[currentnum]);
        if (divide > max)
        {
            max = divide;
        }
        met[3] = met[3] + 1;
    }

    return max;
}

long long summin(int currentnum, int result)
{
    long long min = 1000000000;

    if (currentnum == N)
    {
        return result;
    }
    long long plus, minus, multi, divide;

    if (met[0] > 0)
    {

        met[0] = met[0] - 1;
        plus = summin(currentnum + 1, result + num[currentnum]);
        if (plus < min)
        {
            min = plus;
        }
        met[0] = met[0] + 1;
    }
    if (met[1] > 0)
    {
        met[1] = met[1] - 1;
        minus = summin(currentnum + 1, result - num[currentnum]);
        if (minus < min)
        {
            min = minus;
        }
        met[1] = met[1] + 1;
    }
    if (met[2] > 0)
    {
        met[2] = met[2] - 1;
        multi = summin(currentnum + 1, result * num[currentnum]);
        if (multi < min)
        {
            min = multi;
        }
        met[2] = met[2] + 1;
    }
    if (met[3] > 0)
    {
        met[3] = met[3] - 1;
        divide = summin(currentnum + 1, result / num[currentnum]);
        if (divide < min)
        {
            min = divide;
        }
        met[3] = met[3] + 1;
    }

    return min;
}
int main()
{

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }

    for (int i = 0; i < 4; i++)
    {
        cin >> met[i];
    }

    cout << summax(1, num[0]);
    cout << "\n";
    cout << summin(1, num[0]);
}